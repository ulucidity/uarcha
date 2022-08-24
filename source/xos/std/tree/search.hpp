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
///   File: search.hpp
///
/// Author: $author$
///   Date: 8/20/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_SEARCH_HPP
#define XOS_STD_TREE_SEARCH_HPP

#include "xos/std/tree/find.hpp"

namespace xos {
namespace std {
namespace tree {

/// class searcht
template <class branch>
class searcht {
public:
    typedef typename branch::leaf_t leaf;
    searcht() {}
private:
    searcht(const searcht& copy) {
    }
public:
    virtual ~searcht() {}
    virtual void search(branch* b) {}
    virtual branch* found(branch* b) { return 0; }
    virtual leaf* found(leaf* l) { return 0; }
}; /// class searcht

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_SEARCH_HPP
