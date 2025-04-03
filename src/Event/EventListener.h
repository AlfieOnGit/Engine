//
// Contributors: Alfie
//

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

template <EventType E> class EventListener
{
public:
    virtual ~EventListener() = default;
    virtual void on_event(E* e) = 0;
};

#endif //EVENTLISTENER_H
