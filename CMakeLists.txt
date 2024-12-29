cmake_minimum_required(VERSION 3.28)
project(Sandbox)

set(CMAKE_CXX_STANDARD 23)

add_executable(Sandbox main.cpp
        Event/Event.h
        Event/EventListener.h
        Test/ChatEvent.h
        Test/Game.cpp
        Test/Game.h
        Event/EventManager.h
        Core/PriorityQueue.h
        Test/TestListener.cpp
        Test/TestListener.h
        Event/EventPriority.h
)
