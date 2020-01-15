#pragma once

#include "mesh.h"
#include "shader.h"
#include "texArray.h"
#include "window.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class layer
{
public:
    virtual ~layer(){};
    virtual layer* update(float a_delta) = 0;
    virtual void draw(window* a_window) = 0;
};
