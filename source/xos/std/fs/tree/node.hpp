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
///   Date: 8/23/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_FS_TREE_NODE_HPP
#define XOS_STD_FS_TREE_NODE_HPP

#include "xos/os/fs/directory/entry.hpp"
#include "xos/std/tree/search.hpp"

namespace xos {
namespace std {
namespace fs {
namespace tree {

class node;
class leaf;
class branch;

typedef xos::os::fs::directory::entry nodeExtends;
/// class node
class exported node: public nodeExtends {
public:
    typedef nodeExtends extends;
    typedef node derives; 
    
    typedef typename extends::wchar_string_t wchar_string_t;
    typedef typename extends::char_string_t char_string_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    node(const string_t& path, const string_t& name, xos::fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    node(const string_t& path, const xos::fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    node(const char* path, const char* name, xos::fs::entry_type type) {
        construct(path, name, type);
    }
    node(const char* path, const xos::fs::directory::entry& entry) {
        construct(path, entry);
    }
    node(const xos::fs::directory::entry& entry) {
        construct(entry);
    }
    node(const node& copy) {
        construct(copy);
    }
    node() {
        construct();
    }
    virtual ~node() {
        destruct();
    }

    /// set
    using extends::set;
    node& set(const char* path, const char* name, xos::fs::entry_type type) {
        this->set_path_name(path, name);
        this->set_path(path);
        this->set_name(name);
        this->set_type(type);
        return *this;
    }
    node& set(const char* path) {
        this->set_path_name(path);
        return *this;
    }

protected:
    /// construct / destruct
    void construct(const char* path, const char* name, xos::fs::entry_type type) {
        construct();
        this->set_path_name(path, name);
        this->set_path(path);
        this->set_name(name);
        this->set_type(type);
    }
    void construct(const char* path, const xos::fs::directory::entry& entry) {
        construct(entry);
        this->set_path_name(path);
    }
    void construct(const xos::fs::directory::entry& entry) {
        construct();
        this->set(entry);
    }
    void construct() {
    }
    void destruct() {
    }

}; /// class node

} /// namespace tree
} /// namespace fs
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_FS_TREE_NODE_HPP
