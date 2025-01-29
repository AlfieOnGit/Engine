//
// Created by Alfie on 28/01/2025.
//

#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    virtual ~Scene() = default;

    /**
     * Called when the scene manager has just changed the current scene to this one.
     */
    virtual void on_load() { }

    /**
     * Called every tick this scene is the current scene.
     * @param dt
     */
    virtual void update(float dt) { }

    /**
     * Called when the scene manager has just changed the current scene away from this one.
     */
    virtual void on_unload() { }
};

#endif //SCENE_H
