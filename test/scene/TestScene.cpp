//
// Created by Alfie on 28/01/2025.
//

#include "TestScene.h"

#include <iostream>

void TestScene::on_load() {
    std::cout <<"Test Scene loaded with message:" << message << '\n';
}


void TestScene::update(float const dt) {
    std::cout << "Test scene DT: " << dt << '\n';
}


void TestScene::on_unload() {
    std::cout << "Test scene unloaded!\n";
}


