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
///   File: string.cpp
///
/// Author: $author$
///   Date: 8/21/2022
///////////////////////////////////////////////////////////////////////
#include "xos/fs/string.hpp"

#if !defined(XOS_FS_STRING_INSTANCE)
///#define XOS_FS_STRING_INSTANCE
#endif /// !defined(XOS_FS_STRING_INSTANCE)

namespace xos {
namespace fs {

///  Class: stringt
#if defined(XOS_FS_STRING_INSTANCE)
static string the_string;
#endif /// defined(XOS_FS_STRING_INSTANCE)


} /// namespace fs
} /// namespace xos
