//
// Created by Alfie on 20/12/2024.
//

#ifndef GAME_H
#define GAME_H
#include "ChatEvent.h"
#include "../../src/event/EventListener.h"


class Game final : public EventListener<ChatEvent>
{
public:
    void on_event(ChatEvent* e) override;
};



#endif //GAME_H
