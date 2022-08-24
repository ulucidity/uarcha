///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: path_separator.hpp
///
/// Author: $author$
///   Date: 8/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_PATH_SEPARATOR_HPP
#define XOS_FS_PATH_SEPARATOR_HPP

#include "xos/fs/path_separator_events.hpp"

namespace xos {
namespace fs {

/// class path_separatort
template 
<class TString = xos::fs::string, 
 class TEvents = xos::fs::path_separator_eventst<TString>, 
 class TExtends = xos::extended::loggedt<TEvents>, class TImplements = typename TExtends::implements>
class exported path_separatort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef path_separatort derives; 
    
    typedef TEvents events_t;
    typedef TString string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    path_separatort(const path_separatort& copy): events_(copy.events_), on_char_(0), on_end_(0) {
    }
    path_separatort(events_t& events): events_(events), on_char_(0), on_end_(0) {
    }
    path_separatort(): events_(this_events_), on_char_(0), on_end_(0) {
    }
    virtual ~path_separatort() {
    }

    /// separate
    virtual bool separate(const char_t* chars, size_t length) {
        if ((chars) && (length)) {
            name_.clear();
            extension_.clear();
            on_char_ = &derives::on_first_char;
            on_end_ = &derives::on_end_fail;
            for (; length; --length, ++chars) {
                if (!(on_char(*chars))) {
                    return false;
                }
            }
            return on_end();
        }
        return false;
    }

protected:
    /// on...char
    /// ...
    typedef bool (derives::*on_char_t)(char_t c);
    virtual bool on_char(char_t c) {
        if ((on_char_)) {
            return (this->*on_char_)(c);
        }
        return false;
    }
    virtual bool on_first_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// '/'
            on_char_ = &derives::on_host_char;
            on_end_ = &derives::on_end_root_directory;
            break;
        case ':':
            /// ':'
            return false;
        case '.':
            /// '.'
            on_char_ = &derives::on_current_char;
            on_end_ = &derives::on_end_current_directory;
            break;
        default:
            /// A
            name_.append(&c, 1);
            on_char_ = &derives::on_volume_char;
            on_end_ = &derives::on_end_file_name;
        }
        return true;
    }
    /// '/'
    virtual bool on_next_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// '/''/'
        case ':':
            /// '/'':'
            return false;
        case '.':
            /// '/''.'
            on_char_ = &derives::on_current_char;
            on_end_ = &derives::on_end_current_directory;
            break;
        default:
            /// '/'A
            name_.append(&c, 1);
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_file_name;
        }
        return true;
    }
    /// '/'
    virtual bool on_host_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// '/''/'
            on_char_ = &derives::on_host_name_char;
            on_end_ = &derives::on_end_fail;
            break;
        case ':':
            /// '/'':'
            return false;
            break;
        case '.':
            /// '/''.'
            events_.on_root_directory();
            on_char_ = &derives::on_current_char;
            on_end_ = &derives::on_end_current_directory;
            break;
        default:
            /// '/'A
            events_.on_root_directory();
            name_.append(&c, 1);
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_file_name;
        }
        return true;
    }
    /// '/''/'
    virtual bool on_host_name_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// '/''/'A*'/'
            if ((name_.length())) {
                events_.on_host_name(name_.c_str(), name_.length());
                name_.clear();
                events_.on_root_directory();
            } else {
                return false;
            }
            break;
        case ':':
            /// '/''/'A*':'
            return false;
            break;
        case '.':
            /// '/''/'A*'.'
            name_.append(&c, 1);
            on_char_ = &derives::on_host_name_char;
            on_end_ = &derives::on_end_host_name;
            break;
        default:
            /// '/''/'A*A
            name_.append(&c, 1);
            on_char_ = &derives::on_host_name_char;
            on_end_ = &derives::on_end_host_name;
        }
        return true;
    }
    /// '.'
    virtual bool on_current_char(char_t c) {
        static const char_t dot = (char_t)('.');
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// '.''/'
            events_.on_current_directory();
            on_char_ = &derives::on_next_char;
            on_end_ = &derives::on_end_fail;
            break;
        case ':':
            /// '.'':'
            return false;
            break;
        case '.':
            /// '.''.'
            on_char_ = &derives::on_parent_name_char;
            on_end_ = &derives::on_end_parent_directory;
            break;
        default:
            /// '.'A
            name_.append(&dot, 1);
            name_.append(&c, 1);
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_file_name;
        }
        return true;
    }
    /// '.'.'
    virtual bool on_parent_name_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// '.''.''/'
            events_.on_parent_directory();
            on_char_ = &derives::on_next_char;
            on_end_ = &derives::on_end_fail;
            break;
        case ':':
            /// '.''.'':'
            return false;
            break;
        case '.':
            /// '.''.''.'
            return false;
            break;
        default:
            /// '.''.'A
            return false;
        }
        return true;
    }
    /// A+
    virtual bool on_volume_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// A+'/'
            events_.on_directory_name(name_.c_str(), name_.length());
            name_.clear();
            on_char_ = &derives::on_next_char;
            on_end_ = &derives::on_end_fail;
            break;
        case ':':
            /// A+':'
            events_.on_volume_name(name_.c_str(), name_.length());
            name_.clear();
            on_char_ = &derives::on_root_name_char;
            on_end_ = &derives::on_end_success;
            break;
        case '.':
            /// A+'.'
            on_char_ = &derives::on_extension_char;
            on_end_ = &derives::on_end_file_extension;
            break;
        default:
            /// A+A
            name_.append(&c, 1);
            on_char_ = &derives::on_volume_char;
            on_end_ = &derives::on_end_file_name;
        }
        return true;
    }
    /// A+':'
    virtual bool on_root_name_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// A+':''/'
            events_.on_root_directory();
            on_char_ = &derives::on_next_char;
            on_end_ = &derives::on_end_success;
            break;
        case ':':
            /// A+':'':'
            return false;
            break;
        case '.':
            /// A+':''.'
            on_char_ = &derives::on_current_char;
            on_end_ = &derives::on_end_current_directory;
            break;
        default:
            /// A+':'A
            name_.append(&c, 1);
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_file_name;
        }
        return true;
    }
    /// A+
    virtual bool on_name_char(char_t c) {
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// A+'/'
            events_.on_directory_name(name_.c_str(), name_.length());
            name_.clear();
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_fail;
            break;
        case ':':
            /// A+':'
            return false;
            break;
        case '.':
            /// A+'.'
            on_char_ = &derives::on_extension_char;
            on_end_ = &derives::on_end_file_name;
            break;
        default:
            /// A+A
            name_.append(&c, 1);
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_file_name;
        }
        return true;
    }
    /// A+'.'
    virtual bool on_extension_char(char_t c) {
        static const char_t dot = (char_t)('.');
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// A+'.''/'
            name_.append(&dot, 1);
            events_.on_directory_name(name_.c_str(), name_.length());
            name_.clear();
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_fail;
            break;
        case ':':
            /// A+'.'':'
            return false;
            break;
        case '.':
            /// A+'.''.'
            return false;
            break;
        default:
            /// A+'.'A
            extension_.append(&c, 1);
            on_char_ = &derives::on_extension_name_char;
            on_end_ = &derives::on_end_file_extension;
        }
        return true;
    }
    /// A+'.'A+
    virtual bool on_extension_name_char(char_t c) {
        static const char_t dot = (char_t)('.');
        const char cc = (char)(c);
        switch (cc) {
        case '/':
        case '\\':
            /// A+'.'A+'/'
            name_.append(&dot, 1);
            name_.append(extension_);
            events_.on_directory_name(name_.c_str(), name_.length());
            name_.clear();
            extension_.clear();
            on_char_ = &derives::on_name_char;
            on_end_ = &derives::on_end_fail;
            break;
        case ':':
            /// A+'.'A+':'
            return false;
            break;
        case '.':
            /// A+'.'A+'.'
            name_.append(&dot, 1);
            name_.append(extension_);
            extension_.clear();
            on_char_ = &derives::on_extension_char;
            on_end_ = &derives::on_end_file_extension;
            break;
        default:
            /// A+'.'A+A
            extension_.append(&c, 1);
            on_char_ = &derives::on_extension_name_char;
            on_end_ = &derives::on_end_file_extension;
        }
        return true;
    }
    /// ...
    /// on...char

    /// on_end...
    /// ...
    typedef bool (derives::*on_end_t)();
    virtual bool on_end() {
        if ((on_end_)) {
            return (this->*on_end_)();
        }
        return false;
    }
    virtual bool on_end_success() {
        return true;
    }
    virtual bool on_end_fail() {
        return false;
    }
    virtual bool on_end_host_name() {
        return true;
    }
    virtual bool on_end_file_name() {
        events_.on_file_name(name_.c_str(), name_.length());
        return true;
    }
    virtual bool on_end_file_extension() {
        events_.on_file_base(name_.c_str(), name_.length());
        events_.on_file_extension(extension_.c_str(), extension_.length());
        return true;
    }
    virtual bool on_end_root_directory() {
        events_.on_root_directory();
        return true;
    }
    virtual bool on_end_current_directory() {
        events_.on_current_directory();
        return true;
    }
    virtual bool on_end_parent_directory() {
        events_.on_parent_directory();
        return true;
    }
    /// ... 
    /// on_end...

protected:
    events_t this_events_, &events_;
    on_char_t on_char_;
    on_end_t on_end_;
    string_t name_, extension_;
}; /// class path_separatort
typedef path_separatort<> path_separator;

} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_PATH_SEPARATOR_HPP
