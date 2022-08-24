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
///   File: bottom_first_search.hpp
///
/// Author: $author$
///   Date: 8/20/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_BOTTOM_FIRST_SEARCH_HPP
#define XOS_STD_TREE_BOTTOM_FIRST_SEARCH_HPP

#include "xos/std/tree/search.hpp"

namespace xos {
namespace std {
namespace tree {

/// class bottom_first_searcht
template <class branch, class branches, class leaves, class extends = searcht<branch> >
class bottom_first_searcht: public brancht<branch, branches, leaves, extends> {
public:
    bottom_first_searcht() {}
    bottom_first_searcht(branch* v) { this->search(v); }
    virtual ~bottom_first_searcht() {}
private:
    bottom_first_searcht(const bottom_first_searcht& copy) {
        throw exception(exception_unexpected);
    }
public:
    virtual void search(branch* v) {
        if (v) {
            stack_.push_branch(v);
            do {
                for (auto b: v->branches()) {
                    this->push_branch(b);
                }
                for (auto b: branches::reverse_iterate(v->branches())) {
                    stack_.push_branch(b);
                }
            } while ((v = this->pop_branch()));
            while ((v = stack_.pop_branch())) {
                if (this->found(v)) { break; }
            }
        }
    }
protected:
    branches stack_;
}; /// class bottom_first_searcht

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_BOTTOM_FIRST_SEARCH_HPP
