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
///   File: string.hpp
///
/// Author: $author$
///   Date: 8/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_FS_STRING_HPP
#define XOS_FS_STRING_HPP

#include "xos/base/string.hpp"

namespace xos {
namespace fs {

/// class stringt
template 
<class TString = xos::char_string, 
 class TExtends = TString, class TImplements = typename TExtends::implements>

class exported stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef stringt derives; 
    
    typedef TString string_t;
    typedef typename string_t::char_t char_t;
    typedef typename string_t::end_char_t end_char_t;
    enum { end_char = string_t::end_char };

    /// constructors / destructor
    stringt(const char* chars, size_t length) {
        this->append(chars, length);
    }
    stringt(const wchar_t* chars, size_t length) {
        this->append(chars, length);
    }
    stringt(const char* chars) {
        this->append(chars);
    }
    stringt(const wchar_t* chars) {
        this->append(chars);
    }
    stringt(const string_t& copy): extends(copy) {
    }
    stringt(const stringt& copy): extends(copy) {
    }
    stringt() {
    }
    virtual ~stringt() {
    }

    /// wchar_t
    /// ...
    /// assign...
    using extends::assign;
    virtual stringt& assign(const wchar_t* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& assign(const wchar_t* chars, size_t length) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& assignl(const wchar_t* chars, ...) {
        this->clear();
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& assignv(const wchar_t* chars, va_list va) {
        this->clear();
        if ((chars)) {
            this->appendv(chars, va);
        }
        return *this;
    }
    /// append...
    using extends::append;
    virtual stringt& append(const wchar_t* chars) {
        if ((chars)) {
            for (wchar_t c = *chars; c != 0; c = *(++chars)) {
                char_t tc = ((char_t)c);
                extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& append(const wchar_t* chars, size_t length) {
        if ((chars) && (length)) {
            for (; length > 0; --length, ++chars) {
                char_t tc = ((char_t)(*chars));
                extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& appendl(const wchar_t* chars, ...) {
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& appendv(const wchar_t* chars, va_list va) {
        if ((chars)) {
            do {
                this->append(chars);
            } while ((chars = va_arg(va, const wchar_t*)));
        }
        return *this;
    }
    /// ...
    /// wchar_t

    /// char
    /// ...
    /// assign...
    virtual stringt& assign(const char* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual stringt& assign(const char* chars, size_t length) {
        this->clear();
        this->append(chars, length);
        return *this;
    }
    virtual stringt& assignl(const char* chars, ...) {
        this->clear();
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& assignv(const char* chars, va_list va) {
        this->clear();
        if ((chars)) {
            this->appendv(chars, va);
        }
        return *this;
    }
    /// append...
    virtual stringt& append(const char* chars) {
        if ((chars)) {
            for (char c = *chars; c != 0; c = *(++chars)) {
                char_t tc = ((char_t)c);
                extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& append(const char* chars, size_t length) {
        if ((chars) && (length)) {
            for (; length > 0; --length, ++chars) {
                char_t tc = ((char_t)(*chars));
                extends::append(&tc, 1);
            }
        }
        return *this;
    }
    virtual stringt& appendl(const char* chars, ...) {
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
        return *this;
    }
    virtual stringt& appendv(const char* chars, va_list va) {
        if ((chars)) {
            do {
                this->append(chars);
            } while ((chars = va_arg(va, const char*)));
        }
        return *this;
    }
    /// ...
    /// char

}; /// class stringt
typedef stringt<> string;

typedef stringt<xos::char_string> cstring;
typedef stringt<xos::tchar_string> tstring;
typedef stringt<xos::wchar_string> wstring;

} /// namespace fs
} /// namespace xos

#endif /// ndef XOS_FS_STRING_HPP
