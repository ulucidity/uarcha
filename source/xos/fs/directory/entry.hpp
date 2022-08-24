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
///   File: entry.hpp
///
/// Author: $author$
///   Date: 8/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_DIRECTORY_ENTRY_HPP
#define XOS_FS_DIRECTORY_ENTRY_HPP

#include "xos/fs/entry.hpp"

namespace xos {
namespace fs {
namespace directory {

/// class entryt
template 
<class TExtends = xos::fs::entry, class TImplements = typename TExtends::implements>
class exported entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef entryt derives; 
    
    typedef typename TExtends::wchar_string_t wchar_string_t;
    typedef typename TExtends::char_string_t char_string_t;
    typedef typename TExtends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    entryt(const entryt &copy) {
        construct(copy);
    }
    entryt() {
        construct();
    }
    virtual ~entryt() {
        destruct();
    }

    /// ...path_name...
    template <typename tchar_t>
    const char_t* set_path_namet(const tchar_t* path, const tchar_t* name) {
        path_name_.clear();
        if ((path) && (path[0])) {
            path_name_.append(path);
            if ((name) && (name[0])) {
                path_name_.append(directory_separator_chars());
            }
        }
        if ((name) && (name[0])) {
            path_name_.append(name);
        }
        return path_name();
    }
    virtual const char_t* set_path_name(const char* path, const char* name) {
        return set_path_namet<char>(path, name);
    }
    virtual const char_t* set_path_name(const char* to, size_t length) {
        path_name_.assign(to, length);
        return path_name();
    }
    virtual const char_t* set_path_name(const char* to) {
        path_name_.assign(to);
        return path_name();
    }
    virtual const char_t* set_path_name(const wchar_t* path, const wchar_t* name) {
        return set_path_namet<wchar_t>(path, name);
    }
    virtual const char_t* set_path_name(const wchar_t* to, size_t length) {
        path_name_.assign(to, length);
        return path_name();
    }
    virtual const char_t* set_path_name(const wchar_t* to) {
        path_name_.assign(to);
        return path_name();
    }
    virtual const char_t* has_path_name(size_t& length) const {
        return path_name_.has_chars(length);
    }
    virtual const char_t* has_path_name() const {
        return path_name_.has_chars();
    }
    virtual const char_t* path_name(size_t& length) const {
        return path_name_.chars(length);
    }
    virtual const char_t* path_name() const {
        return path_name_.chars();
    }

    /// ...is...
    virtual bool is_normal_directory() const {
        if ((this->is_directory()) && (!is_circular())) {
            return true;
        }
        return false;
    }
    virtual bool is_circular_directory() const {
        if ((this->is_directory()) && (is_circular())) {
            return true;
        }
        return false;
    }
    virtual bool is_circular() const {
        return (is_current_ || is_parent_);
    }
    virtual bool set_is_current(bool to = true) {
        is_parent_ = (false);
        is_current_ = to;
        return is_current_;
    }
    virtual bool is_current() const {
        return is_current_;
    }
    virtual bool set_is_parent(bool to = true) {
        is_current_ = (false);
        is_parent_ = to;
        return is_parent_;
    }
    virtual bool is_parent() const {
        return is_parent_;
    }

    /// ...chars
    virtual const char* current_name_chars() const {
        return ".";
    }
    virtual const char* parent_name_chars() const {
        return "..";
    }
    virtual const char* volume_separator_chars() const {
        return ":";
    }
    virtual const char* volume_directory_separator_chars() const {
        return "\\";
    }
    virtual const char* directory_separator_chars() const {
        return "/";
    }

    /// set / clear
    virtual entryt& set(const entryt &copy) {
        extends::set(copy);
        is_current_=(copy.is_current()), is_parent_=(copy.is_parent());
        path_name_.assign(copy.path_name());
        return *this;
    }
    virtual entryt& clear() {
        extends::clear();
        is_current_=(false), is_parent_=(false);
        path_name_.clear();
        return *this;
    }

protected:
    /// on_set...
    virtual void on_set_path_name() {
    }
    virtual void on_set_name() {
        set_is_current(false);
        set_is_parent(false);
        if (!(this->name_.compare(current_name_chars()))) {
            set_is_current();
        } else {
            if (!(this->name_.compare(parent_name_chars()))) {
                set_is_parent();
            } else {
            }
        }
    }

private:
    /// construct / destruct
    void construct(const entryt &copy) {
        construct();
        this->set(copy);
    }
    void construct() {
        is_current_=(false); 
        is_parent_=(false);
    }
    void destruct() {
        path_name_.clear();
    }

protected:
    bool is_current_, is_parent_;
    string_t path_name_;
}; /// class entryt
typedef entryt<> entry;

} /// namespace directory
} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_DIRECTORY_ENTRY_HPP
