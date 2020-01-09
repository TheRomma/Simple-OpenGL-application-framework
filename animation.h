#pragma once

#include <vector>

class animation
{
public:
    animation(std::vector<unsigned int> a_swapChain, float a_frameTime);
    ~animation();
    void update(float a_delta);
    unsigned int getCurrentId();
private:
    float m_timer;
    float m_frameTime;
    unsigned int m_index;
    std::vector<unsigned int> m_swapChain;
};
