#file(GLOB_RECURSE Headers CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.h")
#file(GLOB_RECURSE Sources CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")

add_executable(Game main.cpp
        #${Headers}
        #${Sources}
)

# Include necessary directories
#target_include_directories(Game PRIVATE Project)
include_directories(../dependencies/include)

# Add GLFW subdirectory
include_directories(../dependencies/src/glfw-3.4/include)

# Check that OpenGL is present
find_package(OpenGL REQUIRED)

# Add Engine subdirectory
#include_directories(engine)
include_directories(../engine)

# Link GLFW, GLAD, and OpenGL to the target
target_link_libraries(Game glfw glad OpenGL::GL Engine)