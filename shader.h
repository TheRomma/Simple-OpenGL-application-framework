#pragma once

#include <GL/glew.h>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

class shader
{
public:
    shader(const std::string a_vertexPath, const std::string a_fragmentPath);
    ~shader();
    unsigned int getId();
private:
    unsigned int createProg(const char* a_vertexSource, const char* a_fragmentSource);
    std::string loadSource(const std::string a_filepath);
    unsigned int m_shader;
};
