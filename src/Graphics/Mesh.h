//
// Created by Alfie on 02/01/2025.
//

#ifndef MESH_H
#define MESH_H
#include <glad/glad.h>

#include "../Core/Vector.h"

class Mesh {
public:
    Mesh();
    ~Mesh();

    static Mesh* generate_triangle(Vector3<float> vert1, Vector3<float> vert2, Vector3<float> vert3);

    void draw() const;

    void fill_buffer() const;

protected:
    int vertex_count = 0;
    GLfloat* vertices = nullptr;
    GLuint array_object = 0;
    GLuint buffer_object = 0;
};

#endif //MESH_H
