//
// Contributors: Alfie
//

#ifndef RENDERER_H
#define RENDERER_H
#include "../GraphicsEngine.h"
#include "../Mesh.h"
#include "../Shader.h"
#include "../../core/Matrix.h"
#include "../../core/PriorityQueue.h"

#define MAX_DEPTH 5

class Renderer final : public GraphicsEngine {
public:
    Renderer();

    void update() override;

private:
    Shader* shader = nullptr;

    PriorityQueue<Mesh*> objects = PriorityQueue<Mesh*>(MAX_DEPTH);

    Matrix<float, 4, 4> projection_matrix, view_matrix;
};

#endif //RENDERER_H
