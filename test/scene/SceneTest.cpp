//
// Created by Alfie on 28/01/2025.
//

#include "TestScene.h"
#include "../../src/scene/SceneManager.h"

namespace SceneTest {

    inline void static_set() {
        auto ts = TestScene("Hello world!");
        SceneManager::set(&ts);
        SceneManager::set_current_to_instance<TestScene>();

        for (int i = 0; i < 5; i++) SceneManager::get_current()->update(static_cast<float>(i));

        SceneManager::set_current(nullptr);
    }
}
