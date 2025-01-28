//
// Created by Alfie on 28/01/2025.
//

#include "TestScene.h"

#include <iostream>

TestScene::TestScene() : Scene("TestScene") { }

TestScene::TestScene(const std::pmr::string& unique_name) : Scene(unique_name) { }



void TestScene::on_load() {
    std::cout << name << " loaded!\n";
}


void TestScene::update(float const dt) {
    std::cout << name << " DT: " << dt << '\n';
}


void TestScene::on_unload() {
    std::cout << name << " unloaded!\n";
}


