file(GLOB SOURCE_FILES "*.c")

message(${SOURCE_FILES})

## list REMOVE_ITEM Does not work
list(REMOVE_ITEM ${SOURCE_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

add_library(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

add_executable(${CMAKE_PROJECT_NAME}_main main.c)
target_link_libraries(${CMAKE_PROJECT_NAME}_main ${CMAKE_PROJECT_NAME})
