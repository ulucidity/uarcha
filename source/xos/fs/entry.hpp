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
///   File: entry.hpp
///
/// Author: $author$
///   Date: 8/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_ENTRY_HPP
#define XOS_FS_ENTRY_HPP

#include "xos/fs/entry_type.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace fs {

/// class entryt
template 
<class TString = xos::fs::string, 
 class TExtends = xos::extended::logged, class TImplements = typename TExtends::implements>

class exported entryt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef entryt derives; 
    
    typedef xos::fs::wstring wchar_string_t;
    typedef xos::fs::cstring char_string_t;
    typedef TString string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    entryt(const entryt& copy): extends(copy) {
        construct(copy);
    }
    entryt() {
        construct();
    }
    virtual ~entryt() {
        destruct();
    }

    /// exists
    virtual entry_type exists(const char* chars) {
        const string_t path(chars);
        return exists(path);
    }
    virtual entry_type exists(const wchar_t* chars) {
        const string_t path(chars);
        return exists(path);
    }
    virtual entry_type exists(const string_t& path) {
        return entry_type_none;
    }

    /// set_times...set
    virtual fs::time_when set_times_to_set(const entryt& e, bool is_local = false) {
        fs::time_when times = time_when_none;
        const time& time_modified = e.time_modified();
        const time& time_accessed = e.time_accessed();
        const time& time_changed = e.time_changed();
        const time& time_created = e.time_created();
        times = set_times_to_set
        (time_modified, time_accessed,
         time_changed, time_created, is_local);
        return times;
    }
    virtual fs::time_when set_times_to_set
    (const time& time_modified, const time& time_accessed,
     const time& time_changed, const time& time_created,
     bool is_local = false) {
        fs::time_when times = time_when_none;
        return times;
    }
    virtual fs::time_when set_times_set() {
        fs::time_when times = time_when_none;
        return times;
    }

    /// ...path
    virtual const char_t* set_path(const char_t* chars, size_t length) {
        path_.assign(chars, length);
        on_set_path();
        return path_.c_str();
    }
    virtual const char_t* set_path(const char_t* chars) {
        path_.assign(chars);
        on_set_path();
        return path_.c_str();
    }
    virtual const char_t* has_path(size_t& length) const {
        if ((length = path_.length())) {
            return path_.c_str();
        }
        return 0;
    }
    virtual const char_t* has_path() const {
        if ((path_.length())) {
            return path_.c_str();
        }
        return 0;
    }
    virtual const char_t* path(size_t& length) const {
        length = path_.length();
        return path_.c_str();
    }
    virtual const char_t* path() const {
        return path_.c_str();
    }

    /// ...name
    virtual const char_t* set_name(const char_t* chars, size_t length) {
        name_.assign(chars, length);
        on_set_name();
        return name_.c_str();
    }
    virtual const char_t* set_name(const char_t* chars) {
        name_.assign(chars);
        on_set_name();
        return name_.c_str();
    }
    virtual const char_t* has_name(size_t& length) const {
        if ((length = name_.length())) {
            return name_.c_str();
        }
        return 0;
    }
    virtual const char_t* has_name() const {
        if ((name_.length())) {
            return name_.c_str();
        }
        return 0;
    }
    virtual const char_t* name(size_t& length) const {
        length = name_.length();
        return name_.c_str();
    }
    virtual const char_t* name() const {
        return name_.c_str();
    }

    /// ...size / ...type
    virtual entry_size_t set_size(entry_size_t size) {
        size_ = size;
        on_set_size();
        return size_;
    }
    virtual entry_size_t size() const {
        return size_;
    }
    virtual const entry_type& set_type(const entry_type& type) {
        type_ = type;
        on_set_type();
        return type_;
    }
    virtual const entry_type& type() const {
        return type_;
    }

    /// ...is_directory / ...is_hidden
    virtual bool set_is_directory(bool to = true) {
        entry_type type((to)?(entry_type_directory):(entry_type_file));
        set_type(type);
        return is_directory();
    }
    virtual bool is_directory() const {
        if ((entry_type_directory == (entry_type_directory & (this->type().which())))) {
            return true;
        }
        return false;
    }
    virtual bool set_is_hidden(bool is_hidden = true) {
        is_hidden_ = is_hidden;
        on_set_is_hidden();
        return is_hidden_;
    }
    virtual bool is_hidden() const {
        return is_hidden_;
    }

    /// ...times
    virtual const fs::time_when& set_times(const fs::time_when& times) {
        times_ = times;
        return times_;
    }
    virtual const fs::time_when& times() const {
        return times_;
    }

    /// ...time...ed
    virtual const time& set_time_modified(const time& to) {
        times_ |= time_when_modified;
        time_modified_ = to;
        return time_modified_;
    }
    virtual const time& time_modified() const {
        return time_modified_;
    }
    virtual const time& set_time_accessed(const time& to) {
        times_ |= time_when_accessed;
        time_accessed_ = to;
        return time_accessed_;
    }
    virtual const time& time_accessed() const {
        return time_accessed_;
    }
    virtual const time& set_time_changed(const time& to) {
        times_ |= time_when_changed;
        time_changed_ = to;
        return time_changed_;
    }
    virtual const time& time_changed() const {
        return time_changed_;
    }
    virtual const time& set_time_created(const time& to) {
        times_ |= time_when_created;
        time_created_ = to;
        return time_created_;
    }
    virtual const time& time_created() const {
        return time_created_;
    }

    /// ...time_when
    virtual const time* has_time_when(const fs::time_when& when) const {
        const time_when_which which = when.which();
        return has_time_when(which);
    }
    virtual const time* has_time_when(time_when_which which) const {
        if (which == (times_.has_which(which))) {
            return time_when(which);
        }
        return 0;
    }
    virtual const time* time_when(const fs::time_when& when) const {
        const time_when_which which = when.which();
        return time_when(which);
    }
    virtual const time* time_when(time_when_which which) const {
        switch (which) {
        case fs::time_when_modified:
            return &time_modified_;
            break;
        case fs::time_when_accessed:
            return &time_accessed_;
            break;
        case fs::time_when_changed:
            return &time_changed_;
            break;
        case fs::time_when_created:
            return &time_created_;
            break;
        }
        return 0;
    }

    /// set / clear
    virtual entryt& set(const entryt& copy) {
        path_=(copy.path()), name_=(copy.name()), is_hidden_=(copy.is_hidden()),
        size_=(copy.size()), type_=(copy.type()), times_=(copy.times()),
        time_modified_=(copy.time_modified()), time_accessed_=(copy.time_accessed()),
        time_changed_=(copy.time_changed()), time_created_=(copy.time_created());
        return *this;
    }
    virtual entryt& clear() {
        is_hidden_ = false;
        size_ = 0;
        type_.clear();
        times_.clear();
        time_modified_.clear();
        time_accessed_.clear();
        time_changed_.clear();
        time_created_.clear();
        path_.clear();
        name_.clear();
        return *this;
    }

protected:
    /// on_set...
    virtual void on_set_is_hidden() {
    }
    virtual void on_set_path() {
    }
    virtual void on_set_name() {
    }
    virtual void on_set_size() {
    }
    virtual void on_set_type() {
    }

private:
    /// construct / destruct
    void construct(const entryt& copy) {
        path_=(copy.path()), name_=(copy.name()), is_hidden_=(copy.is_hidden()),
        size_=(copy.size()), type_=(copy.type()), times_=(copy.times()),
        time_modified_=(copy.time_modified()), time_accessed_=(copy.time_accessed()),
        time_changed_=(copy.time_changed()), time_created_=(copy.time_created());
    }
    void construct() {
        is_hidden_=(false), size_=(0), type_=(entry_type_none), times_=(time_when_none),
        time_modified_=(time_when_modified), time_accessed_=(time_when_accessed),
        time_changed_=(time_when_changed), time_created_=(time_when_created);
    }
    void destruct() {
        name_.clear();
        path_.clear();
    }

protected:
    string_t path_, name_;
    bool is_hidden_;
    entry_size_t size_;
    entry_type type_;
    fs::time_when times_;
    time time_modified_, time_accessed_, time_changed_, time_created_;
}; /// class entryt
typedef entryt<> entry;

} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_ENTRY_HPP
