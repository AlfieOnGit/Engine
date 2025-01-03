//
// Created by Alfie on 02/01/2025.
//

#ifndef GRAPHICSENGINE2D_H
#define GRAPHICSENGINE2D_H

#include <vector>

#include "../GraphicsEngine.h"
#include "../Mesh.h"
#include "../Shader.h"

class GraphicsEngine2D : public GraphicsEngine {
public:
    GraphicsEngine2D();
    ~GraphicsEngine2D() override;

    void update() override;

    void add_mesh(Mesh* mesh) { objects.push_back(mesh); }

protected:
    std::vector<Mesh*> objects;

    Shader* shader;
};

#endif //GRAPHICSENGINE2D_H
