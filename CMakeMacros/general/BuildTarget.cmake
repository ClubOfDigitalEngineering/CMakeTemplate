macro(buildExe targetName sourceFiles linkDirs libsToLink includeDirs)
    setLinkDirectories("${linkDirs}")

    add_executable(${targetName} "${sourceFiles}")

    linkLibraries(${targetName} "${libsToLink}")
    setIncludeDirectories("${includeDirs}")

endmacro(buildExe)

macro(buildLib libName sourceFiles linkDirs libsToLink includeDirs)
    setLinkDirectories("${linkDirs}")

    add_library(${libName} ${LIB_TYPE} ${sourceFiles})

    linkLibraries(${libName} "${libsToLink}")
    setIncludeDirectories("${includeDirs}")

endmacro(buildLib)


macro(setLinkDirectories linkDirs)
    foreach(dir ${linkDirs})
        link_directories(${dir})
    endforeach()
endmacro(setLinkDirectories)

macro(linkLibraries targetName libsToLink)
    foreach(lib ${libsToLink})
        target_link_libraries(${targetName} ${lib})
    endforeach()
endmacro(linkLibraries)

macro(setIncludeDirectories includeDirs)
    foreach(dir ${includeDirs})
        include_directories(${dir})
    endforeach()
endmacro(setIncludeDirectories)



include (GenerateExportHeader)
macro(generateExportHeader libName path)
    if(${BUILD_SHARED_LIBS})
            GENERATE_EXPORT_HEADER	(${libName}
                    BASE_NAME ${libName}
                    EXPORT_MACRO_NAME ${libName}_EXPORT
                    EXPORT_FILE_NAME ${path}/${libName}_EXPORT.h
                    STATIC_DEFINE ${libName}_BUILT_AS_STATIC
                    )
    endif()
endmacro(generateExportHeader)