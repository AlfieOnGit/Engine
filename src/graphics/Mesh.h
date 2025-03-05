//
// Contributors: Alfie
//

#ifndef MESH_H
#define MESH_H
#include <glad/glad.h>

#include "../core/Vector.h"

class Mesh {
public:
    Mesh();
    ~Mesh();

    static Mesh* generate_triangle(Vector3<float> vert1, Vector3<float> vert2, Vector3<float> vert3);

    void draw() const;

    void fill_buffer() const;

    void set_colour(Vector4<float> const colour) { this->colour = colour; }
    [[nodiscard]] Vector4<float> get_colour() const { return colour; }

protected:
    int vertex_count = 0;
    GLfloat* vertices = nullptr;
    GLuint array_object = 0;
    GLuint buffer_object = 0;

    Vector4<float> colour = Vector4<float>();
};

#endif //MESH_H
