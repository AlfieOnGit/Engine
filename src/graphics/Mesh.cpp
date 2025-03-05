//
// Contributors: Alfie
//

#include "Mesh.h"

Mesh::Mesh()
{
    glGenVertexArrays(1, &array_object);
    glGenBuffers(1, &buffer_object);
}


Mesh::~Mesh()
{
    delete vertices;
    glDeleteVertexArrays(1, &array_object);
    glDeleteBuffers(1, &buffer_object);
}


// TODO: More ways to generate meshes


Mesh *Mesh::generate_triangle(Vector3<float> vert1, Vector3<float> vert2, Vector3<float> vert3)
{
    auto* out = new Mesh();

    out->vertex_count = 9;
    out->vertices = new GLfloat[9];
    for (int i = 0; i < 3; i++) out->vertices[i] = vert1[i];
    for (int i = 0; i < 3; i++) out->vertices[i + 3] = vert2[i];
    for (int i = 0; i < 3; i++) out->vertices[i + 6] = vert3[i];

    out->fill_buffer();

    return out;
}


void Mesh::draw() const
{
    glBindVertexArray(array_object);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}


void Mesh::fill_buffer() const
{
    glBindVertexArray(array_object);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_object);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
