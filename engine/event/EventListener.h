//
// Contributors: Alfie
//

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "Event.h"

/**
 * An interface that provides an "on_event()" function.
 *
 * To register a class as an event listener, it must inherit EventListener<E> where E is the event type. Then, it must
 * be registered using EventManager::register_listener(). From then on, it will hear whenever the target event is
 * called.
 * @tparam E Event type (child class)
 */
template <EventType E>
class EventListener
{
public:
    virtual ~EventListener() = default;

    /**
    * Function invoked by the Event Manager when an event of the target event type is called.
    * @tparam E Event type class
    * @param e Event instance pointer
    */
    virtual void on_event(E* e) = 0;
};

#endif //EVENTLISTENER_H
