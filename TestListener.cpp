//
// Created by Alfie on 24/12/2024.
//

#include "TestListener.h"

#include <iostream>

void TestListener::on_event(ChatEvent *e) {
    std::cout << "Test class called!\n";
}
