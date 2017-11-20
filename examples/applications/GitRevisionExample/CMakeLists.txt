set(targetName GitRevisionExample)       #REQUIRED#

set(linkDirectories "")
set(libsToLink "")
set(includeDirectories "")

#glob files and save in MY_SRCS
include(CMakePackage.cmake)

include(buildInfo.cmake)

buildExe(${targetName} "${MY_SRCS}" "${linkDirectories}" "${libsToLink}" "${includeDirectories}")
groupTarget(${targetName} ${CppExamples})


#Specify the linking to 3rdParty libs
include(3rdPartyLinking.cmake)
