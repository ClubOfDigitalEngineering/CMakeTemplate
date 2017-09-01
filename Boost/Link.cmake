macro(linkBoost targetName)

	FIND_PACKAGE( Boost REQUIRED COMPONENTS signals)
	INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

	TARGET_LINK_LIBRARIES( ${targetName} ${Boost_LIBRARIES} )

endmacro(linkBoost)
