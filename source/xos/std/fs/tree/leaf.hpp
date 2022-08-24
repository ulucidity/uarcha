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
///   Date: 8/23/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_FS_TREE_LEAF_HPP
#define XOS_STD_FS_TREE_LEAF_HPP

#include "xos/std/fs/tree/node.hpp"

namespace xos {
namespace std {
namespace fs {
namespace tree {

typedef xos::std::tree::leaft<branch, node> leafExtends;
/// class leaf
class exported leaf: public leafExtends {
public:
    typedef leafExtends extends;
    typedef leaf derives; 
    
    typedef typename extends::wchar_string_t wchar_string_t;
    typedef typename extends::char_string_t char_string_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    leaf(const string_t& path, const string_t& name, xos::fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    leaf(const string_t& path, const xos::fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    leaf(const char* path, const char* name, xos::fs::entry_type type) {
        construct(path, name, type);
    }
    leaf(const char* path, const xos::fs::directory::entry& entry) {
        construct(path, entry);
    }
    leaf(const xos::fs::directory::entry& entry) {
        construct(entry);
    }
    leaf(const leaf& copy) {
        construct(copy);
    }
    leaf() {
        construct();
    }
    virtual ~leaf() {
        destruct();
    }

protected:
    /// constructors / destructor
    void construct(const char* path, const char* name, xos::fs::entry_type type) {
        construct();
        this->set(path, name, type);
    }
    void construct(const char* path, const xos::fs::directory::entry& entry) {
        construct(entry);
        this->set(path);
    }
    void construct(const xos::fs::directory::entry& entry) {
        extends::construct(entry);
        construct();
    }
    void construct() {
    }
    void destruct() {
    }

}; /// class leaf

} /// namespace tree
} /// namespace fs
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_FS_TREE_LEAF_HPP
