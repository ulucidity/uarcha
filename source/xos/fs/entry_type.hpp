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
///   File: entry_type.hpp
///
/// Author: $author$
///   Date: 8/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_TYPE_HPP
#define XOS_FS_ENTRY_TYPE_HPP

#include "xos/fs/time.hpp"
#include "xos/fs/path.hpp"

#define XOS_FS_ENTRY_TYPE_WHICH_NAME_NONE "none"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_FILE "file"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_DIRECTORY "directory"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_SYMBOLIC_LINK "symbolic-link"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_HARD_LINK "hard-link"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_BLOCK_DEVICE "block-device"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_CHAR_DEVICE "char-device"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_PIPE "pipe"
#define XOS_FS_ENTRY_TYPE_WHICH_NAME_SOCKET "socket"

namespace xos {
namespace fs {

typedef int64_t entry_ssize_t;
typedef uint64_t entry_size_t;

/// enum entry_type_which
typedef int entry_type_which;
enum {
    entry_type_none = 0,

    entry_type_file          = 1,
    entry_type_directory     = (entry_type_file << 1),
    entry_type_symbolic_link = (entry_type_directory << 1),
    entry_type_hard_link     = (entry_type_symbolic_link << 1),
    entry_type_block_device  = (entry_type_hard_link << 1),
    entry_type_char_device   = (entry_type_block_device << 1),
    entry_type_pipe          = (entry_type_char_device << 1),
    entry_type_socket        = (entry_type_pipe << 1),

    first_entry_type = entry_type_file,
    last_entry_type = entry_type_socket,
    next_entry_type = (last_entry_type << 1),

    entry_type_any = (next_entry_type - 1)
}; /// enum entry_type_which

/// class entry_typet
template <class TExtends = extend, class TImplements = implement>
class exported entry_typet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef entry_typet derives; 
    
    /// constructors / destructor
    entry_typet(const entry_typet& copy): which_(copy.which_) {
    }
    entry_typet(entry_type_which which): which_(which) {
    }
    entry_typet(): which_(entry_type_none) {
    }
    virtual ~entry_typet() {
    }

    /// clear
    virtual entry_typet& clear() {
        which_ = entry_type_none;
        return *this;
    }

    /// operator ...=
    virtual entry_typet& operator = (entry_type_which which) {
        which_ = which;
        return *this;
    }
    virtual entry_typet& operator |= (entry_type_which which) {
        which_ |= which;
        return *this;
    }
    virtual entry_typet& operator &= (entry_type_which which) {
        which_ &= which;
        return *this;
    }

    /// name
    virtual const char* name() const {
        return name(which_);
    }
    static const char* name(entry_type_which of) {
        switch (of) {
        case entry_type_file          : return XOS_FS_ENTRY_TYPE_WHICH_NAME_FILE;
        case entry_type_directory     : return XOS_FS_ENTRY_TYPE_WHICH_NAME_DIRECTORY;
        case entry_type_symbolic_link : return XOS_FS_ENTRY_TYPE_WHICH_NAME_SYMBOLIC_LINK;
        case entry_type_hard_link     : return XOS_FS_ENTRY_TYPE_WHICH_NAME_HARD_LINK;
        case entry_type_block_device  : return XOS_FS_ENTRY_TYPE_WHICH_NAME_BLOCK_DEVICE;
        case entry_type_char_device   : return XOS_FS_ENTRY_TYPE_WHICH_NAME_CHAR_DEVICE;
        case entry_type_pipe          : return XOS_FS_ENTRY_TYPE_WHICH_NAME_PIPE;
        case entry_type_socket        : return XOS_FS_ENTRY_TYPE_WHICH_NAME_SOCKET;
        }
        return XOS_FS_ENTRY_TYPE_WHICH_NAME_NONE;
    }
    virtual operator const char* () const {
        return name(which_);
    }

    /// which / of
    virtual entry_type_which which() const {
        return which_;
    }
    static entry_type_which of(const char* name) {
        return entry_type_none;
    }
    virtual operator entry_type_which() const {
        return which_;
    }

protected:
    entry_type_which which_;
}; /// class entry_typet
typedef entry_typet<> entry_type;

} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_ENTRY_TYPE_HPP
