//
// Contributors: Alfie
//

#ifndef RENDERER_H
#define RENDERER_H
#include "../GraphicsEngine.h"
#include "../Shader.h"
#include "../../core/Matrix.h"
#include "../../core/PriorityQueue.h"
#include "../../object/GameObject.h"

#define MAX_DEPTH 5

class Renderer final : public GraphicsEngine {
public:
    Renderer();

    void update() override;

    void add_object(GameObject* object) { objects.push_back(object); }

private:
    Shader* shader = nullptr;

    std::vector<GameObject*> objects;

    Matrix<float, 4, 4> projection_matrix, view_matrix;
};

#endif //RENDERER_H
