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
///   File: find.hpp
///
/// Author: $author$
///   Date: 8/20/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_FIND_HPP
#define XOS_STD_TREE_FIND_HPP

#include "xos/std/tree/branch.hpp"

namespace xos {
namespace std {
namespace tree {

/// class findt
template <class branch, class extends, class find>
class findt: public extends {
public:
    typedef typename branch::leaf_t leaf;
    findt(find& _find, branch& b): find_(_find) { 
        this->search(&b); 
    }
private:
    findt(const findt& copy) {
    }
public:
    virtual branch* found(branch* b) {
        return find_.found(b);
    }
    virtual leaf* found(leaf* l) {
        return find_.found(l);
    }
protected:
    find& find_;
}; /// class findt

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_FIND_HPP
