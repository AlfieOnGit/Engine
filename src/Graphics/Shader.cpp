//
// Created by Alfie on 01/01/2025.
//

#include<fstream>
#include "Shader.h"

#include <iostream>

Shader::Shader(const std::string& vertex_source, const std::string& fragment_source)
{
    // Fetch the vertex shader code from its file
    std::string vertex_string;
    get_source_from_file(vertex_source, vertex_string);
    const char* vertex_chars = vertex_string.c_str();

    // Create the vertex shader
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_chars, nullptr);
    glCompileShader(vertex_shader);


    // Fetch the fragment shader code from its file
    std::string fragment_string;
    get_source_from_file(fragment_source, fragment_string);
    const char* fragment_chars = fragment_string.c_str();

    // Create the fragment shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_chars, nullptr);
    glCompileShader(fragment_shader);


    // Create the shader program from both shaders
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &valid);


    // Delete now-useless shaders
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}


Shader::~Shader()
{
    glDeleteProgram(program);
}


bool Shader::get_source_from_file(const std::string& file_name, std::string& into)
{
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cout << "File " << file_name << " not found!\n";
        return false;
    }

    std::string line, out;
    while (getline(file, line))
    {
        into += line + '\n';
    }
    return true;
}
