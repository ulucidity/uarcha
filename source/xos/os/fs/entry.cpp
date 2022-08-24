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
///   File: entry.cpp
///
/// Author: $author$
///   Date: 8/22/2022
///////////////////////////////////////////////////////////////////////
#include "xos/os/fs/entry.hpp"

#if defined(WINDOWS)
#include "xos/os/microsoft/windows/fs/entry.cpp"
#elif defined(APPLEOSX)
#include "xos/os/apple/osx/fs/entry.cpp"
#elif defined(LINUX)
#include "xos/os/linux/fs/entry.cpp"
#else // defined(WINDOWS)
#include "xos/os/posix/fs/entry.cpp"
#endif // defined(WINDOWS)

namespace xos {
namespace os {

} /// namespace os
} /// namespace xos