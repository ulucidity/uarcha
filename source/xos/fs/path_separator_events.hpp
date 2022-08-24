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
///   File: path_separator_events.hpp
///
/// Author: $author$
///   Date: 8/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_PATH_SEPARATOR_EVENTS_HPP
#define XOS_FS_PATH_SEPARATOR_EVENTS_HPP

#include "xos/fs/string.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace fs {

/// class path_separator_eventst
template <class TString = xos::fs::string, class TImplements = xos::logged>
class exported path_separator_eventst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef path_separator_eventst derives; 
    
    typedef TString string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    virtual ~path_separator_eventst() {
    }

    /// on...directory
    virtual void on_root_directory() {}
    virtual void on_current_directory() {}
    virtual void on_parent_directory() {}

    /// on...name
    virtual void on_host_name(const char_t* chars, size_t length) {}
    virtual void on_volume_name(const char_t* chars, size_t length) {}
    virtual void on_directory_name(const char_t* chars, size_t length) {}

    /// on_file...
    virtual void on_file_name(const char_t* chars, size_t length) {}
    virtual void on_file_base(const char_t* chars, size_t length) {}
    virtual void on_file_extension(const char_t* chars, size_t length) {}

}; /// class path_separator_eventst
typedef path_separator_eventst<> path_separator_events;

} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_PATH_SEPARATOR_EVENTS_HPP
