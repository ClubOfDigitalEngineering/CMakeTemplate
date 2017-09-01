macro(linkCuda)
#input: -
	FIND_PACKAGE(CUDA REQUIRED)
	IF (CUDA_FOUND)
	    set(CUDA_64_BIT_DEVICE_CODE ON CACHE STRING "Compile device code in 64 bit mode" FORCE)

	    find_path(CUDA_CUT_INCLUDE_DIR
	   	  helper_cuda.h
	   	  PATHS "$ENV{NVSDKCOMPUTE_ROOT}" "$ENV{NVSDKCUDA_ROOT}"
	   	  PATH_SUFFIXES "common/inc" "samples/common/inc" "CUDA-5.5/samples/common/inc"
	   	  DOC "Location of helper_cuda.h"
	   	  NO_DEFAULT_PATH
   	    )
	    find_path(CUDA_CUT_INCLUDE_DIR helper_cuda.h DOC "Location of helper_cuda.h")
	    #set(CUDA_SEPARABLE_COMPILATION ON CACHE STRING "Compile seperate" FORCE)

		#CUDA_INCLUDE_DIRECTORIES(${CUDA_CUT_INCLUDE_DIR})
		#INCLUDE_DIRECTORIES( ${CUDA_INCLUDE_DIRS} ${CUDA_CUT_INCLUDE_DIR})
		INCLUDE_DIRECTORIES( ${CUDA_INCLUDE_DIRS})
		link_directories(${CUDA_INCLUDE_DIRS}/../lib/x64)
		
		#set( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -gencode arch=compute_13,code=sm_13 )
    ELSE()
      MESSAGE(FATAL_ERROR "CUDA ${CUDA_VERSION} not found.")
    ENDIF()
#output: -
endmacro(linkCuda)