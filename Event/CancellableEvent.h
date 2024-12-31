//
// Created by Alfie Watkins on 30/12/2024.
//

#ifndef CANCELLABLEEVENT_H
#define CANCELLABLEEVENT_H
#include "Event.h"

class CancellableEvent : public Event
{
public:
    void set_cancelled(bool const cancelled) { this->cancelled = cancelled; }
    [[nodiscard]] bool is_cancelled() const { return cancelled; }

private:
    bool cancelled = false;
};

#endif //CANCELLABLEEVENT_H
