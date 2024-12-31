//
// Created by Alfie on 20/12/2024.
//

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

template <typename E> class EventListener
{
public:
    virtual ~EventListener() = default;
    virtual void on_event(E* e) = 0;
};

#endif //EVENTLISTENER_H
