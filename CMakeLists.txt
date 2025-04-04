cmake_minimum_required(VERSION 3.28)
project(Project)

set(CMAKE_CXX_STANDARD 23)

add_compile_definitions(PROJECTDIR="${CMAKE_SOURCE_DIR}")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/game")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/engine")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dependencies/src/glfw-3.4")