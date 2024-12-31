cmake_minimum_required(VERSION 3.28)
project(Engine)

set(CMAKE_CXX_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR}/Dependencies/include)
link_directories(${PROJECT_SOURCE_DIR}/Dependencies/lib)

add_executable(Engine main.cpp
        Event/Event.h
        Event/EventListener.h
        Test/Event/ChatEvent.h
        Test/Event/Game.cpp
        Test/Event/Game.h
        Event/EventManager.h
        Core/PriorityQueue.h
        Test/Event/TestListener.cpp
        Test/Event/TestListener.h
        Event/EventPriority.h
        Event/CancellableEvent.h
)

include_directories(Dependencies/include)
find_package(glfw3 3.4 REQUIRED)
target_link_libraries(Engine glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(Engine OpenGL::GL)
