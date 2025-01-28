//
// Created by Alfie on 28/01/2025.
//

#include "SceneManager.h"

Scene* SceneManager::current = nullptr;

void SceneManager::set_current(Scene* scene) {
    Scene* old = current;
    current = scene;
    if (old) old->on_unload();
    if (current) current->on_load();
}
