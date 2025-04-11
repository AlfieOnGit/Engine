//
// Contributors: Alfie
//

#ifndef CAMERA_H
#define CAMERA_H

#include "../core/Matrix.h"
#include "../core/Quaternion.h"
#include "../core/Vector.h"

#include <glad/glad.h> // Your IDE might tell you this isn't necessary but it is
#include "GLFW/glfw3.h"

class Camera {
public:
    explicit Camera(GLFWwindow& window, Vector3<float> const& displacement = Vector3<float>(), Quaternion const& orientation = Quaternion())
        : window(&window), displacement(displacement), orientation(orientation)
    {
        //glfwSetKeyCallback(this->window, Camera::update); // TODO: make this work
    }

    void update(float dt);

    [[nodiscard]] Matrix<float, 4, 4> get_view_matrix() const;

protected:
    GLFWwindow* window;
    Vector3<float> displacement;
    Quaternion orientation;
};

#endif //CAMERA_H
