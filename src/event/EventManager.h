//
// Contributors: Alfie
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#define QUEUE PriorityQueue<EventListener<E>*>

#include "EventListener.h"
#include "EventPriority.h"
#include "../core/PriorityQueue.h"

using namespace std;

/**
 * A static class that holds pointers to EventListeners and calls their OnEvent() functions when an Event is called.
 */
class EventManager
{
public:
    /**
    * Invokes the OnEvent() functions of all registered listeners for this event type.
    * @tparam E Event type (child class)
    * @param e Event instance
    */
    template <EventType E>
    static void call(E* e);

    template <EventType E>
    static void register_listener(EventListener<E>* listener, EventPriority priority = DEFAULT);

protected:
    template <EventType E> static QUEUE listeners;
};


// EARLY because that's the highest value of the priority enum (i.e. the max)
template <EventType E> QUEUE EventManager::listeners = QUEUE(EARLY);


template <EventType E>
void EventManager::call(E *e)
{
    for (int i = 0; i < listeners<E>.get_length(); i++) listeners<E>[i]->on_event(e);
}


template <EventType E>
void EventManager::register_listener(EventListener<E> *listener, EventPriority priority)
{
    listeners<E>.add(listener, priority);
}

#endif //EVENTMANAGER_H
