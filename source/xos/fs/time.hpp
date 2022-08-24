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
///   File: time.hpp
///
/// Author: $author$
///   Date: 8/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_TIME_HPP
#define XOS_FS_TIME_HPP

#include "xos/fs/time_when.hpp"
#include "xos/base/date.hpp"

namespace xos {
namespace fs {

/// class timet
template <class TExtends = xos::date, class TImplements = typename TExtends::implements>
class exported timet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef timet derives; 
    
    /// constructors / destructor
    timet(const time_when& when): when_(when) {
    }
    timet(time_when_which which): when_(which) {
    }
    timet(const timet &copy): extends(copy) {
    }
    timet() {
    }
    virtual ~timet() {
    }

    /// clear
    virtual timet& clear() {
        extends::clear();
        when_.clear();
        return *this;
    }
    
    /// ...when...
    virtual time_when set_when(const time_when& to) {
        when_ = to;
        return when_;
    }
    virtual time_when set_when(time_when_which to) {
        when_ = to;
        return when_;
    }
    virtual time_when when() const {
        return when_;
    }
    virtual const char* when_name() const {
        return when_.name();
    }

    /// ...which...
    virtual time_when_which set_which(time_when_which to) {
        when_ = to;
        return when_.which();
    }
    virtual time_when_which which() const {
        return when_.which();
    }

protected:
    time_when when_;
}; /// class timet
typedef timet<> time;

} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_TIME_HPP
