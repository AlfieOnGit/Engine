cmake_minimum_required(VERSION 3.28)
project(Engine)

set(CMAKE_CXX_STANDARD 23)

include_directories(Dependencies/Apple/include)
link_directories(Dependencies/Apple/lib)

add_executable(Engine main.cpp
        Dependencies/Apple/src/glad.c
        src/Core/PriorityQueue.h
        src/Event/CancellableEvent.h
        src/Event/Event.h
        src/Event/EventListener.h
        src/Event/EventManager.h
        src/Event/EventPriority.h
        src/Graphics/Shader.cpp
        src/Graphics/Shader.h
        Test/Event/ChatEvent.h
        Test/Event/Game.cpp
        Test/Event/Game.h
        Test/Event/TestListener.cpp
        Test/Event/TestListener.h
        src/Graphics/Mesh.cpp
        src/Graphics/Mesh.h
        src/Core/Vector.h
        src/Graphics/2D/GraphicsEngine2D.cpp
        src/Graphics/2D/GraphicsEngine2D.h
        src/Graphics/GraphicsEngine.cpp
        src/Graphics/GraphicsEngine.h
)

#include_directories(Dependencies/Apple/include)
add_subdirectory(Dependencies/src/glfw-3.4)
#find_package(glfw3 3.4 REQUIRED)
target_link_libraries(Engine glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(Engine OpenGL::GL)

#if (WIN32)
#    message("You're using Windows!")
#endif ()

#if (APPLE)
#    include_directories(Dependencies/Apple/include)
#    find_package(glfw3 3.4 REQUIRED)
#    target_link_libraries(Engine glfw)
#
#    find_package(OpenGL REQUIRED)
#    target_link_libraries(Engine OpenGL::GL)
#endif ()
