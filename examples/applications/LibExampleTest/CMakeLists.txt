set(targetName LibExampleTest)     #REQUIRED#

set(linkDirectories "")
set(libsToLink "LibExample")
set(includeDirectories ${CMAKE_SOURCE_DIR}/examples/src/LibExample)

#glob files and save in MY_SRCS
include(CMakePackage.cmake)

buildExe(${targetName} "${MY_SRCS}" "${linkDirectories}" "${libsToLink}" "${includeDirectories}")
groupTarget(${targetName} ${CppExamples})

add_definitions(-Wno-attributes)

#Specify the linking to 3rdParty libs
include(3rdPartyLinking.cmake)