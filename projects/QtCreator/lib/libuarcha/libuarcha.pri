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
#   File: libuarcha.pri
#
# Author: $author$
#   Date: 8/19/2022
#
# generic QtCreator project .pri file for framework uarcha static library libuarcha
########################################################################

########################################################################
# libuarcha
XOS_LIB_UARCHA_VERSION_BUILD_DATE = 8/19/2022 #$$system(~/bin/utility/tdate)

# libuarcha TARGET
#
libuarcha_TARGET = uarcha
libuarcha_TEMPLATE = lib
libuarcha_CONFIG += staticlib

# libuarcha INCLUDEPATH
#
libuarcha_INCLUDEPATH += \
$${uarcha_INCLUDEPATH} \

# libuarcha DEFINES
#
libuarcha_DEFINES += \
$${uarcha_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_UARCHA_VERSION_BUILD_DATE=$${XOS_LIB_UARCHA_VERSION_BUILD_DATE} \

########################################################################
# libuarcha OBJECTIVE_HEADERS
#
#libuarcha_OBJECTIVE_HEADERS += \
#$${UARCHA_SRC}/xos/lib/uarcha/version.hh \

# libuarcha OBJECTIVE_SOURCES
#
#libuarcha_OBJECTIVE_SOURCES += \
#$${UARCHA_SRC}/xos/lib/uarcha/version.mm \

########################################################################
# libuarcha HEADERS
#
libuarcha_HEADERS += \
$${UARCHA_SRC}/xos/lib/uarcha/version.hpp \

# libuarcha SOURCES
#
libuarcha_SOURCES += \
$${UARCHA_SRC}/xos/lib/uarcha/version.cpp \

########################################################################

