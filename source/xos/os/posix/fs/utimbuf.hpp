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
///   File: utimbuf.hpp
///
/// Author: $author$
///   Date: 8/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_OS_POSIX_FS_UTIMBUF_HPP
#define XOS_OS_POSIX_FS_UTIMBUF_HPP

#include "xos/os/posix/fs/stat.hpp"

namespace xos {
namespace os {
namespace posix {
namespace fs {

/// class utimbuft
template <class TExtends = extend, class TImplements = implement>
class exported utimbuft: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef utimbuft derives; 
    
    typedef struct utimbuf struct_utimbuf_t;

    /// constructors / destructor
    utimbuft(const utimbuft &copy) {
        ::memcpy(&struct_utimbuf_, &copy.utimbuf(), sizeof(struct_utimbuf_));
    }
    utimbuft() {
        ::memset(&struct_utimbuf_, 0, sizeof(struct_utimbuf_));
    }
    virtual ~utimbuft() {
    }

    /// ...
    virtual struct_utimbuf_t& utimbuf() const { 
        return (struct_utimbuf_t&)struct_utimbuf_; 
    }
    virtual struct_utimbuf_t* operator & () const { 
        return (struct_utimbuf_t*)&struct_utimbuf_; 
    }
    virtual operator struct_utimbuf_t&() const { 
        return (struct_utimbuf_t&)struct_utimbuf_; 
    }

protected:
    struct_utimbuf_t struct_utimbuf_;
}; /// class utimbuft
typedef utimbuft<> utimbuf_t;

} /// namespace fs
} /// namespace posix
} /// namespace os
} /// namespace xos

#endif /// ndef XOS_OS_POSIX_FS_UTIMBUF_HPP
