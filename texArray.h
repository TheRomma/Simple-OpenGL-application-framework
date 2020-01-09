#pragma once

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <SFML/Graphics/Image.hpp>

class texArray
{
public:
    texArray(const std::string a_filepath, unsigned int a_width, unsigned int a_height);
    ~texArray();
    unsigned int getId();
private:
    unsigned int m_texArray;
};
