//
// Created by Alfie on 02/01/2025.
//

#include "GraphicsEngine2D.h"

#include <iostream>
#include <string>

GraphicsEngine2D::GraphicsEngine2D()
{
    shader = new Shader(SHADERDIR"2DVert.glsl", SHADERDIR"2DFrag.glsl");
    if (!shader->is_valid()) return;
}


GraphicsEngine2D::~GraphicsEngine2D()
{
    delete shader;
}


void GraphicsEngine2D::update()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader->get_program());
    for (const Mesh* m : objects.get_values())
    {
        glUniform4fv(glGetUniformLocation(shader->get_program(), "colour"),
            1, m->get_colour().get_data());
        m->draw();
    }
    glfwSwapBuffers(window);
    glfwPollEvents();
}

