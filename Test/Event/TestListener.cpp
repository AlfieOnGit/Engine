//
// Created by Alfie on 24/12/2024.
//

#include "TestListener.h"

#include <iostream>

void TestListener::on_event(ChatEvent *e) {
    if (!e->is_cancelled()) std::cout << "Event called! Message: " << e->get_message() << '\n';
    else std::cout << "Event cancelled!\n";
}
