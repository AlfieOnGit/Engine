//
// Created by Alfie on 28/01/2025.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <vector>

#include "Scene.h"

/**
 * SceneManager is a static class that stores the game's different scenes and dictates the current.
 */
class SceneManager {
public:
    /**
     * Saves a scene object to
     * @param scene
     */
    static void register_scene(const Scene& scene);

    static void set_current(const Scene& scene) { current = get_index(scene); }
    static Scene& get_current() { return scenes[current]; }

    /**
     * Gets a pointer to a registered scene by its index in the scenes vector
     * @param index int index in the scenes vector
     * @return Pointer to target scene
     * @warning Out of bounds indexes will throw vector out of bounds error
     */
    [[nodiscard]] static Scene* get(unsigned int const index) { return &scenes[index]; }

    /**
     * Gets a pointer to a registered scene by its name.
     * @param scene_name String scene name
     * @return Pointer to target scene or NULLPTR if not found
     */
    [[nodiscard]] static Scene* get(const std::pmr::string& scene_name);

    /**
     * Index of current screen in scenes vector
     */
    static int current;

private:
    static std::vector<Scene> scenes;

    /**
     * Returns index of target scene in scenes vector
     * @param scene Target scene
     * @return Target scene or 0 if not found - 0 not -1 to prevent out of range error with scenes vector
     */
    static int get_index(const Scene& scene);
};

#endif //SCENEMANAGER_H