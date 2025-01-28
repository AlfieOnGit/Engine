//
// Created by Alfie on 28/01/2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <string>

class Scene {
public:
    /**
     * @param name String unique name - Keep them unique or the manager will not understand
     */
    explicit Scene(std::pmr::string const name) { this->name = name; }

    bool operator==(const Scene& second) const { return this->name == second.name; }

    virtual ~Scene() = default;

    /**
     * Called when the scene manager has just changed the current scene to this one.
     */
    virtual void on_load() = 0;

    /**
     * Called every tick this scene is the current scene.
     * @param dt
     */
    virtual void update(float dt) = 0;

    /**
     * Called when the scene manager has just changed the current scene away from this one.
     */
    virtual void on_unload() = 0;

    [[nodiscard]]
    const std::pmr::string& get_name() const { return name; }

protected:
    /**
     * Unique String name ID
     */
    std::pmr::string name;
};

#endif //SCENE_H
