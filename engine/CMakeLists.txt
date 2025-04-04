file(GLOB_RECURSE Headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE Sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(Engine
    ${Headers}
    ${Sources}
)

# Include necessary directories
include_directories(../dependencies/include)

#target_include_directories(Engine PRIVATE Project)
add_library(glad STATIC ../dependencies/src/glad/glad.c)

# Add GLFW subdirectory
#include_directories(../dependencies/src/glfw-3.4)
#add_subdirectory(../dependencies/src/glfw-3.4)

# Check that OpenGL is present
find_package(OpenGL REQUIRED)

# Link GLFW, GLAD, and OpenGL to the target
target_link_libraries(Engine glfw glad OpenGL::GL)
