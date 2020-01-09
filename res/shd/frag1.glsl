#version 330 core

out vec4 fragColor;

in vec2 f_tex;

uniform sampler2DArray Texture;
uniform unsigned int texId;
uniform float elapsedTime;
uniform int effect;

void main()
{
    vec2 uv = f_tex;
    vec4 color;

    if(effect == 1)//Scary ghost effect
    {
        uv.x += sin(elapsedTime * 4 + uv.y * 8) * 0.05;
        uv.y += cos(elapsedTime * 3 + uv.x * 0) * 0.05;
        color = 1 - texture(Texture, vec3(uv, texId));
    }

    else if(effect == 2)//Color changing effect
    {
        color = texture(Texture, vec3(uv, texId)) * vec4(0.5f + 0.5f * cos(elapsedTime*2), 0.5f + 0.5f * sin(elapsedTime*2), 1.0f, 1.0f);
    }

    else//Normal
    {
        color = texture(Texture, vec3(uv, texId));
    }

    fragColor = color;
}
