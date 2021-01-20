#include "mesh.h"

mesh::mesh(std::vector<float> a_vertices)
{
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, a_vertices.size() * sizeof(float), &a_vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)(2*sizeof(float)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

mesh::~mesh()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &m_VAO);
}

unsigned int mesh::getId()
{
    return m_VAO;
}
