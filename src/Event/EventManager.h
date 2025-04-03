//
// Contributors: Alfie
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Event.h"
#include "EventListener.h"
#include "EventPriority.h"
#include "../Core/PriorityQueue.h"

using namespace std;

#define QUEUE PriorityQueue<EventListener<E>*>

class EventManager
{
public:
    template <EventType E> static void call(E* e);
    template <EventType E> static void register_listener(EventListener<E>* listener, EventPriority priority = NORMAL);

protected:
    template <EventType E> static QUEUE listeners;
};


template <EventType E> QUEUE EventManager::listeners = QUEUE(EARLY);


template<EventType E>
void EventManager::call(E *e)
{
    for (int i = 0; i < listeners<E>.get_length(); i++) listeners<E>[i]->on_event(e);
}


template<EventType E>
void EventManager::register_listener(EventListener<E> *listener, EventPriority priority)
{
    listeners<E>.add(listener, priority);
}

#endif //EVENTHANDLER_H
