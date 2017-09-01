# - Try to find METIS
# Once done this will define
#
#  METIS_FOUND        - system has METIS
#  METIS_INCLUDE_DIRS - include directories for METIS
#  METIS_LIBRARIES    - libraries for METIS
#
# Variables used by this module. They can change the default behaviour and
# need to be set before calling find_package:
#
#  METIS_DIR          - Prefix directory of the METIS installation
#  METIS_INCLUDE_DIR  - Include directory of the METIS installation
#                       (set only if different from ${METIS_DIR}/include)
#  METIS_LIB_DIR      - Library directory of the METIS installation
#                       (set only if different from ${METIS_DIR}/lib)
#  METIS_TEST_RUNS    - Skip tests building and running a test
#                       executable linked against METIS libraries
#  METIS_LIB_SUFFIX   - Also search for non-standard library names with the
#                       given suffix appended
#
# NOTE: This file was modified from a ParMETIS detection script 

#=============================================================================
# Copyright (C) 2015 Jack Poulson. All rights reserved.
#
# Copyright (C) 2010-2012 Garth N. Wells, Anders Logg, Johannes Ring
# and Florian Rathgeber. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#=============================================================================


find_path(JSONCPP_INCLUDE_DIRS json/json.h
    HINTS ${JSONCPP_ROOT} ENV JSONCPP_ROOT
    PATH_SUFFIXES include
    DOC "Directory where the JSONCPP header files are located"
)



find_library(JSONCPP_LIBRARIES
    NAMES jsoncpp.lib 
    HINTS ${JSONCPP_LIBRARIES_PATH}
    DOC "Directory where the JSONCPP library is located"
)


# Standard package handling
include(FindPackageHandleStandardArgs)
if(CMAKE_VERSION VERSION_GREATER 2.8.2)
  find_package_handle_standard_args(JSONCPP
    REQUIRED_VARS JSONCPP_INCLUDE_DIRS JSONCPP_LIBRARIES)
else()
  find_package_handle_standard_args(JSONCPP
    REQUIRED_VARS JSONCPP_INCLUDE_DIRS JSONCPP_LIBRARIES)
endif()


mark_as_advanced(JSONCPP_INCLUDE_DIRS JSONCPP_LIBRARIES)