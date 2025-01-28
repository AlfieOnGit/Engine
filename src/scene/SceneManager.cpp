//
// Created by Alfie on 28/01/2025.
//

#include "SceneManager.h"

int SceneManager::current = 0;

std::pmr::vector<Scene*> SceneManager::scenes = std::pmr::vector<Scene*>();


void SceneManager::register_scene(Scene& scene) {
    if (get(scene.get_name()) != nullptr) return;

    scenes.push_back(&scene);
    if (scenes.size() - 1 == current) scene.on_load();
}


void SceneManager::set_current(const Scene* scene) {
    Scene* old = scenes[current];
    if (*old == *scene) return;
    current = get_index(scene);
    old->on_unload();
    scenes[current]->on_load();
}


Scene* SceneManager::get(const std::pmr::string& scene_name) {
    for (Scene* s : scenes) if (s->get_name() == scene_name) return s;
    return nullptr;
}


int SceneManager::get_index(const Scene* scene) {
    for (int i = 0; i < scenes.size(); i++) {
        if (*scenes[i] == *scene) return i;
    }
    return 0;
}

