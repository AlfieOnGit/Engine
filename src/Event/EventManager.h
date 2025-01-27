//
// Created by Alfie on 20/12/2024.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "EventListener.h"
#include "EventPriority.h"
#include "../Core/PriorityQueue.h"

using namespace std;

#define QUEUE PriorityQueue<EventListener<E>*>

class EventManager
{
public:
    template <typename E> static void call(E* e);
    template <typename E> static void register_listener(EventListener<E>* listener, EventPriority priority = DEFAULT);

protected:
    template <typename E> static QUEUE listeners;
};


// EARLY because that's the highest value of the priority enum (i.e. the max)
template <typename E> QUEUE EventManager::listeners = QUEUE(EARLY);


template<typename E>
void EventManager::call(E *e)
{
    for (int i = 0; i < listeners<E>.get_length(); i++) listeners<E>[i]->on_event(e);
}


template<typename E>
void EventManager::register_listener(EventListener<E> *listener, EventPriority priority)
{
    listeners<E>.add(listener, priority);
}

#endif //EVENTMANAGER_H
