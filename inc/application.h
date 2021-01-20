#pragma once

#include "window.h"
#include "test_layer.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class application
{
public:
    application(window* a_window, layer* a_layer);
    ~application();
    void execute();
    void close();
private:
    bool m_running;
    float m_delta;
    float m_time;
    sf::Clock m_clock;

    window* m_window;
    layer* m_layer;
};
