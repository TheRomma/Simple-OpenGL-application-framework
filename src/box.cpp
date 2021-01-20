#include "box.h"

box::box(glm::vec3 a_pos, glm::vec3 a_scale, b2World* a_world, unsigned int a_texId, int a_effect)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(a_pos.x, a_pos.y);
    m_body = a_world->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(a_scale.x, a_scale.y);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    m_body->CreateFixture(&fixtureDef);

    m_pos = a_pos;
    m_scale = a_scale;
    m_model = glm::translate(glm::mat4(1.0f), m_pos);
    m_model = glm::scale(m_model, m_scale);

    m_texId = a_texId;
    std::vector<unsigned int> temp_swapChain = {m_texId, m_texId+1, m_texId+2};
    m_animations.push_back(animation(temp_swapChain, 0.1f));

    m_effect = a_effect;
}

box::~box()
{

}

void box::update(float a_delta)
{
    m_pos.x = m_body->GetPosition().x;
    m_pos.y = m_body->GetPosition().y;

    m_model = glm::translate(glm::mat4(1.0f), m_pos);
    m_model = glm::rotate(m_model, m_body->GetAngle(), glm::vec3(0.0f, 0.0f, 1.0f));
    m_model = glm::scale(m_model, m_scale);

    m_animations[0].update(a_delta);
}

void box::draw(unsigned int a_modelLoc, unsigned int a_texIdLoc, unsigned int a_effectLoc)
{
    glUniformMatrix4fv(a_modelLoc, 1, GL_FALSE, glm::value_ptr(m_model));
    glUniform1ui(a_texIdLoc, m_animations[0].getCurrentId());
    glUniform1i(a_effectLoc, m_effect);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
