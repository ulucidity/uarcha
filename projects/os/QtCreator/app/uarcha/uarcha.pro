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
#   File: uarcha.pro
#
# Author: $author$
#   Date: 8/19/2022
#
# os specific QtCreator project .pro file for framework uarcha executable uarcha
########################################################################
#
# Debug: uarcha/build/os/QtCreator/Debug/bin/uarcha
# Release: uarcha/build/os/QtCreator/Release/bin/uarcha
# Profile: uarcha/build/os/QtCreator/Profile/bin/uarcha
#
include(../../../../../build/QtCreator/uarcha.pri)
include(../../../../QtCreator/uarcha.pri)
include(../../uarcha.pri)
include(../../../../QtCreator/app/uarcha/uarcha.pri)

TARGET = $${uarcha_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${uarcha_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${uarcha_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${uarcha_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${uarcha_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${uarcha_exe_HEADERS} \
$${uarcha_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${uarcha_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${uarcha_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${uarcha_exe_LIBS} \
$${FRAMEWORKS} \

########################################################################

