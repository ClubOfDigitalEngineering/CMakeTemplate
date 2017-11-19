include(${CMAKE_CURRENT_LIST_DIR}/FindFftw.cmake)

macro(linkFftw targetName)

	target_include_directories(${targetName} PUBLIC ${FFTW_INCLUDE_DIRS})
	target_link_libraries(${targetName} ${FFTW_LIBRARIES})

endmacro(linkFftw)
