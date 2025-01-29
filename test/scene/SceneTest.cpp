//
// Created by Alfie on 28/01/2025.
//

#include <iostream>

#include "TestScene.h"
#include "../../src/scene/SceneManager.h"

namespace SceneTest {

    inline void static_set() {
        auto ts = TestScene("Hello");
        SceneManager::set(&ts);
        SceneManager::set_current_to_instance<TestScene>();
        std::cout << "The scene is called: " << SceneManager::get_current()->get_name();
    }
}
