# target_include_directories (Hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES card.c)
#file(GLOB SOURCE_FILES *.c)

add_library(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

add_executable(${CMAKE_PROJECT_NAME}_main main.c)
target_link_libraries(${CMAKE_PROJECT_NAME}_main ${CMAKE_PROJECT_NAME})
