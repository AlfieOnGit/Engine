//
// Contributors: Alfie
//

#include "Renderer.h"

Renderer::Renderer()
{
    shader = new Shader(SHADERDIR"3DVert.glsl", SHADERDIR"3DFrag.glsl");
    if (!shader->is_valid()) return;
}

void Renderer::update()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader->get_program());

    glUniformMatrix4fv(glGetUniformLocation(shader->get_program(), "projection_matrix"),
        1, false, projection_matrix.get_array());
    glUniformMatrix4fv(glGetUniformLocation(shader->get_program(), "view_matrix"),
        1, false, view_matrix.get_array());

    for (const Mesh* m : objects.get_values())
    {

    }
}
