//
// Created by Alfie on 20/12/2024.
//

#ifndef CHATEVENT_H
#define CHATEVENT_H
#include <string>

#include "../Event/Event.h"

class ChatEvent : public Event {
public:
    explicit ChatEvent(const std::string& message) { this->message = message; }

    std::string get_message() { return message; }

protected:
    std::string message;
};

#endif //CHATEVENT_H
