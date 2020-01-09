#include "shader.h"

shader::shader(const std::string a_vertexPath, const std::string a_fragmentPath)
{
    m_shader = createProg(loadSource(a_vertexPath).c_str(), loadSource(a_fragmentPath).c_str());
}

shader::~shader()
{
    glDeleteProgram(m_shader);
}

unsigned int shader::createProg(const GLchar* a_vertexSource, const GLchar* a_fragmentSource)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int shaderProgram = glCreateProgram();

    glShaderSource(vertexShader, 1, &a_vertexSource, nullptr);
    glCompileShader(vertexShader);

    int vertexsuccess;
    char vertexinfoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexsuccess);
    if(!vertexsuccess)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, vertexinfoLog);
        std::cout << "Vertex shader compilation failed: " << vertexinfoLog << std::endl;
    };

    glShaderSource(fragmentShader, 1, &a_fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    int fragmentsuccess;
    char fragmentinfoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentsuccess);
    if(!fragmentsuccess)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentinfoLog);
        std::cout << "Fragment shader compilation failed: " << fragmentinfoLog << std::endl;
    };

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

std::string shader::loadSource(const std::string a_filepath)
{
    std::ifstream file(a_filepath);
    std::stringstream sstream;

    sstream<<file.rdbuf();
    file.close();

    return sstream.str();
}

unsigned int shader::getId()
{
    return m_shader;
}
