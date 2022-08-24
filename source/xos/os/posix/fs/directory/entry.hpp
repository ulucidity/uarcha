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
///   Date: 8/23/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_OS_POSIX_FS_DIRECTORY_ENTRY_HPP
#define XOS_OS_POSIX_FS_DIRECTORY_ENTRY_HPP

#include "xos/os/posix/fs/directory/dirent.hpp"

namespace xos {
namespace os {
namespace posix {
namespace fs {
namespace directory {

/// class entryt
template 
<class TExtends = xos::os::posix::fs::entryt
 <xos::fs::directory::entry>, class TImplements = typename TExtends::implements>
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
    entryt(const entryt& copy): extends(copy) {
    }
    entryt() {
    }
    virtual ~entryt() {
    }

    /// assign
    virtual entryt& assign(const char* path, const struct dirent* dirent) {
        if ((path) && (dirent)) {
            this->set_dirent(dirent);
            this->set_found(path, *dirent);
        }
        return *this;
    }

    /// ...found...
    virtual entry_type set_found(const char* path, const struct dirent& dirent) {
        entry_type type = set_found_type(dirent);
#if defined(APPLEOSX)
        this->set_name(dirent.d_name, dirent.d_namlen);
#else /// defined(APPLEOSX)
        this->set_name(dirent.d_name);
#endif /// defined(APPLEOSX)
        return this->get_found(path);
    }
    virtual entry_type set_found_type(const struct dirent& dirent) {
        this->set_type(entry_type_none);
        switch (dirent.d_type) {
        case DT_REG:
            this->set_type(entry_type_file);
            break;
        case DT_DIR:
            this->set_type(entry_type_directory);
            break;
        case DT_LNK:
            this->set_type(entry_type_symbolic_link);
            break;
        case DT_BLK:
            this->set_type(entry_type_block_device);
            break;
        case DT_CHR:
            this->set_type(entry_type_char_device);
            break;
        case DT_FIFO:
            this->set_type(entry_type_pipe);
            break;
        case DT_SOCK:
            this->set_type(entry_type_socket);
            break;
        }
        return this->type();
    }

    /// ...dirent
    virtual const struct dirent* set_dirent(const struct dirent* dirent) {
        dirent_ = dirent;
        return dirent_;
    }
    virtual const struct dirent* dirent() const {
        return dirent_;
    }

protected:
    dirent_t dirent_;
}; /// class entryt
typedef entryt<> entry;

} /// namespace directory
} /// namespace fs
} /// namespace posix
} /// namespace os
} /// namespace xos

#endif /// ndef XOS_OS_POSIX_FS_DIRECTORY_ENTRY_HPP
