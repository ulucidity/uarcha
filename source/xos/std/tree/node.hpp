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
///   File: node.hpp
///
/// Author: $author$
///   Date: 8/20/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_TREE_NODE_HPP
#define XOS_STD_TREE_NODE_HPP

#include "xos/std/tree/nodes.hpp"

namespace xos {
namespace std {
namespace tree {

/// class nodet
template <class tbranch, class tleaf, class tnode, class tstream, class extends>
class nodet: public extends {
public:
    typedef tbranch branch_t;
    typedef tleaf leaf_t;

    nodet(): depth_(0) {}
    virtual ~nodet() {}
private:
    nodet(const nodet& copy) {
    }
public:

    virtual ssize_t write(tstream& to) const {
        return 0;
    }
    virtual ssize_t read(tstream& from) {
        return 0;
    }
    virtual operator tbranch* () const {
        return 0;
    }
    virtual operator tleaf* () const {
        return 0;
    }

    virtual size_t set_depth(size_t to) {
        depth_ = to;
        return depth_;
    }
    virtual size_t depth() const {
        return depth_;
    }

protected:
    size_t depth_;
}; /// class nodet

} /// namespace tree
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_TREE_NODE_HPP
