//
// Created by Alfie on 28/01/2025.
//

#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "../../src/scene/Scene.h"

class TestScene final : public Scene {
public:
    TestScene();
    explicit TestScene(const std::pmr::string& unique_name);

    void on_load() override;
    void update(float dt) override;
    void on_unload() override;
};

#endif //TESTSCENE_H
