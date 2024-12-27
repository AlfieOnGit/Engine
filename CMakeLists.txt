cmake_minimum_required(VERSION 3.28)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sandbox main.cpp
        Event/Event.h
        Event/EventListener.h
        ChatEvent.h
        Game.cpp
        Game.h
        Event/EventManager.h
        Core/PriorityQueue.h
        TestListener.cpp
        TestListener.h
        Event/EventPriority.h
)
