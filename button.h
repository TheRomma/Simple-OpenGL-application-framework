#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h>

#include "animation.h"

#include <SFML/Window.hpp>

#include <iostream>

class button
{
public:
    button(glm::vec3 a_pos, glm::vec3 a_scale, unsigned int a_texId, int a_effect);
    ~button();
    bool update(float a_delta, glm::mat4 a_projView, sf::Window* a_window);
    void draw(unsigned int a_modelLoc, unsigned int a_texIdLoc, unsigned int a_effectLoc);
    glm::vec2 convertToPixelCoord(glm::vec4 a_coord, glm::mat4 a_projView, glm::vec2 a_viewPortSize);
private:
    glm::mat4 m_model;
    glm::vec3 m_pos;
    glm::vec3 m_scale;
    unsigned int m_texId;//Initial texture ID
    int m_effect;//1. Scary ghost effect 2. Color changing effect
    std::vector<animation> m_animations;
    glm::vec4 m_min, m_max;
};
