#include <iostream>
#include "GLFW/glfw3.h"

int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW failed, oh no!\n";
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "Alfie's Window", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
