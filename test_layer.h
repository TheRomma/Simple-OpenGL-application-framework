#pragma once

#include "layer.h"
#include <Box2D/Box2D.h>

#include "box.h"
#include "button.h"

#include <iostream>

class test_layer : public layer
{
public:
    test_layer();
    ~test_layer();
    layer* update(float a_delta);
    void draw(window* a_window);
private:
    mesh* m_mesh;
    shader* m_shader;
    texArray* m_texArray;
    int* m_x;
    window* m_window;

    unsigned int m_modelLoc, m_viewLoc, m_projLoc, m_texIdLoc, m_timeLoc, m_effectLoc;

    b2World* m_world;
    b2Body* m_ground;
    std::vector<box> m_boxes;
    std::vector<button> m_buttons;
    float m_elapsedTime;

    glm::mat4 m_view;
    glm::mat4 m_proj;
};
