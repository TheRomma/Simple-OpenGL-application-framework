#pragma once

#include <GL/glew.h>
#include <vector>

class mesh
{
public:
    mesh(std::vector<float> a_vertices);
    ~mesh();
    unsigned int getId();
private:
    unsigned int m_VAO;
    unsigned int m_VBO;
};
