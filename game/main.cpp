#include <iostream>

#include "../test/event/Game.h"
#include "core/Matrix.h"
#include "graphics/3D/Renderer.h"

int main()
{
    auto engine = Renderer();

    if (!engine.is_valid())
    {
        std::cout << "Engine invalid!\n";
        return -1;
    }

    // Red triangle
    //Mesh* triangle = Mesh::generate_triangle( // Orthographic example
    //    Vector3<float>(-320.0f, -240.0f, -5.0f),
    //    Vector3<float>(320.0f, -240.0f, -5.0f),
    //    Vector3<float>(0.0f,  240.0f, -5.0f));
    Mesh* triangle = Mesh::generate_triangle( // Perspective example
        Vector3<float>(-0.5f, -0.5f, 0.0f), // Lower left corner
        Vector3<float>(0.5f, -0.5f, 0.0f), // Lower right corner
        Vector3<float>(0.0f, 0.5f, 0.0f)); // Top middle corner
    triangle->set_colour(Vectors::axis<float, 3>(x) << 0.5f);
    //triangle->set_colour(Vector4<float>(1.0f, 0.0f, 0.0f, 0.5f));


    //auto* obj = new GameObject();
    //obj->set_mesh(triangle);
    //obj->get_transform().set_displacement(Vector3<float>(-1.0f, 0.0f, 0.0f));
    //obj->get_transform().set_orientation(Quaternion(0,0,-0.38268, 0.92388));
    //engine.add_object(obj);

    auto* obj1 = new GameObject();
    obj1->set_mesh(triangle);
    obj1->get_transform().set_displacement(Vector3<float>(0.0f, 0.0f, -5.0f));
    //obj1->get_transform().set_displacement(Vector3<float>(-0.5f, 0.0f, 0.0f));
    engine.add_object(obj1);

    // Blue triangle
    Mesh* triangle2 = Mesh::generate_triangle(
        Vector3<float>(-0.5f, -0.5f, 0.0f), // Lower left corner
        Vector3<float>(0.5f, -0.5f, 0.0f), // Lower right corner
        Vector3<float>(0.0f, 0.5f, 0.0f)); // Top middle corner
    triangle2->set_colour(Vector4<float>(0.0f, 0.0f, 1.0f, 1.0f));

    auto* obj2 = new GameObject();
    obj2->set_mesh(triangle2);
    obj2->get_transform().set_displacement(Vector3<float>(0.0f, 0.0f, -10.0f));
    obj2->get_transform().set_scale(Vector3<float>(2.0f, 2.0f, 2.0f));
    engine.add_object(obj2);

    engine.start();

    return 0;
}
