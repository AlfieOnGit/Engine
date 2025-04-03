//
// Contributors: Alfie
//

#include "Game.h"

#include <iostream>

void Game::on_event(ChatEvent* e)
{
    std::cout << "Message: " << e->get_message() << '\n';
    std::cout << "Now cancelling the event!\n";
    e->set_cancelled(true);
}
