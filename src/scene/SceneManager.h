//
// Created by Alfie on 28/01/2025.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"

/**
 * SceneManager is a static class that stores the game's different scenes and dictates the current.
 */
class SceneManager {
public:
    /**
     * Changes the current scene to the target Scene and calls on_load() and on_unload() in the new and old current
     * scenes respectively.
     * @param scene Target Scene (or NULLPTR if you want a black screen for some reason)
     */
    static inline void set_current(Scene* scene);

    /**
     * @return Current Scene pointer or NULLPTR if not set
     */
    static Scene* get_current() { return current; }

    /**
     * Sets the static singleton instance of the Scene
     * @tparam S Scene type (child class)
     * @param scene Scene instance
     */
    template <typename S>
    static void set(S* scene) { scene_instance<S> = scene; }

    /**
     * Gets the static singleton instance of the Scene
     * @tparam S Scene type (child class)
     * @return Singleton S instance or NULLPTR if not set
     */
    template <typename S>
    static S* get() { return scene_instance<S>; }

    /**
     * Sets the current Scene pointer to the static singleton instance of a target scene type.
     * @tparam S Target Scene type (child class)
     */
    template <typename S>
    static void set_current_to_instance() { set_current(scene_instance<S>); }

private:
    static Scene* current;

    /**
     * Static singleton instance: Each scene type can store 1 instance (the singleton) in this variable
     * @tparam S Scene type (child class)
     */
    template <typename S>
    static S* scene_instance;
};

template <typename S>
S* SceneManager::scene_instance = nullptr;


void SceneManager::set_current(Scene* scene) {
    Scene* old = current;
    current = scene;
    if (old) old->on_unload();
    if (current) current->on_load();
}

#endif //SCENEMANAGER_H