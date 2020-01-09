#version 330 core

layout (location = 0) in vec2 v_pos;
layout (location = 1) in vec2 v_tex;

out vec2 f_tex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * model * vec4(v_pos, 0.0f, 1.0f);
    f_tex = v_tex;
}
