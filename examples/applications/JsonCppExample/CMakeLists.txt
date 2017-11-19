set(targetName JsonCppExample)       #REQUIRED#

set(linkDirectories "")
set(libsToLink "")
set(includeDirectories "")

#glob files and save in MY_SRCS
include(CMakePackage.cmake)

buildExe(${targetName} "${MY_SRCS}" "${linkDirectories}" "${libsToLink}" "${includeDirectories}")
groupTarget(${targetName} ${CppExamples})

target_compile_definitions(${targetName} PRIVATE JSONPATH="${CMAKE_CURRENT_LIST_DIR}")

#Specify the linking to 3rdParty libs
include(3rdPartyLinking.cmake)
