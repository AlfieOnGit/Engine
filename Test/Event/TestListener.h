//
// Contributors: Alfie
//

#ifndef TESTLISTENER_H
#define TESTLISTENER_H
#include "ChatEvent.h"
#include "../../src/Event/EventListener.h"

class TestListener : public EventListener<ChatEvent>
{
    void on_event(ChatEvent *e) override;
};

#endif //TESTLISTENER_H
