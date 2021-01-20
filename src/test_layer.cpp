#include "test_layer.h"

test_layer::test_layer()
{
    srand(time(NULL));
    m_elapsedTime = 0;

    std::vector<float> quad_vertices =
    {
        -1.0, -1.0, 0.0, 0.0,
        1.0, -1.0, 1.0, 0.0,
        -1.0, 1.0, 0.0, 1.0,

        1.0, 1.0, 1.0, 1.0,
        -1.0, 1.0, 0.0, 1.0,
        1.0, -1.0, 1.0, 0.0
    };

    m_mesh = new mesh(quad_vertices);
    m_shader = new shader("res/shd/vert1.glsl", "res/shd/frag1.glsl");
    m_texArray = new texArray("res/tex/texArrayConfig1", 128, 128);

    glUseProgram(m_shader->getId());
    m_modelLoc = glGetUniformLocation(m_shader->getId(), "model");
    m_viewLoc = glGetUniformLocation(m_shader->getId(), "view");
    m_projLoc = glGetUniformLocation(m_shader->getId(), "proj");
    m_texIdLoc = glGetUniformLocation(m_shader->getId(), "texId");
    m_timeLoc = glGetUniformLocation(m_shader->getId(), "elapsedTime");
    m_effectLoc = glGetUniformLocation(m_shader->getId(), "effect");
    glUseProgram(0);

    m_world = new b2World(b2Vec2(0.0f, -9.81f));

    b2BodyDef groundDef;
    groundDef.position.Set(0.0f, -5.0f);
    m_ground = m_world->CreateBody(&groundDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(20.0f, 1.0f);
    m_ground->CreateFixture(&groundBox, 0.0f);

    m_boxes.push_back(box(glm::vec3(rand()%3 - 1,2,0), glm::vec3(0.5f, 0.5f, 1.0f), m_world, rand()%2 * 3, rand()%3));
    m_boxes.push_back(box(glm::vec3(rand()%3 - 1,4,0), glm::vec3(0.7f, 0.7f, 1.0f), m_world, rand()%2 * 3, rand()%3));
    m_boxes.push_back(box(glm::vec3(rand()%3 - 1,6,0), glm::vec3(0.6f, 0.6f, 1.0f), m_world, rand()%2 * 3, rand()%3));
    m_boxes.push_back(box(glm::vec3(rand()%3 - 1,8,0), glm::vec3(0.4f, 0.4f, 1.0f), m_world, rand()%2 * 3, rand()%3));
    m_boxes.push_back(box(glm::vec3(rand()%3 - 1,10,0), glm::vec3(0.8f, 0.8f, 1.0f), m_world, rand()%2 * 3, rand()%3));
    m_boxes.push_back(box(glm::vec3(rand()%3 - 1,12,0), glm::vec3(0.3f, 0.3f, 1.0f), m_world, rand()%2 * 3, rand()%3));
    m_boxes.push_back(box(glm::vec3(rand()%3 - 1,14,0), glm::vec3(0.9f, 0.9f, 1.0f), m_world, rand()%2 * 3, rand()%3));

    m_buttons.push_back(button(glm::vec3(-14, 7, 0), glm::vec3(1.0f, 1.0f, 1.0f), 6, 0));
    m_buttons.push_back(button(glm::vec3(14, 7, 0), glm::vec3(1.0f, 1.0f, 1.0f), 9, 0));

    m_view = glm::mat4();
    m_proj = glm::mat4();

    m_window = nullptr;

}

test_layer::~test_layer()
{
    delete m_mesh;
    delete m_shader;
    delete m_texArray;

    delete m_world;
}

layer* test_layer::update(float a_delta)
{
    m_elapsedTime += a_delta;

    m_world->Step(a_delta, 8, 3);
    for(unsigned int i=0; i<m_boxes.size(); i++)
    {
        m_boxes[i].update(a_delta);
    }

    if(m_buttons[0].update(a_delta, m_proj * m_view, m_window->getWindowPtr()) == true)
    {
        layer* next = new test_layer();
        delete this;
        return next;
    }
    else if(m_buttons[1].update(a_delta, m_proj * m_view, m_window->getWindowPtr()) == true)
    {
        delete this;
        return nullptr;
    }
    else
    {
        return this;
    }
}

void test_layer::draw(window* a_window)
{
    m_window = a_window;

    glClearColor(0.1f + 0.1f * sin(m_elapsedTime/2 + 0), 0.1f + 0.1f * sin(m_elapsedTime/2 + 2 * 3.14 / 3), 0.1f + 0.1f * sin(m_elapsedTime/2 + 4 * 3.14 / 3), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindVertexArray(m_mesh->getId());
    glUseProgram(m_shader->getId());
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_texArray->getId());

    m_view = glm::lookAt(glm::vec3(0.0f, 0.0f, 100.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    m_proj = glm::perspective(glm::radians(10.0f), a_window->getAspect(), 0.1f, 100.0f);

    glUniformMatrix4fv(m_viewLoc, 1, GL_FALSE, glm::value_ptr(m_view));
    glUniformMatrix4fv(m_projLoc, 1, GL_FALSE, glm::value_ptr(m_proj));
    glUniform1f(m_timeLoc, m_elapsedTime);

    for(unsigned int i=0; i<m_boxes.size(); i++)
    {
        m_boxes[i].draw(m_modelLoc, m_texIdLoc, m_effectLoc);
    }

    m_buttons[0].draw(m_modelLoc, m_texIdLoc, m_effectLoc);
    m_buttons[1].draw(m_modelLoc, m_texIdLoc, m_effectLoc);

    glBindVertexArray(0);
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);

    a_window->swapBuffers();
}
