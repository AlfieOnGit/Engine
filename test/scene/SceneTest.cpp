//
// Created by Alfie on 28/01/2025.
//

#include "TestScene.h"
#include "../../src/scene/SceneManager.h"

namespace SceneTest {

    inline void load_and_unload() {
        auto ts = TestScene();
        SceneManager::register_scene(ts);

        auto ts2 = TestScene("Unique name");
        SceneManager::register_scene(ts2);

        for (int i = 0; i < 10; i++) {
            SceneManager::get_current()->update(0.1);
        }

        SceneManager::set_current(SceneManager::get(1));
        for (int i = 0; i < 10; i++) {
            SceneManager::get_current()->update(0.2);
        }
    }
}
