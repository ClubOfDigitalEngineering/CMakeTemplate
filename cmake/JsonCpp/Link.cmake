macro(linkJsonCpp targetName)

	include(${CMAKE_SOURCE_DIR}/cmake/JsonCpp/FindJsonCpp.cmake)
	include_directories(${JSONCPP_INCLUDE_DIRS})

	target_link_libraries(${targetName} ${JSONCPP_LIBRARIES})

endmacro(linkJsonCpp)
