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
#   File: libuarcha.pro
#
# Author: $author$
#   Date: 8/19/2022
#
# os specific QtCreator project .pro file for framework uarcha static library libuarcha
########################################################################
#
# Debug: uarcha/build/os/QtCreator/Debug/lib/libuarcha
# Release: uarcha/build/os/QtCreator/Release/lib/libuarcha
# Profile: uarcha/build/os/QtCreator/Profile/lib/libuarcha
#
include(../../../../../build/QtCreator/uarcha.pri)
include(../../../../QtCreator/uarcha.pri)
include(../../uarcha.pri)
include(../../../../QtCreator/lib/libuarcha/libuarcha.pri)

TARGET = $${libuarcha_TARGET}
TEMPLATE = $${libuarcha_TEMPLATE}
CONFIG += $${libuarcha_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libuarcha_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libuarcha_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libuarcha_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libuarcha_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libuarcha_HEADERS} \
$${libuarcha_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libuarcha_SOURCES} \

########################################################################

