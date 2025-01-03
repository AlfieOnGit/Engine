//
// Created by Alfie on 02/01/2025.
//

#include "GraphicsEngine2D.h"
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
    for (Mesh* m : objects) m->draw();
    glfwSwapBuffers(window);
    glfwPollEvents();
}

