set(targetName BoostExample)     #REQUIRED#

set(linkDirectories "")
set(libsToCollect "")
set(includeDirectories "")

#glob files and save in MY_SRCS
include(CMakePackage.cmake)

buildExe(${targetName} "${MY_SRCS}" "${linkDirectories}" "${libsToLink}" "${includeDirectories}")

#Specify the linking to 3rdParty libs
include(3rdPartyLinking.cmake)
