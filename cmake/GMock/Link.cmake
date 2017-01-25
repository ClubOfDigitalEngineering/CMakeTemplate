macro(linkGMock targetName)
	add_definitions(-DGTEST_LINKED_AS_SHARED_LIBRARY)

	include_directories($ENV{GMOCK_HOME}/googlemock/include)
	include_directories($ENV{GMOCK_HOME}/googletest/include)

	set(GMOCK_LINK_PATH $ENV{GMOCK_HOME}/${PLATFORM}/googlemock)
	
	if(APPLE)
	target_link_libraries(${targetName} ${GMOCK_LINK_PATH}/libgmock_main.dylib ${GMOCK_LINK_PATH}/libgmock.dylib)
	endif()
	
	if(WIN32)
	target_link_libraries(${targetName} ${GMOCK_LINK_PATH}/Debug/gmock_main.lib ${GMOCK_LINK_PATH}/Debug/gmock.lib)
	endif()
endmacro(linkGMock)
