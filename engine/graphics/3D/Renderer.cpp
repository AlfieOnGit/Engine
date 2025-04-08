//
// Contributors: Alfie
//

#include "Renderer.h"

Renderer::Renderer()
{
    shader = new Shader(SHADERDIR"3DVert.glsl", SHADERDIR"2DFrag.glsl");
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

    for (GameObject* o : objects)
    {
        Transform& t = o->get_transform();

        auto model_matrix =
            Matrices::translation(t.get_displacement())
            * Matrices::rotation(t.get_orientation())
            * Matrices::scale(t.get_scale());

        glUniformMatrix4fv(glGetUniformLocation(shader->get_program(), "model_matrix"),
            1, false, model_matrix.get_array());

        glUniform4fv(glGetUniformLocation(shader->get_program(), "colour"),
            1, o->get_mesh()->get_colour().get_array());

        o->get_mesh()->draw();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}
