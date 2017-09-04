macro(linkMetis targetName)

	include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/Metis/FindMetis.cmake)
	include_directories(${METIS_INCLUDE_DIRS})

	target_link_libraries(${targetName} ${METIS_LIBRARIES})

endmacro(linkMetis)
