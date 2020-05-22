cmake_minimum_required (VERSION 3.10)
project (cblackjack)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(VERSION_MAJOR, 1)
set(VERSION_MINOR, 0)
set(VERSION_PATCH, 0)

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

add_compile_options(
	"-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
	"$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

include(cmake/CodeCoverage.cmake)

# setup_target_for_coverage(NAME ${PROJECT_NAME}_coverage)

setup_target_for_coverage_lcov(
      NAME ${PROJECT_NAME}_coverage               # New target name
#     EXECUTABLE testrunner -j ${PROCESSOR_COUNT} # Executable in PROJECT_BINARY_DIR
#     DEPENDENCIES testrunner                     # Dependencies to build first
      BASE_DIRECTORY "${CMAKE_BINARY_DIR}/coverage"    # Base directory for report
#                                                 #  (defaults to PROJECT_SOURCE_DIR)
#     EXCLUDE "src/dir1/*" "src/dir2/*"           # Patterns to exclude (can be relative
#                                                 #  to BASE_DIRECTORY, with CMake 3.4+)
#     NO_DEMANGLE                                 # Don't demangle C++ symbols
#                                                 #  even if c++filt is found
)

add_subdirectory (src)

enable_testing()

add_subdirectory (test)

include(cmake/Doxygen.cmake)
