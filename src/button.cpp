#include "button.h"

button::button(glm::vec3 a_pos, glm::vec3 a_scale, unsigned int a_texId, int a_effect)
{
    m_pos = a_pos;
    m_scale = a_scale;
    m_model = glm::translate(glm::mat4(1.0f), m_pos);
    m_model = glm::scale(m_model, m_scale);

    m_texId = a_texId;
    std::vector<unsigned int> temp_swapChain = {m_texId, m_texId+1, m_texId+2};
    m_animations.push_back(animation(temp_swapChain, 0.1f));

    m_effect = a_effect;

    m_min = glm::vec4(-m_scale.x + m_pos.x, m_scale.y + m_pos.y, 0.0f, 1.0f);
    m_max = glm::vec4(m_scale.x + m_pos.x, -m_scale.y + m_pos.y, 0.0f, 1.0f);
}

button::~button()
{

}

bool button::update(float a_delta, glm::mat4 a_projView, sf::Window* a_window)
{
    m_animations[0].update(a_delta);

    glm::vec2 aabb_min = convertToPixelCoord(m_min, a_projView, glm::vec2(a_window->getSize().x, a_window->getSize().y));
    glm::vec2 aabb_max = convertToPixelCoord(m_max, a_projView, glm::vec2(a_window->getSize().x, a_window->getSize().y));

    glm::vec2 mousePos = glm::vec2(sf::Mouse::getPosition(*a_window).x, sf::Mouse::getPosition(*a_window).y);

    glm::vec2 check1 = aabb_min - mousePos;
    glm::vec2 check2 = mousePos - aabb_max;

    glm::vec2 result = glm::max(check1, check2);


    if(result.x < 0 && result.y < 0)
    {
        m_effect = 3;
        m_model = glm::translate(glm::mat4(1.0f), m_pos);
        m_model = glm::scale(m_model, glm::vec3(1.1f, 1.1f, 1.0f));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        m_effect = 0;
        m_model = glm::translate(glm::mat4(1.0f), m_pos);
        m_model = glm::scale(m_model, m_scale);
        return false;
    }
}

glm::vec2 button::convertToPixelCoord(glm::vec4 a_coord, glm::mat4 a_projView, glm::vec2 a_viewPortSize)
{
    glm::vec4 pixelCoord = a_projView * a_coord;
    pixelCoord.x = (pixelCoord.x/pixelCoord.w + 1) * a_viewPortSize.x * 0.5f;
    pixelCoord.y = (1 - pixelCoord.y/pixelCoord.w) * a_viewPortSize.y * 0.5f;

    return glm::vec2(pixelCoord.x, pixelCoord.y);
}

void button::draw(unsigned int a_modelLoc, unsigned int a_texIdLoc, unsigned int a_effectLoc)
{
    glUniformMatrix4fv(a_modelLoc, 1, GL_FALSE, glm::value_ptr(m_model));
    glUniform1ui(a_texIdLoc, m_animations[0].getCurrentId());
    glUniform1i(a_effectLoc, m_effect);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
