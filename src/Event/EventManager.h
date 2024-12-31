//
// Created by Alfie on 20/12/2024.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "EventListener.h"
#include "EventPriority.h"
#include "../Core/PriorityQueue.h"

using namespace std;

#define QUEUE PriorityQueue<EventListener<E>*>

class EventManager
{
public:
    template <typename E> static void call(E* e);
    template <typename E> static void register_listener(EventListener<E>* listener, EventPriority priority = NORMAL);

protected:
    template <typename E> static QUEUE listeners;
};


template <typename E> QUEUE EventManager::listeners = QUEUE(EARLY);


template<typename E>
void EventManager::call(E *e)
{
    for (int i = 0; i < listeners<E>.get_length(); i++) listeners<E>.get(i)->on_event(e);
}


template<typename E>
void EventManager::register_listener(EventListener<E> *listener, EventPriority priority)
{
    listeners<E>.add(listener, priority);
}

#endif //EVENTHANDLER_H
