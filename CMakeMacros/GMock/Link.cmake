include(${CMAKE_CURRENT_LIST_DIR}/FindGMock.cmake)
macro(linkGMock targetName)
	add_definitions(-DGTEST_LINKED_AS_SHARED_LIBRARY)

	include_directories(${GMOCK_INCLUDE_DIR})
	include_directories(${GMOCK_GTEST_INCLUDE_DIR})

	target_link_libraries(${targetName}  ${GMOCK_BOTH_LIBRARIES})
endmacro(linkGMock)
