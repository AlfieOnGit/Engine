//
// Contributors: Alfie
//

#include "Camera.h"

void Camera::update(float dt)
{
    // TODO: Remove
    // TODO: Movement needs to be based around the orientation of the camera, (I.E. forwards isn't always -Z)
    float constexpr speed = 0.01f;
    auto const turn = Quaternion(0.0f, 0.0043633, 0.0f, 0.9999905);

    if (glfwGetKey(window, GLFW_KEY_W)) displacement[z] -= speed;
    if (glfwGetKey(window, GLFW_KEY_S)) displacement[z] += speed;
    if (glfwGetKey(window, GLFW_KEY_A)) displacement[x] -= speed;
    if (glfwGetKey(window, GLFW_KEY_D)) displacement[x] += speed;
    if (glfwGetKey(window, GLFW_KEY_SPACE)) displacement[y] += speed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) displacement[y] -= speed;
    if (glfwGetKey(window, GLFW_KEY_LEFT)) orientation = orientation * turn.get_conjugate();
    if (glfwGetKey(window, GLFW_KEY_RIGHT)) orientation = orientation * turn;
}


Matrix<float, 4, 4> Camera::get_view_matrix() const
{
    return Matrices::rotation(orientation.get_conjugate()) * Matrices::translation(-displacement);
}

