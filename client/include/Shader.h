#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

#include "Debug.h"
#include "Memory.h"

#define VERTEX_SHADER_EXTENSION ".vs"
#define FRAGMENT_SHADER_EXTENSION ".ps"

#define VERTEX_SHADER_ERROR                               \
    #version 330                                          \
                                                          \
        in vec3 position;                                 \
                                                          \
    uniform mat4 worldMatrix;                             \
    uniform mat4 viewMatrix;                              \
    uniform mat4 projectionMatrix;                        \
                                                          \
    void                                                  \
    main()                                                \
    {                                                     \
        gl_position = worldMatrix * vec4(position, 1.0f); \
        gl_position = worldMatrix * gl_position;          \
        gl_position = worldMatrix * gl_position;          \
    }

#define FRAGMENT_SHADER_ERROR                   \
    #version 330                               \
                                               \
        out vec4 outColor;                     \
                                               \
    void main(void)                            \
    {                                          \
        outColor = vec4(1.0, 1.0, 0.0f, 1.0f); \
    }

#define WORDL_MATRIX_SHADER             "worldMatrix"
#define VIEW_MATRIX_SHADER              "viewMatrix"
#define PROJECTION_MATRIX_SHADER        "projectionMatrix"

class Shader
{
  public:
  private:
    GLuint m_program;
    std::string m_name;
};