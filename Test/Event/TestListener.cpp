//
// Contributors: Alfie
//

#include "TestListener.h"

#include <iostream>

void TestListener::on_event(ChatEvent *e)
{
    if (!e->is_cancelled()) std::cout << "Event called! Message: " << e->get_message() << '\n';
    else std::cout << "Event cancelled!\n";
}
