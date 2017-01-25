MESSAGE(STATUS "starting to build examples...")

#independent from 3rd party libs
add_subdirectory(LibExample)

#GMock
include(${CMAKE_SOURCE_DIR}/cmake/GMock/FindGMock.cmake)
IF (GMock_FOUND)
	add_subdirectory(LibExampleTest)
	add_subdirectory(AllTestExample)
	add_subdirectory(GMockExample)
ELSE()
	MESSAGE("GMock on system not found - skip example")
ENDIF()

#Boost
find_package(Boost)
IF (Boost_FOUND)
	add_subdirectory(BoostExample)
ELSE()
	MESSAGE("Boost on system not found - skip example")
ENDIF()

#Qt
find_package(Qt5Charts)
IF (Qt5Charts_FOUND)
	add_subdirectory(QtExample)
ELSE()
	MESSAGE("Qt Charts (example requires Qt version 5.7) on system not found - skip example")
ENDIF()

#VTK
find_package(VTK)
IF (VTK_FOUND)
	add_subdirectory(VTKExample)
ELSE()
	MESSAGE("VTK on system not found - skip example")
ENDIF()

#Cuda
find_package(CUDA)
IF (CUDA_FOUND)
	add_subdirectory(CudaExample)
ELSE()
	MESSAGE("CUDA on system not found - skip example")
ENDIF()

MESSAGE(STATUS "... finish building examples")