cmake_minimum_required (VERSION 3.10)
project (cblackjack)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

add_compile_options(
	"-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
	"$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
    
add_subdirectory (src)

enable_testing()

add_subdirectory (test)
