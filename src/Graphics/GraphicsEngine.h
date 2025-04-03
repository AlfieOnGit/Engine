//
// Contributors: Alfie
//

#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
#include "glad/glad.h" // Your IDE might tell you this isn't necessary but it is
#include <GLFW/glfw3.h>

class GraphicsEngine {
public:
    GraphicsEngine();
    virtual ~GraphicsEngine();

    void start();
    virtual void update() = 0;

    [[nodiscard]] bool is_valid() const { return valid; }

protected:
    GLFWwindow* window = nullptr;
    bool valid = false;

    bool set_up_glad() const;

    static void texture_set_repeating(GLuint texture, bool repeating);
};

#endif //GRAPHICSENGINE_H
