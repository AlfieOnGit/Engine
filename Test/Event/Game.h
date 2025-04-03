//
// Contributors: Alfie
//

#ifndef GAME_H
#define GAME_H
#include "ChatEvent.h"
#include "../../src/Event/EventListener.h"


class Game final : public EventListener<ChatEvent>
{
public:
    void on_event(ChatEvent* e) override;
};



#endif //GAME_H
