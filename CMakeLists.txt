cmake_minimum_required (VERSION 3.10)
project (cblackjack)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(VERSION_MAJOR, 1)
set(VERSION_MINOR, 0)
set(VERSION_PATCH, 0)

add_compile_options(
	"-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
	"$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

include(cmake/CodeCoverage.cmake)

append_coverage_compiler_flags()
setup_target_for_coverage_lcov(
	NAME coverage 
	EXECUTABLE ctest 
	EXCLUDE "test/include/*" "/usr/include/*"
)

add_subdirectory (src)

enable_testing()

add_subdirectory (test)

include(cmake/Doxygen.cmake)
