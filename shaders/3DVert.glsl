#version 330 core

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;

in vec3 position;

void main() {
    mat4 mvp = projection_matrix * view_matrix * model_matrix;
    gl_Position = mvp * vec4(position, 1.0);
}