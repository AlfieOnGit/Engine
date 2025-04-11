//
// Contributors: Alfie
//

#include "Camera.h"

void Camera::update(float dt)
{
    // TODO: Replace with better, more abstract, system. Anyway, not gonna do that for a while while I work out graphics
    float constexpr speed = 0.01f;
    auto const turn = Quaternion(0.0f, 0.0043633, 0.0f, 0.9999905);

    auto move = Vector3<float>(); // Change in displacement in this frame

    if (glfwGetKey(window, GLFW_KEY_W)) move[z] -= speed;
    if (glfwGetKey(window, GLFW_KEY_S)) move[z] += speed;
    if (glfwGetKey(window, GLFW_KEY_A)) move[x] -= speed;
    if (glfwGetKey(window, GLFW_KEY_D)) move[x] += speed;
    if (glfwGetKey(window, GLFW_KEY_SPACE)) move[y] += speed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) move[y] -= speed;
    if (glfwGetKey(window, GLFW_KEY_LEFT)) orientation = orientation * turn;
    if (glfwGetKey(window, GLFW_KEY_RIGHT)) orientation = orientation * turn.get_conjugate();

    displacement += orientation * move;
}


Matrix<float, 4, 4> Camera::get_view_matrix() const
{
    return Matrices::rotation(orientation.get_conjugate()) * Matrices::translation(-displacement);
}

