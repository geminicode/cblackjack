include_directories(include)

file(GLOB SOURCE_FILES *.cpp)

foreach(TESTSOURCE ${SOURCE_FILES})

    get_filename_component(TESTEXE ${TESTSOURCE} NAME_WE)
	add_executable(${TESTEXE} ${TESTSOURCE} )

	target_link_libraries(${TESTEXE} gtest gmock gtest_main pthread ${CMAKE_PROJECT_NAME})

	add_test(NAME ${TESTEXE} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TESTEXE})

endforeach()