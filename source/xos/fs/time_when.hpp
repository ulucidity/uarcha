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
///   File: time_when.hpp
///
/// Author: $author$
///   Date: 8/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_TIME_WHEN_HPP
#define XOS_FS_TIME_WHEN_HPP

#include "xos/base/chars.hpp"

#define XOS_FS_TIME_WHICH_NAME_NONE "none"
#define XOS_FS_TIME_WHICH_NAME_MODIFIED "modified"
#define XOS_FS_TIME_WHICH_NAME_ACCESSED "accessed"
#define XOS_FS_TIME_WHICH_NAME_CHANGED "changed"
#define XOS_FS_TIME_WHICH_NAME_CREATED "created"

namespace xos {
namespace fs {

/// enum time_when_which
typedef int time_when_which;
enum {
    time_when_none     = 0,

    time_when_modified = 1,
    time_when_accessed = (time_when_modified << 1),
    time_when_changed  = (time_when_accessed << 1),
    time_when_created  = (time_when_changed << 1),

    first_time_when = time_when_modified,
    last_time_when = time_when_created,
    next_time_when = (last_time_when << 1),

    time_when_any = (next_time_when - 1)
};/// enum time_when_which

/// class time_whent
template <class TExtends = extend, class TImplements = typename TExtends::implements>
class exported time_whent: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef time_whent derives; 
    
    /// constructors / destructor
    time_whent(time_when_which which): which_(which) {
    }
    time_whent(const time_whent& copy): which_(copy.which()) {
    }
    time_whent(): which_(time_when_none) {
    }
    virtual ~time_whent() {
    }

    /// clear
    virtual time_whent& clear() {
        which_ = time_when_none;
        return *this;
    }

    /// ...=
    virtual time_whent& operator = (time_when_which which) {
        which_ = which;
        return *this;
    }
    virtual time_whent& operator |= (time_when_which which) {
        which_ |= which;
        return *this;
    }
    virtual time_whent& operator &= (time_when_which which) {
        which_ &= which;
        return *this;
    }

    /// name
    virtual const char* name() const {
        return name(which_);
    }
    static const char* name(time_when_which of) {
        switch (of) {
        case time_when_modified: return XOS_FS_TIME_WHICH_NAME_MODIFIED;
        case time_when_accessed: return XOS_FS_TIME_WHICH_NAME_ACCESSED;
        case time_when_changed: return XOS_FS_TIME_WHICH_NAME_CHANGED;
        case time_when_created: return XOS_FS_TIME_WHICH_NAME_CREATED;
        }
        return XOS_FS_TIME_WHICH_NAME_NONE;
    }

    /// ...which
    virtual time_when_which has_which(time_when_which which) const {
        if (which == (which & which_)) {
            return which;
        }
        return time_when_none;
    }
    virtual time_when_which which() const {
        return which_;
    }
    virtual operator time_when_which() const {
        return which_;
    }
    static time_when_which of(const char* name) {
        if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_MODIFIED))) {
            if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_ACCESSED))) {
                if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_CHANGED))) {
                    if ((chars_t::compare_uncased(name, XOS_FS_TIME_WHICH_NAME_CREATED))) {
                        return time_when_none;
                    } else {
                        return time_when_created;
                    }
                } else {
                    return time_when_changed;
                }
            } else {
                return time_when_accessed;
            }
        } else {
            return time_when_modified;
        }
        return time_when_none;
    }
    
    /// next / prev
    static time_when_which next(time_when_which to) {
        return to << 1;
    }
    static time_when_which prev(time_when_which to) {
        return to >> 1;
    }

protected:
    time_when_which which_;
}; /// class time_whent
typedef time_whent<> time_when;

} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_TIME_WHEN_HPP
