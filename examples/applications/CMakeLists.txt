MESSAGE(STATUS "starting to build examples...")

#group targets to folders:
set(CSharpExamples "CSharp_Examples")
set(CppExamples "Cpp_Examples")


option(EXAMPLES_BUILD_Cpp "build cpp example" ON)
option(EXAMPLES_BUILD_CSharp "build c# example" ON)

option(EXAMPLES_Cuda "build cuda example" ON)
option(EXAMPLES_Boost "build boost example" ON)
option(EXAMPLES_Qt5Charts "build qt 5 charts example" ON)
option(EXAMPLES_Lib "build lib example" ON)
option(EXAMPLES_GMock "build gmock example" ON)
option(EXAMPLES_Metis "build metis example" ON)
option(EXAMPLES_VTK "build vtk example" ON)
option(EXAMPLES_MPI "build MPI example" ON)
option(EXAMPLES_OpenMP "build OpenMP example" ON)
option(EXAMPLES_FFTW "build fftw example" ON)
option(EXAMPLES_JsonCpp "build JsonCpp example" ON)

if(EXAMPLES_BUILD_Cpp)
	MESSAGE(STATUS "building c++ examples...")
	
	#independent from 3rd party libs
	IF (EXAMPLES_Lib)
	  add_subdirectory(LibExample)
	endif()

	#GMock
	include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/GMock/FindGMock.cmake)
	IF (GMock_FOUND AND EXAMPLES_GMock)
		add_subdirectory(LibExampleTest)
		add_subdirectory(AllTestExample)
		add_subdirectory(GMockExample)
	ELSE()
		MESSAGE("GMock on system not found - skip example")
	ENDIF()

	#Boost
	find_package(Boost)
	IF (Boost_FOUND AND EXAMPLES_Boost)
		add_subdirectory(BoostExample)
	ELSE()
		MESSAGE("Boost on system not found - skip example")
	ENDIF()

	#Qt
	find_package(Qt5Charts)
	IF (Qt5Charts_FOUND AND EXAMPLES_Qt5Charts)
		add_subdirectory(QtExample)
	ELSE()
		MESSAGE("Qt Charts (example requires Qt version 5.7) on system not found - skip example")
	ENDIF()

	#VTK
	find_package(VTK)
	IF (VTK_FOUND AND EXAMPLES_VTK)
		add_subdirectory(VTKExample)
	ELSE()
		MESSAGE("VTK on system not found - skip example")
	ENDIF()

	#Metis
	include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/Metis/FindMetis.cmake)
	IF (METIS_FOUND AND EXAMPLES_Metis)
		add_subdirectory(MetisExample)
	ELSE()
		MESSAGE("Metis on system not found - skip example")
	ENDIF()

	#JsonCpp
	include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/JsonCpp/FindJsonCpp.cmake)
	IF (JSONCPP_FOUND AND EXAMPLES_JsonCpp)
		add_subdirectory(JsonCppExample)
	ELSE()
		MESSAGE("JsonCpp on system not found - skip example")
	ENDIF()

	#FFTW
	include(${CMAKE_SOURCE_DIR}/${cmakeMacroPath}/fftw/FindFftw.cmake)
	IF (FFTW_FOUND AND EXAMPLES_FFTW)
		add_subdirectory(FFTWExample)
	ELSE()
		MESSAGE("FFTW on system not found - skip example")
	ENDIF()

	#MPI
	find_package(MPI)
	IF (MPI_FOUND AND EXAMPLES_MPI)
		add_subdirectory(MPIExample)
	ELSE()
		MESSAGE("MPI on system not found - skip example")
	ENDIF()

	#OpenMP
	find_package(OpenMP)
	IF (OPENMP_FOUND AND EXAMPLES_OpenMP)
		add_subdirectory(OpenMPExample)
	ELSE()
		MESSAGE("OpenMP on system not found - skip example")
	ENDIF()

	if(EXAMPLES_Cuda)
		add_subdirectory(CudaExample)
	endif()

endif() # build cpp examples

if(EXAMPLES_BUILD_CSharp)
    MESSAGE(STATUS "building c# examples...")
    add_subdirectory(CSharpExample)
endif()

MESSAGE(STATUS "... finish building examples")