cmake_minimum_required(VERSION 3.28)
project(Engine)

set(CMAKE_CXX_STANDARD 23)

include_directories(dependencies/include)

add_executable(Engine main.cpp
        dependencies/src/glad/glad.c
        src/core/PriorityQueue.h
        src/event/CancellableEvent.h
        src/event/Event.h
        src/event/EventListener.h
        src/event/EventManager.h
        src/event/EventPriority.h
        src/graphics/Shader.cpp
        src/graphics/Shader.h
        test/event/ChatEvent.h
        test/event/Game.cpp
        test/event/Game.h
        test/event/TestListener.cpp
        test/event/TestListener.h
        src/graphics/Mesh.cpp
        src/graphics/Mesh.h
        src/core/Vector.h
        src/graphics/2D/GraphicsEngine2D.cpp
        src/graphics/2D/GraphicsEngine2D.h
        src/graphics/GraphicsEngine.cpp
        src/graphics/GraphicsEngine.h
        src/scene/Scene.h
        src/scene/SceneManager.cpp
        src/scene/SceneManager.h
)

add_subdirectory(dependencies/src/glfw-3.4)
target_link_libraries(Engine glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(Engine OpenGL::GL)
