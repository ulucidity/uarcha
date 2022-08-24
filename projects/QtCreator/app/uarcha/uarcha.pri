########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: uarcha.pri
#
# Author: $author$
#   Date: 8/19/2022
#
# generic QtCreator project .pri file for framework uarcha executable uarcha
########################################################################

########################################################################
# uarcha

# uarcha_exe TARGET
#
uarcha_exe_TARGET = uarcha

# uarcha_exe INCLUDEPATH
#
uarcha_exe_INCLUDEPATH += \
$${uarcha_INCLUDEPATH} \

# uarcha_exe DEFINES
#
uarcha_exe_DEFINES += \
$${uarcha_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# uarcha_exe OBJECTIVE_HEADERS
#
#uarcha_exe_OBJECTIVE_HEADERS += \
#$${UARCHA_SRC}/xos/app/console/uarcha/main.hh \

# uarcha_exe OBJECTIVE_SOURCES
#
#uarcha_exe_OBJECTIVE_SOURCES += \
#$${UARCHA_SRC}/xos/app/console/uarcha/main.mm \

########################################################################
# uarcha_exe HEADERS
#
uarcha_exe_HEADERS += \
$${UARCHA_SRC}/xos/base/event.hpp \
$${UARCHA_SRC}/xos/base/seconds.hpp \
$${UARCHA_SRC}/xos/base/timezone.hpp \
$${UARCHA_SRC}/xos/base/time.hpp \
$${UARCHA_SRC}/xos/base/date.hpp \
\
$${UARCHA_SRC}/xos/fs/string.hpp \
$${UARCHA_SRC}/xos/fs/path_separator_events.hpp \
$${UARCHA_SRC}/xos/fs/path_separator.hpp \
$${UARCHA_SRC}/xos/fs/path.hpp \
$${UARCHA_SRC}/xos/fs/time_when.hpp \
$${UARCHA_SRC}/xos/fs/time.hpp \
$${UARCHA_SRC}/xos/fs/entry_type.hpp \
$${UARCHA_SRC}/xos/fs/entry.hpp \
$${UARCHA_SRC}/xos/fs/directory/entry.hpp \
$${UARCHA_SRC}/xos/fs/directory/path.hpp \
\
$${UARCHA_SRC}/xos/os/fs.hpp \
$${UARCHA_SRC}/xos/os/posix/fs/stat.hpp \
$${UARCHA_SRC}/xos/os/posix/fs/utimbuf.hpp \
$${UARCHA_SRC}/xos/os/posix/fs/entry.hpp \
$${UARCHA_SRC}/xos/os/posix/fs/directory/dirent.hpp \
$${UARCHA_SRC}/xos/os/posix/fs/directory/entry.hpp \
$${UARCHA_SRC}/xos/os/posix/fs/directory/path.hpp \
$${UARCHA_SRC}/xos/os/apple/osx/fs/entry.hpp \
$${UARCHA_SRC}/xos/os/apple/osx/fs/directory/entry.hpp \
$${UARCHA_SRC}/xos/os/apple/osx/fs/directory/path.hpp \
$${UARCHA_SRC}/xos/os/fs/entry.hpp \
$${UARCHA_SRC}/xos/os/fs/directory/entry.hpp \
$${UARCHA_SRC}/xos/os/fs/directory/path.hpp \
\
$${UARCHA_SRC}/xos/std/tree/leaves.hpp \
$${UARCHA_SRC}/xos/std/tree/leaf.hpp \
$${UARCHA_SRC}/xos/std/tree/reverse_range.hpp \
$${UARCHA_SRC}/xos/std/tree/branches.hpp \
$${UARCHA_SRC}/xos/std/tree/branch.hpp \
$${UARCHA_SRC}/xos/std/tree/find.hpp \
$${UARCHA_SRC}/xos/std/tree/search.hpp \
$${UARCHA_SRC}/xos/std/tree/breadth_first_search.hpp \
$${UARCHA_SRC}/xos/std/tree/depth_first_search.hpp \
$${UARCHA_SRC}/xos/std/tree/depend_first_search.hpp \
$${UARCHA_SRC}/xos/std/tree/bottom_first_search.hpp \
$${UARCHA_SRC}/xos/std/tree/searches.hpp \
$${UARCHA_SRC}/xos/std/tree/nodes.hpp \
$${UARCHA_SRC}/xos/std/tree/node.hpp \
$${UARCHA_SRC}/xos/std/tree/depth_first_read.hpp \
$${UARCHA_SRC}/xos/std/tree/depth_first_write.hpp \
\
$${UARCHA_SRC}/xos/std/fs/tree/node.hpp \
$${UARCHA_SRC}/xos/std/fs/tree/leaf.hpp \
$${UARCHA_SRC}/xos/std/fs/tree/branch.hpp \
\
$${UARCHA_SRC}/xos/app/console/uarcha/version/main_opt.hpp \
$${UARCHA_SRC}/xos/app/console/uarcha/version/main.hpp \
\
$${UARCHA_SRC}/xos/app/console/uarcha/main_opt.hpp \
$${UARCHA_SRC}/xos/app/console/uarcha/main.hpp \

# uarcha_exe SOURCES
#
uarcha_exe_SOURCES += \
$${UARCHA_SRC}/xos/base/event.cpp \
$${UARCHA_SRC}/xos/base/seconds.cpp \
$${UARCHA_SRC}/xos/base/timezone.cpp \
$${UARCHA_SRC}/xos/base/date.cpp \
\
$${UARCHA_SRC}/xos/fs/string.cpp \
$${UARCHA_SRC}/xos/fs/path_separator_events.cpp \
$${UARCHA_SRC}/xos/fs/path_separator.cpp \
$${UARCHA_SRC}/xos/fs/time_when.cpp \
$${UARCHA_SRC}/xos/fs/time.cpp \
$${UARCHA_SRC}/xos/fs/entry_type.cpp \
\
$${UARCHA_SRC}/xos/os/fs.cpp \
$${UARCHA_SRC}/xos/os/posix/fs/stat.cpp \
$${UARCHA_SRC}/xos/os/posix/fs/utimbuf.cpp \
$${UARCHA_SRC}/xos/os/posix/fs/directory/dirent.cpp \
$${UARCHA_SRC}/xos/os/fs/directory/entry.cpp \
$${UARCHA_SRC}/xos/os/fs/directory/path.cpp \
\
$${UARCHA_SRC}/xos/std/tree/leaves.cpp \
$${UARCHA_SRC}/xos/std/tree/reverse_range.cpp \
$${UARCHA_SRC}/xos/std/tree/branches.cpp \
$${UARCHA_SRC}/xos/std/tree/find.cpp \
$${UARCHA_SRC}/xos/std/tree/search.cpp \
$${UARCHA_SRC}/xos/std/tree/searches.cpp \
$${UARCHA_SRC}/xos/std/tree/nodes.cpp \
$${UARCHA_SRC}/xos/std/tree/depth_first_read.cpp \
$${UARCHA_SRC}/xos/std/tree/depth_first_write.cpp \
\
$${UARCHA_SRC}/xos/std/fs/tree/node.cpp \
$${UARCHA_SRC}/xos/std/fs/tree/leaf.cpp \
$${UARCHA_SRC}/xos/std/fs/tree/branch.cpp \
\
$${UARCHA_SRC}/xos/app/console/uarcha/main_opt.cpp \
$${UARCHA_SRC}/xos/app/console/uarcha/main.cpp \

########################################################################
# uarcha_exe FRAMEWORKS
#
uarcha_exe_FRAMEWORKS += \
$${uarcha_FRAMEWORKS} \

# uarcha_exe LIBS
#
uarcha_exe_LIBS += \
$${uarcha_LIBS} \

########################################################################
# NO Qt
QT -= gui core

