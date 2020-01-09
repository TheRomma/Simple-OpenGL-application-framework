#include "animation.h"

animation::animation(std::vector<unsigned int> a_swapChain, float a_frameTime)
{
    m_swapChain = a_swapChain;
    m_frameTime = a_frameTime;
    m_index = 0;
    m_timer = 0;
}

animation::~animation()
{

}

void animation::update(float a_delta)
{
    m_timer += a_delta;
    if(m_timer > m_frameTime)
    {
        m_index ++;
        if(m_index == m_swapChain.size())
        {
            m_index = 0;
        }
        m_timer = 0;
    }
}

unsigned int animation::getCurrentId()
{
    return m_swapChain[m_index];
}
