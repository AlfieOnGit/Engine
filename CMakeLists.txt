cmake_minimum_required(VERSION 3.28)
project(Engine)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE Headers CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE Sources CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(Engine main.cpp
        ${Headers}
        ${Sources}
)

# Share includes with the whole project
include_directories(dependencies/include)

add_library(glad STATIC dependencies/src/glad/glad.c)

# Include necessary directories
target_include_directories(Engine PRIVATE src)

# Add GLFW subdirectory
add_subdirectory(dependencies/src/glfw-3.4)

# Check that OpenGL is present
find_package(OpenGL REQUIRED)

# Link GLFW, GLAD, and OpenGL to the target
target_link_libraries(Engine glfw glad OpenGL::GL)
