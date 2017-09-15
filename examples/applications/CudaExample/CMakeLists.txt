set(targetName CudaExample)        #REQUIRED#

set(linkDirectories "")
set(libsToLink "")
set(includeDirectories "")

#glob files and save in MY_SRCS
include(CMakePackage.cmake)

include (${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/Cuda/CudaCreateTarget.cmake)
createCudaEXE(${targetName} "${MY_SRCS}" "${linkDirectories}" "${libsToLink}" "${includeDirectories}")

#Specify the linking to 3rdParty libs
include(3rdPartyLinking.cmake)
