#include <iostream>

#include "src/Graphics/2D/GraphicsEngine2D.h"

int main()
{
    auto engine = GraphicsEngine2D();

    if (!engine.is_valid())
    {
        std::cout << "Engine invalid!\n";
        return -1;
    }

    Mesh* triangle = Mesh::generate_triangle(
        Vector3(-0.5f, -0.5f, 0.0f), // Lower left corner
        Vector3(0.5f, -0.5f, 0.0f), // Lower right corner
        Vector3(0.0f, 0.0f, 0.0f)); // Top middle corner
    engine.add_mesh(triangle);

    Mesh* triangle2 = Mesh::generate_triangle(
        Vector3(-0.5f, 0.5f, 0.0f), // Upper left corner
        Vector3(0.5f, 0.5f, 0.0f), // Upper right corner
        Vector3(0.0f, 0.0f, 0.0f)); // Lower middle corner
    engine.add_mesh(triangle2);

    engine.start();

    return 0;
}
