//
// Contributors: Alfie
//

#ifndef GRAPHICSENGINE2D_H
#define GRAPHICSENGINE2D_H

#define MAX_DEPTH 5

#include "../GraphicsEngine.h"
#include "../Mesh.h"
#include "../Shader.h"
#include "../../core/PriorityQueue.h"

class GraphicsEngine2D : public GraphicsEngine {
public:
    GraphicsEngine2D();
    ~GraphicsEngine2D() override;

    void update() override;

    /**
     * Adds a mesh to the "objects" vector, so it'll be rendered each frame
     * @param mesh Mesh object
     * @param depth How far in the background an object is. The higher the number, the further back it is. DEPTH can be
     * a maximum of MAX_DEPTH
     */
    void add_mesh(Mesh* mesh, int const depth) { objects.add(mesh, depth); }

protected:
    PriorityQueue<Mesh*> objects = PriorityQueue<Mesh*>(MAX_DEPTH);

    Shader* shader = nullptr;
};

#endif //GRAPHICSENGINE2D_H
