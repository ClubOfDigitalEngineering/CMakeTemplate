include(${CMAKE_SOURCE_DIR}/cmake/general/BuildTarget.cmake)
MACRO(createCudaLIB targetName sourceFiles linkDirs libsToLink includeDirs)
#input: lib, libtype (e.g. shared), src files
    setLinkDirectories("${linkDirs}")
	
	CUDA_ADD_LIBRARY(${targetName} ${LIB_TYPE} ${sourceFiles})
						
	linkLibraries(${targetName} "${libsToLink}")
    setIncludeDirectories("${includeDirs}")
#output: -
ENDMACRO(createCudaLIB)


MACRO(createCudaEXE targetName sourceFiles linkDirs libsToLink includeDirs)
#input: EXE_NAME, src files
    setLinkDirectories("${linkDirs}")

	cuda_add_executable(${targetName} ${sourceFiles})

    linkLibraries(${targetName} "${libsToLink}")
    setIncludeDirectories("${includeDirs}")
#output: -
ENDMACRO(createCudaEXE)