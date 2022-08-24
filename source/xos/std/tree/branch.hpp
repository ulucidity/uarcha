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
///   File: branch.hpp
///
/// Author: $author$
///   Date: 8/20/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_BRANCH_HPP
#define XOS_STD_TREE_BRANCH_HPP

#include "xos/std/tree/branches.hpp"

namespace xos {
namespace std {
namespace tree {

/// class brancht
template <class tbranch, class tbranches, class tleaves, class extends>
class brancht: public extends {
public:
    typedef typename tleaves::leaf_t tleaf;
    typedef tbranch branch_t;
    typedef tleaves leaves_t;
    typedef typename leaves_t::leaf_t leaf_t;

    brancht(tbranch* branch): branch_(branch) {}
    brancht(): branch_(0) {}
    virtual ~brancht() {}
private:
    brancht(const brancht& copy) {
        throw exception(exception_unexpected);
    }
public:

    virtual tbranch* push_branch(tbranch* first) {
        return branches_.push_branch(first);
    }
    virtual tbranch* pop_branch() {
        return branches_.pop_branch();
    }
    virtual tbranch* queue_branch(tbranch* last) {
        return branches_.queue_branch(last);
    }
    virtual tbranch* pull_branch() {
        return branches_.pull_branch();
    }
    virtual tbranch* first_branch() const {
        return branches_.first_branch();
    }
    virtual tbranch* last_branch() const {
        return branches_.last_branch();
    }
    virtual tbranch* set_branch(tbranch* to) {
        branch_ = to;
        return branch_;
    }
    virtual tbranch* branch() const {
        return (tbranch*)branch_;
    }
    virtual tbranches& branches() const {
        return (tbranches&)branches_;
    }

    virtual tleaf* push_leaf(tleaf* first) {
        return leaves_.push_leaf(first);
    }
    virtual tleaf* pop_leaf() {
        return leaves_.pop_leaf();
    }
    virtual tleaf* queue_leaf(tleaf* last) {
        return leaves_.queue_leaf(last);
    }
    virtual tleaf* pull_leaf() {
        return leaves_.pull_leaf();
    }
    virtual tleaves& leaves() const {
        return (tleaves&)leaves_;
    }

protected:
    tbranch* branch_;
    tbranches branches_;
    tleaves leaves_;
}; /// class brancht

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_BRANCH_HPP
