MESSAGE(STATUS "starting to build examples...")

#group targets to folders:
set(CSharpExamples "CSharp_Examples")
set(CppExamples "Cpp_Examples")

#independent from 3rd party libs
add_subdirectory(LibExample)

#GMock
include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/GMock/FindGMock.cmake)
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

#Metis
include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/Metis/FindMetis.cmake)
IF (METIS_FOUND)
	add_subdirectory(MetisExample)
ELSE()
	MESSAGE("Metis on system not found - skip example")
ENDIF()

#JsonCpp
include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/JsonCpp/FindJsonCpp.cmake)
IF (JSONCPP_FOUND)
	add_subdirectory(JsonCppExample)
ELSE()
	MESSAGE("JsonCpp on system not found - skip example")
ENDIF()

#FFTW
include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/fftw/FindFftw.cmake)
IF (FFTW_FOUND)
	add_subdirectory(FFTWExample)
ELSE()
	MESSAGE("FFTW on system not found - skip example")
ENDIF()

#MPI
find_package(MPI)
IF (MPI_FOUND)
	add_subdirectory(MPIExample)
ELSE()
	MESSAGE("MPI on system not found - skip example")
ENDIF()

#OpenMP
find_package(OpenMP)
IF (OPENMP_FOUND)
	add_subdirectory(OpenMPExample)
ELSE()
	MESSAGE("OpenMP on system not found - skip example")
ENDIF()

option(BUILD_CudaExample "build cuda example" ON)
if(BUILD_CudaExample)
    add_subdirectory(CudaExample)
endif()

option(BUILD_CSharpExample "build c# example" ON)
if(BUILD_CSharpExample)
    add_subdirectory(CSharpExample)
endif()

MESSAGE(STATUS "... finish building examples")