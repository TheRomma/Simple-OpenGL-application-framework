#include "window.h"

window::window(float a_width, float a_height, const char* a_title)
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 3;

    m_width = a_width;
    m_height = a_height;

    m_window.create(sf::VideoMode(a_width, a_height), a_title, sf::Style::Close, settings);
    m_window.setVerticalSyncEnabled(true);
    m_window.setActive(true);

    glewExperimental = GL_TRUE;
    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

window::~window()
{
    m_window.close();
}

void window::swapBuffers()
{
    m_window.display();
}

sf::Window* window::getWindowPtr()
{
    return &m_window;
}

float window::getAspect()
{
    return (float)m_width/(float)m_height;
}
