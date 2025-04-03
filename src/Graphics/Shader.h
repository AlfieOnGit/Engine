//
// Created by Alfie on 01/01/2025.
//

#ifndef SHADER_H
#define SHADER_H

#define SHADERDIR "../Shaders/"

#include <glad/glad.h>
#include <string>

class Shader
{
public:
    Shader(const std::string& vertex_source, const std::string& fragment_source);
    ~Shader();

    [[nodiscard]] GLuint get_program() const { return program; }
    [[nodiscard]] bool is_valid() const { return valid == GL_TRUE; }

protected:
    GLuint program;
    GLuint vertex_shader, fragment_shader;
    GLint valid = GL_FALSE;

    static bool get_source_from_file(const std::string& file_name, std::string& into);
};

#endif //SHADER_H
