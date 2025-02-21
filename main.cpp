#include <iostream>

#include "graphics/2D/GraphicsEngine2D.h"

int main()
{
    auto engine = GraphicsEngine2D();

    if (!engine.is_valid())
    {
        std::cout << "Engine invalid!\n";
        return -1;
    }

    // Red triangle
    Mesh* triangle = Mesh::generate_triangle(
        Vector3(-0.5f, -0.5f, 1.0f), // Lower left corner
        Vector3(0.5f, -0.5f, 1.0f), // Lower right corner
        Vector3(0.0f, 0.0f, 1.0f)); // Top middle corner
    triangle->set_colour(Vector4(1.0f, 0.0f, 0.0f, 0.5f));
    engine.add_mesh(triangle, 0);

    // Blue triangle
    Mesh* triangle2 = Mesh::generate_triangle(
        Vector3(-0.5f, 0.5f, 0.0f), // Upper left corner
        Vector3(0.5f, 0.5f, 0.0f), // Upper right corner
        Vector3(0.0f, -0.5f, 0.0f)); // Lower middle corner
    triangle2->set_colour(Vector4(0.0f, 0.0f, 1.0f, 1.0f));
    engine.add_mesh(triangle2, 1);

    engine.start();

    return 0;
}
