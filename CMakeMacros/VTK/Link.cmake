macro(linkVTK targetName)
	find_package(VTK REQUIRED)
	include(${VTK_USE_FILE})

	target_link_libraries(${targetName} ${VTK_LIBRARIES})

endmacro(linkVTK)
