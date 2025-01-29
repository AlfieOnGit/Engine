//
// Created by Alfie on 28/01/2025.
//

#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <string>

#include "../../src/scene/Scene.h"

class TestScene final : public Scene {
public:
    explicit TestScene(std::pmr::string const& message) { this->message = message; }

    void on_load() override;
    void update(float dt) override;
    void on_unload() override;

    [[nodiscard]]
    std::pmr::string get_message() { return message; }

protected:
    std::pmr::string message;
};

#endif //TESTSCENE_H
