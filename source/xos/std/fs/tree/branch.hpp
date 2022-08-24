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
///   Date: 8/23/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_STD_FS_TREE_BRANCH_HPP
#define XOS_STD_FS_TREE_BRANCH_HPP

#include "xos/std/fs/tree/leaf.hpp"
#include "xos/os/fs/directory/entry.hpp"
#include "xos/os/fs/directory/path.hpp"

namespace xos {
namespace std {
namespace fs {
namespace tree {

typedef xos::std::tree::leavest<leaf> leaves;
typedef xos::std::tree::branchest<branch> branches;
typedef xos::std::tree::brancht<branch, branches, leaves, node> branchExtends;
/// class branch
class exported branch: public branchExtends {
public:
    typedef branchExtends extends;
    typedef branch derives; 
    
    typedef typename extends::wchar_string_t wchar_string_t;
    typedef typename extends::char_string_t char_string_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    branch(const string_t& path, const string_t& name, xos::fs::entry_type type) {
        construct(path.chars(), name.chars(), type);
    }
    branch(const string_t& path, const xos::fs::directory::entry& entry) {
        construct(path.chars(), entry);
    }
    branch(const string_t& path) {
        construct(path.chars());
    }
    branch(const char* path, const char* name, xos::fs::entry_type type) {
        construct(path, name, type);
    }
    branch(const char* path, const xos::fs::directory::entry& entry) {
        construct(path, entry);
    }
    branch(const char* path) {
        construct(path);
    }
    branch(const xos::fs::directory::entry& entry) {
        construct(entry);
    }
    branch(const branch& copy) {
        construct(copy);
    }
    branch() {
        construct();
    }
    virtual ~branch() {
        destruct();
    }

    /// construct / destruct
    void construct(const char* path, const char* name, xos::fs::entry_type type) {
        construct();
        this->set(path, name, type);
    }
    void construct(const char* path, const xos::fs::directory::entry& entry) {
        construct(entry);
        this->set(path);
    }
    void construct(const char* path) {
        construct();
        this->set(path);
        this->set_is_directory();
    }
    void construct(const xos::fs::directory::entry& entry) {
        construct();
        this->set(entry);
    }
    void construct() {
        got_branches_=(false);
    }
    void destruct() {
    }

    /// leaves / branches
    virtual xos::std::fs::tree::leaves& leaves() const {
        get_branches();
        return extends::leaves();
    }
    virtual xos::std::fs::tree::branches& branches() const {
        get_branches();
        return extends::branches();
    }

    /// branches
    virtual xos::std::fs::tree::branches& get_branches() const {
        xos::std::fs::tree::branches& branches = extends::branches();
        xos::std::fs::tree::leaves& leaves = extends::leaves();
        bool& got_branches = this->got_branches();

        if (!(got_branches)) {
            const char_t* chars = 0;
            size_t length = 0;

            got_branches=(true);
            if ((xos::fs::entry_type_directory == (this->type())) && (!this->is_circular())) {
                const char_t* directory_separator_chars = 0;
                string_t name(this->path_name());

                if ((chars = name.has_chars(length))) {
                    xos::os::fs::directory::path path;

                    if ((chars = this->has_name(length))) {
                        if ((directory_separator_chars = this->directory_separator_chars()) 
                             && (chars[length-1] != directory_separator_chars[0])) {
                            name.append(directory_separator_chars);
                        }
                        name.append(chars, length);
                    }
                    LOGGER_IS_LOGGED_DEBUG("path.open(name = \"" << name << "\")...");
                    if ((path.open(name))) {
                        xos::os::fs::directory::entry* entry = 0;
    
                        if ((entry = path.get_first_entry())) {
                            branch* b = 0;
                            leaf* l = 0;
                            do {
                                if ((xos::fs::entry_type_directory == (entry->type())) && (!entry->is_circular())) {
                                    LOGGER_IS_LOGGED_DEBUG("new branch(name = \"" << name << "\", *entry)...")
                                    if ((b = new branch(name, *entry))) {
                                        branches.push_back(b);
                                    } else {
                                        LOGGER_IS_LOGGED_ERROR("...failed on new branch(name = \"" << name << "\", *entry)");
                                        break;
                                    }
                                } else {
                                    if (xos::fs::entry_type_directory != (entry->type())) {
                                        LOGGER_IS_LOGGED_DEBUG("new leaf(name = \"" << name << "\", *entry)...")
                                        if ((l = new leaf(name, *entry))) {
                                            leaves.push_back(l);
                                        } else {
                                            LOGGER_IS_LOGGED_ERROR("...failed on new leaf(name = \"" << name << "\", *entry)");
                                            break;
                                        }
                                    }
                                }
                                entry = path.get_next_entry();
                            } while ((entry));
                        }
                        path.close();
                    } else {
                        LOGGER_IS_LOGGED_ERROR("...failed on path.open(name = \"" << name << "\")");
                    }
                }
            }
        }
        return branches;
    }
    virtual bool& got_branches() const {
        return (bool&)got_branches_;
    }

protected:
    bool got_branches_;
}; /// class branch

} /// namespace tree
} /// namespace fs
} /// namespace std
} /// namespace xos

#endif /// ndef XOS_STD_FS_TREE_BRANCH_HPP
