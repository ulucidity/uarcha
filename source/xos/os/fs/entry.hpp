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
#ifndef XOS_OS_FS_ENTRY_HPP
#define XOS_OS_FS_ENTRY_HPP

#include "xos/os/fs.hpp"

#if defined(WINDOWS)
#include "xos/os/microsoft/windows/fs/entry.hpp"
#elif defined(APPLEOSX)
#include "xos/os/apple/osx/fs/entry.hpp"
#elif defined(LINUX)
#include "xos/os/linux/fs/entry.hpp"
#else // defined(WINDOWS)
#include "xos/os/posix/fs/entry.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace os {

} /// namespace os
} /// namespace xos

#endif /// ndef XOS_OS_FS_ENTRY_HPP