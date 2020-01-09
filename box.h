#pragma once

#include <Box2D/Box2D.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h>

#include "animation.h"


class box
{
public:
    box(glm::vec3 a_pos, glm::vec3 a_scale, b2World* a_world, unsigned int a_texId, int a_effect);
    ~box();
    void update(float a_delta);
    void draw(unsigned int a_modelLoc, unsigned int a_texIdLoc, unsigned int a_effectLoc);
private:
    b2Body* m_body;
    glm::mat4 m_model;
    glm::vec3 m_pos;
    glm::vec3 m_scale;
    unsigned int m_texId;//Initial texture ID
    int m_effect;//1. Scary ghost effect 2. Color changing effect
    std::vector<animation> m_animations;
};
