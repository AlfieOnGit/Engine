//
// Created by Alfie on 28/01/2025.
//

#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <string>

#include "scene/Scene.h"

class TestScene final : public Scene {
public:
    explicit TestScene(std::string const& message) { this->message = message; }

    void on_load() override;
    void update(float dt) override;
    void on_unload() override;

    [[nodiscard]]
    std::string get_message() { return message; }

protected:
    std::string message;
};

#endif //TESTSCENE_H
