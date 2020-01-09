#include "application.h"

application::application(window* a_window, layer* a_layer)
{
    m_running = true;
    m_window = a_window;
    m_layer = a_layer;
    m_layer->init();
    m_time = 0.0f;
}

application::~application()
{
    delete m_layer;
    delete m_window;
}

void application::execute()
{
    while(m_running)
    {
        m_delta = m_clock.getElapsedTime().asSeconds() - m_time;
        m_time = m_clock.getElapsedTime().asSeconds();

        sf::Event event;
        while(m_window->getWindowPtr()->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_running = false;
            }
        }

        m_layer->draw(m_window);

        m_layer = m_layer->update(m_delta);

        if(m_layer == nullptr)
        {
            m_running = false;
        }
    }
}

void application::close()
{
    m_running = false;
}
