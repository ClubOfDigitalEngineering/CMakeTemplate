setTargetNameToFolderName(${CMAKE_CURRENT_LIST_DIR})

set(linkDirectories "")
set(libsToLink "")
set(includeDirectories "")

#glob files and save in MY_SRCS
include(CMakePackage.cmake)


enable_language(CSharp)
buildExe(${targetName} "${MY_SRCS}" "${linkDirectories}" "${libsToLink}" "${includeDirectories}")
set_property( TARGET  ${targetName}  PROPERTY  FOLDER  ${CSharpExamples} )

#Specify the linking to 3rdParty libs
include(3rdPartyLinking.cmake)
