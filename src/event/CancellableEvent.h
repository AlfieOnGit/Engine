//
// Created by Alfie on 30/12/2024.
//

#ifndef CANCELLABLEEVENT_H
#define CANCELLABLEEVENT_H
#include "Event.h"

/**
 * Base class for events that can be cancelled.
 *
 * To cancel an event, listeners should use set_cancelled() at an appropriate priority. Listeners should check whether
 * CancellableEvents have been cancelled before acting on them, ideally using the MONITOR priority (since events can
 * be cancelled by a later priority listener).
 *
 * If you call a cancellable event, you NEED to check if the event has been cancelled before acting on it, it is not
 * handled automatically.
 */
class CancellableEvent : public Event
{
public:
    /**
     * Sets whether the event should be cancelled. This MAY be changed by a later event. Use a MONITOR priority event
     * to be certain
     */
    void set_cancelled(bool const cancelled) { this->cancelled = cancelled; }

    /**
     * Checks whether the event has already been cancelled. Events may still be cancelled later. To be certain, use
     * the MONITOR priority when registering your listener.
     * @return TRUE if currently cancelled, FALSE otherwise
     */
    [[nodiscard]]
    bool is_cancelled() const { return cancelled; }

protected:
    bool cancelled = false;
};

#endif //CANCELLABLEEVENT_H
