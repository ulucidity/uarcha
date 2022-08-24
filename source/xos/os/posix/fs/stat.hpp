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
///   File: stat.hpp
///
/// Author: $author$
///   Date: 8/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_OS_POSIX_FS_STAT_HPP
#define XOS_OS_POSIX_FS_STAT_HPP

#include "xos/fs/directory/entry.hpp"
#include <sys/stat.h>
#include <utime.h>

#define S_IRWX (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)
#define S_IRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define S_IR (S_IRUSR | S_IRGRP | S_IROTH)

namespace xos {
namespace os {
namespace posix {
namespace fs {

typedef xos::fs::time time;
typedef xos::fs::time_when time_when;
enum {
    time_when_none     = xos::fs::time_when_none,
    time_when_modified = xos::fs::time_when_modified,
    time_when_accessed = xos::fs::time_when_accessed,
    time_when_changed  = xos::fs::time_when_changed,
    time_when_created  = xos::fs::time_when_created
};
typedef xos::fs::entry_type entry_type;
enum {
    entry_type_none          = xos::fs::entry_type_none,
    entry_type_file          = xos::fs::entry_type_file,
    entry_type_directory     = xos::fs::entry_type_directory,
    entry_type_symbolic_link = xos::fs::entry_type_symbolic_link,
    entry_type_hard_link     = xos::fs::entry_type_hard_link,
    entry_type_block_device  = xos::fs::entry_type_block_device,
    entry_type_char_device   = xos::fs::entry_type_char_device,
    entry_type_pipe          = xos::fs::entry_type_pipe,
    entry_type_socket        = xos::fs::entry_type_socket,
};
typedef xos::fs::entry_size_t entry_size_t;
typedef xos::fs::entry_ssize_t entry_ssize_t;

/// class statt
template <class TExtends = extend, class TImplements = implement>
class exported statt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef statt derives; 
    
    typedef struct stat struct_stat_t;

    /// constructors / destructor
    statt(const statt &copy) {
        ::memcpy(&struct_stat_, &copy.stat(), sizeof(struct_stat_));
    }
    statt() {
        ::memset(&struct_stat_, 0, sizeof(struct_stat_));
    }
    virtual ~statt() {
    }

    /// ...
    virtual struct_stat_t& struct_stat() const { 
        return (struct_stat_t&)struct_stat_; 
    }
    virtual struct_stat_t* operator & () const { 
        return (struct_stat_t*)&struct_stat_; 
    }
    virtual operator struct_stat_t&() const { 
        return (struct_stat_t&)struct_stat_; 
    }

protected:
    struct_stat_t struct_stat_;
}; /// class statt
typedef statt<> stat_t;

} /// namespace fs
} /// namespace posix
} /// namespace os
} /// namespace xos

#endif /// ndef XOS_OS_POSIX_FS_STAT_HPP
