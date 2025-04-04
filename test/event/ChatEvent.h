//
// Contributors: Alfie
//

#ifndef CHATEVENT_H
#define CHATEVENT_H
#include <string>

#include "event/Event.h"

class ChatEvent : public CancellableEvent
{
public:
    explicit ChatEvent(const std::string& message) { this->message = message; }

    [[nodiscard]] std::string get_message() const { return message; }

protected:
    std::string message;
};

#endif //CHATEVENT_H
