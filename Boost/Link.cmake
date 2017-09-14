
# usage: linkBoost(${targetName} COMPONENTS arg0 arg1 arg2 ...)
# e.g.   linkBoost(${targetName} COMPONENTS "Thread" "Signals")
# e.g.   linkBoost(${targetName})

function(linkBoost)
  if (WIN32)
	add_definitions( -DBOOST_ALL_NO_LIB )
	add_definitions( -DBOOST_ALL_DYN_LINK )
  endif()

  list(LENGTH ARGV arguments)
  math(EXPR argn "${arguments} - 1")

  if(argn EQUAL 0)
    FIND_PACKAGE( Boost REQUIRED)
	INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
	TARGET_LINK_LIBRARIES( ${targetName} ${Boost_LIBRARIES} )
    return()
  endif()

  foreach(index RANGE 2 ${argn})
    list(GET ARGV ${index} component)
	FIND_PACKAGE( Boost REQUIRED COMPONENTS ${component})
	INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
	TARGET_LINK_LIBRARIES( ${targetName} ${Boost_LIBRARIES} )
  endforeach()
  
endfunction(linkBoost)
