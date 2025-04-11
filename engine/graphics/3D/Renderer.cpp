//
// Contributors: Alfie
//

#include "Renderer.h"

Renderer::Renderer()
{
    shader = new Shader(SHADERDIR"3DVert.glsl", SHADERDIR"2DFrag.glsl");
    if (!shader->is_valid()) return;

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    auto const flt_width = static_cast<float>(width);
    auto const flt_height = static_cast<float>(height);
    auto constexpr radians = static_cast<float>(45.0f * (M_PI / 180));
    projection_matrix = Matrices::perspective(1.0f, 100.0f, flt_width / flt_height, radians);

    camera = new Camera(*window);
}

void Renderer::update()
{
    camera->update(0.0f);
    view_matrix = camera->get_view_matrix();

    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader->get_program());

    glUniformMatrix4fv(glGetUniformLocation(shader->get_program(), "projection_matrix"),
        1, false, projection_matrix.get_array());
    glUniformMatrix4fv(glGetUniformLocation(shader->get_program(), "view_matrix"),
        1, false, view_matrix.get_array());

    for (GameObject* o : objects)
    {
        Transform& t = o->get_transform();

        auto model_matrix = Matrices::model(t);

        glUniformMatrix4fv(glGetUniformLocation(shader->get_program(), "model_matrix"),
            1, false, model_matrix.get_array());

        glUniform4fv(glGetUniformLocation(shader->get_program(), "colour"),
            1, o->get_mesh()->get_colour().get_array());

        o->get_mesh()->draw();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}
