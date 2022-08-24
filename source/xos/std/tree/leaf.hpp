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
///   File: leaf.hpp
///
/// Author: $author$
///   Date: 8/19/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_LEAF_HPP
#define XOS_STD_TREE_LEAF_HPP

#include "xos/std/tree/leaves.hpp"

namespace xos {
namespace std {
namespace tree {

/// class leaft
template <class tbranch, class extends>
class leaft: public extends {
public:
    typedef tbranch branch_t;

    leaft(const leaft& copy): branch_(copy.branch_) {}
    leaft(tbranch* branch): branch_(branch) {}
    leaft(): branch_(0) {}
    virtual ~leaft() {}

    virtual tbranch* set_branch(tbranch* to) {
        branch_ = to;
        return branch_;
    }
    virtual tbranch* branch() const {
        return (tbranch*)branch_;
    }

protected:
    tbranch* branch_;
}; /// class leaft

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_LEAF_HPP
