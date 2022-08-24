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
///   File: main.hpp
///
/// Author: $author$
///   Date: 8/19/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_UARCHA_MAIN_HPP
#define XOS_APP_CONSOLE_UARCHA_MAIN_HPP

#include "xos/app/console/uarcha/main_opt.hpp"
#include "xos/std/tree/searches.hpp"
#include "xos/std/fs/tree/branch.hpp"
#include "xos/os/fs/entry.hpp"
#include "xos/os/fs/directory/path.hpp"

namespace xos {
namespace app {
namespace console {
namespace uarcha {

/// class maint
template 
<class TExtends = xos::app::console::uarcha::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

public:
    typedef xos::std::fs::tree::leaves leaves;
    typedef xos::std::fs::tree::branches branches;
    typedef xos::std::fs::tree::leaf leaf;
    typedef xos::std::fs::tree::branch branch;
    typedef xos::fs::directory::entry entry;
    
    virtual leaf* found(leaf* l) {
        entry* e = l;
        found(e);
        return 0;
    }
    virtual branch* found(branch* b) {
        entry* e = b;
        found(e);
        for (auto l: b->leaves()) {
            found(l);
        }
        return 0;
    }
    virtual entry* found(entry* e) {
        typedef entry::char_t char_t;
        if (e) {
            size_t path_length = 0;
            const char_t *path_chars = e->path_name(path_length),
                         *separator_chars = e->directory_separator_chars(),
                         *name_chars = e->name();
            if ((name_chars) && (name_chars[0])) {
                string_t path(path_chars);
                if ((separator_chars) && (path_chars) && (path_length) 
                    && (path_chars[path_length-1] != separator_chars[0])) {
                    path.append(separator_chars);
                }
                path.append(name_chars);
                if ((path_chars = path.has_chars(path_length))) {
                    this->outln(path_chars, path_length);
                }
            }
        }
        return 0;
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            if ((argc > (optind))) {
                err = arg_run(argc, argv, env);
            } else {
                err = extends::run(argc, argv, env);
            }
        }
        return err;
    }
    virtual int arg_run(int argc, char_t** argv, char_t** env) {
        int err = 0, optind = 0;
        char_t* arg = 0;

        if ((argc > (optind = ::optind)) && (arg = argv[optind]) && (arg[0])) {
            xos::fs::path path(arg);
            xos::fs::entry_type entry_type = xos::fs::entry_type_none;
            xos::os::fs::entry entry;
            
            this->outl("entry \"", path.chars(), "\" ", null);
            if ((xos::fs::entry_type_none != (entry_type = entry.exists(path)))) {
                this->outln("exists");
                if (!(xos::fs::entry_type_directory != (entry_type))) {
                    path_search(path.chars());
                }
            } else {
                this->outln("doesn't exist");
            }
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    int path_search(const char_t* path) {
        int err = 0;
        if ((path) && (path[0])) {
            branch b(path);
            search(b);
        }
        return err;
    }
    int (derives::*search_)(branch& b);
    virtual int search(branch& b) {
        int err = 0;
        if ((search_)) {
            err = (this->*search_)(b);
        } else {
            err = depth_first_search(b);
        }
        return err;
    }
    virtual int all_search(branch& b) {
        int err = 0;
        if (!(err = breadth_first_search(b))) {
            this ->outln();
            if (!(err = depth_first_search(b))) {
                this ->outln();
                if (!(err = depend_first_search(b))) {
                    this ->outln();
                    if (!(err = bottom_first_search(b))) {
                    }
                }
            }
        }
        return err;
    }
    virtual int breadth_first_search(branch& b) {
        int err = 0;
        xos::std::tree::findt<branch, xos::std::tree::breadth_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }
    virtual int depth_first_search(branch& b) {
        int err = 0;
        xos::std::tree::findt<branch, xos::std::tree::depth_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }
    virtual int depend_first_search(branch& b) {
        int err = 0;
        xos::std::tree::findt<branch, xos::std::tree::depend_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }
    virtual int bottom_first_search(branch& b) {
        int err = 0;
        xos::std::tree::findt<branch, xos::std::tree::bottom_first_searcht<branch, branches, leaves>, maint> search(*this, b);
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace uarcha
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_UARCHA_MAIN_HPP
