//
// Created by Alfie on 20/12/2024.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#define QUEUE PriorityQueue<EventListener<E>*>

#include "EventListener.h"
#include "EventPriority.h"
#include "../core/PriorityQueue.h"

/**
 * A static class that holds pointers to EventListeners and calls their on_event() functions when an Event is called.
 */
class EventManager {
public:
    /**
     * Invokes the on_event() functions of all registered listeners for this event type.
     * @tparam E Event type (child class)
     * @param e Event instance
     */
    template <typename E>
    static void call(E* e);

    template <typename E>
    static void register_listener(EventListener<E>* listener, EventPriority priority = DEFAULT);

    /**
     * Deletes all listeners of a target Event type and clears the listeners vec.
     *
     * Does NOT delete all listeners for EVERY Event type. If you want to do that, you have to keep track of what Event
     * types you've used.
     * @tparam E Event type (child class)
     */
    template <typename E>
    static void delete_event_listeners();

protected:
    template <typename E>
    static QUEUE listeners;
};


template <typename E>
QUEUE EventManager::listeners = QUEUE(EARLY); // EARLY because that's the highest value of the priority enum (i.e. the max)


template<typename E>
void EventManager::call(E* e) {
    for (int i = 0; i < listeners<E>.GetLength(); i++) listeners<E>[i]->OnEvent(e);
}


template<typename E>
void EventManager::register_listener(EventListener<E>* listener, EventPriority priority) {
    listeners<E>.Insert(listener, priority);
}


template<typename E>
void EventManager::delete_event_listeners() {
    for (EventListener<E> const* l : listeners<E>.GetValues()) { delete l; }
    listeners<E>.Clear();
}

#endif //EVENTMANAGER_H
