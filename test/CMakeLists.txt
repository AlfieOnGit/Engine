file(GLOB_RECURSE Headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE Sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(Test main.cpp
        ${Headers}
        ${Sources}
)

# Include necessary directories
include_directories(../dependencies/include)

# Add GLFW subdirectory
include_directories(../dependencies/src/glfw-3.4/include)

# Check that OpenGL is present
find_package(OpenGL REQUIRED)

# Add Engine subdirectory
include_directories(../engine)

# Link GLFW, GLAD, and OpenGL to the target
target_link_libraries(Test glfw glad OpenGL::GL Engine)