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
///   File: reverse_range.hpp
///
/// Author: $author$
///   Date: 8/19/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_REVERSE_RANGE_HPP
#define XOS_STD_TREE_REVERSE_RANGE_HPP

#include "xos/std/tree/leaf.hpp"

namespace xos {
namespace std {
namespace tree {

/// class reverse_ranget
template <class trange>
class reverse_ranget {
public:
    reverse_ranget(trange& range): range_(range) {}
    reverse_ranget(const reverse_ranget& copy): range_(copy.range_) {
    }
    typename trange::reverse_iterator begin() const {
        return range_.rbegin();
    }
    typename trange::reverse_iterator end() const {
        return range_.rend();
    }
protected:
    trange& range_;
}; /// class reverse_ranget

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_REVERSE_RANGE_HPP
