#include "texArray.h"

texArray::texArray(const std::string a_filepath, unsigned int a_width, unsigned int a_height)
{
    glGenTextures(1, &m_texArray);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_texArray);

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    std::ifstream file(a_filepath);
    std::string temp_path;
    std::vector<std::string> paths;

    if(file)
    {
        while(file>>temp_path)
        {
            paths.push_back(temp_path);
        }
    }
    else
    {
        std::cerr<<"Failed to generate array texture"<<std::endl;
    }
    file.close();

    glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, GL_RGBA8, a_width, a_height, paths.size());

    for(unsigned int i=0;i<paths.size();i++)
    {
        sf::Image data;
        data.loadFromFile(paths.at(i).c_str());
        data.flipVertically();

        glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, a_width, a_height, 1, GL_RGBA, GL_UNSIGNED_BYTE, data.getPixelsPtr());
    }

    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

texArray::~texArray()
{
    glDeleteTextures(1, &m_texArray);
}

unsigned int texArray::getId()
{
    return m_texArray;
}
