//
// Created by Alfie on 20/12/2024.
//

#include "Game.h"

#include <iostream>

void Game::on_event(ChatEvent* e) {
    std::cout << e->get_message() << '\n';
}
