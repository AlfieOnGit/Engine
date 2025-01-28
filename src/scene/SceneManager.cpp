//
// Created by Alfie on 28/01/2025.
//

#include "SceneManager.h"

int SceneManager::current = 0;

auto scenes = std::pmr::vector<Scene>();


void SceneManager::register_scene(const Scene& scene) {
    if (get(scene.get_name()) == nullptr) scenes.push_back(scene);
}


Scene* SceneManager::get(const std::pmr::string& scene_name) {
    for (Scene& s : scenes) if (s.get_name() == scene_name) return &s;
    return nullptr;
}


int SceneManager::get_index(const Scene& scene) {
    for (int i = 0; i < scenes.size(); i++) {
        if (scenes[i] == scene) return i;
    }
    return -1;
}

