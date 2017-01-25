macro(linkBoost targetName)

	FIND_PACKAGE( Boost REQUIRED COMPONENTS system)
	INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

	TARGET_LINK_LIBRARIES( ${targetName} ${Boost_LIBRARIES} )

endmacro(linkBoost)
