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


Mesh *Mesh::generate_triangle(Vector3<float> const vert1, Vector3<float> const vert2, Vector3<float> const vert3)
{
    auto* out = new Mesh();

    out->vertex_count = 3;
    out->vertices = new Vector3<GLfloat>[] { vert1, vert2, vert3 };

    out->texture_coords = new Vector2<float>[] { Vector2(0.5f, 0.0f), Vector2(1.0f, 1.0f), Vector2(0.0f, 1.0f) };

    out->fill_buffer();

    return out;
}


void Mesh::draw() const
{
    glBindVertexArray(array_object);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count * 3);
}


void Mesh::fill_buffer() const
{
    glBindVertexArray(array_object);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_object);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * 3 * sizeof(GLfloat), vertices->get_data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
