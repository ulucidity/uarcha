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
///   File: path_separator.cpp
///
/// Author: $author$
///   Date: 8/21/2022
///////////////////////////////////////////////////////////////////////
#include "xos/fs/path_separator.hpp"

#if !defined(XOS_FS_PATH_SEPARATOR_INSTANCE)
///#define XOS_FS_PATH_SEPARATOR_INSTANCE
#endif /// !defined(XOS_FS_PATH_SEPARATOR_INSTANCE)

namespace xos {
namespace fs {

///  Class: path_separatort
#if defined(XOS_FS_PATH_SEPARATOR_INSTANCE)
static path_separator the_path_separator;
#endif /// defined(XOS_FS_PATH_SEPARATOR_INSTANCE)


} /// namespace fs
} /// namespace xos
