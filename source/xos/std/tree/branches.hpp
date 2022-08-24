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
///   File: branches.hpp
///
/// Author: $author$
///   Date: 8/19/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_BRANCHES_HPP
#define XOS_STD_TREE_BRANCHES_HPP

#include "xos/std/tree/reverse_range.hpp"

namespace xos {
namespace std {
namespace tree {

/// class branchest
template <class tbranch, class extends = ::std::list<tbranch*> >
class branchest: public extends {
public:
    typedef tbranch branch_t;
    typedef reverse_ranget<branchest> reverse_range;

    branchest() {}
    virtual ~branchest() {}
private:
    branchest(const branchest& copy) {
        throw exception(exception_unexpected);
    }
public:

    virtual tbranch* push_branch(tbranch* first) {
        if (first) { this->push_front(first); }
        return first;
    }
    virtual tbranch* pop_branch() {
        tbranch* first = 0;
        if (!(this->empty())) {
            first = this->front();
            this->pop_front();
        }
        return first;
    }
    virtual tbranch* first_branch() const {
        tbranch* first = 0;
        if (!(this->empty())) {
            first = this->front();
        }
        return first;
    }
    virtual tbranch* last_branch() const {
        tbranch* last = 0;
        if (!(this->empty())) {
            last = this->back();
        }
        return last;
    }
    virtual tbranch* queue_branch(tbranch* last) {
        if (last) { this->push_back(last); }
        return last;
    }
    virtual tbranch* pull_branch() {
        tbranch* last = 0;
        if (!(this->empty())) {
            last = this->back();
            this->pop_back();
        }
        return last;
    }

    virtual void delete_all() {
        for (auto b: *this) {
            if (b) {
                delete b;
                b = 0;
            }
        }
        this->clear();
    }

    static reverse_range reverse_iterate(branchest& branches) {
        return reverse_range(branches);
    }
}; /// class branchest

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_BRANCHES_HPP
