//
// Contributors: Alfie
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Transform.h"
#include "../graphics/Mesh.h"

/**
 * Temporary GameObject definition to make graphics work
 */
class GameObject
{
public:
    GameObject() = default;

    [[nodiscard]] Mesh* get_mesh() const { return mesh; }
    void set_mesh(Mesh* mesh) { this->mesh = mesh; }

    [[nodiscard]] Transform& get_transform() { return transform; }

protected:
    Mesh* mesh = nullptr;
    Transform transform;
};

#endif //GAMEOBJECT_H
