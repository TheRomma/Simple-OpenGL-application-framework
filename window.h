#pragma once

#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class window
{
public:
    window(float a_width, float a_height, const char* a_title);
    ~window();
    void swapBuffers();
    sf::Window* getWindowPtr();
    float getAspect();

private:
    sf::Window m_window;
    unsigned int m_width, m_height;
};
