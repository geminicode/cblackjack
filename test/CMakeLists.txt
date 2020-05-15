enable_testing()

include_directories(include)

file(GLOB SOURCE_FILES *.cpp)

add_executable(unit_tests ${SOURCE_FILES} )

target_link_libraries(unit_tests gtest gmock gtest_main ${CMAKE_PROJECT_NAME})

add_test(NAME unit COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)