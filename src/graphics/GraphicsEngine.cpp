//
// Created by Alfie on 02/01/2025.
//

#include "GraphicsEngine.h"

#include <iostream>
#include <glad/glad.h>

GraphicsEngine::GraphicsEngine()
{
    if (!glfwInit()) return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    window = glfwCreateWindow(640, 480, "Alfie's Window", nullptr, nullptr);
    if (!set_up_glad()) return;

    valid = true;
}


GraphicsEngine::~GraphicsEngine()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}


void GraphicsEngine::start()
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    while (!glfwWindowShouldClose(window))
    {
        update();
    }
}


bool GraphicsEngine::set_up_glad() const
{
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "GLAD failed!\n";
        glfwTerminate();
        return false;
    }

    return true;
}
