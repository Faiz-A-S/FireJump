#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;
layout (location = 3) in vec2 aOffset;

uniform mat4 model;
uniform mat4 projection;
out vec3 ourColor;
out vec2 TexCoord;


void main()
{
    ourColor = color;
    gl_Position = projection * model * vec4(position + aOffset, 0.0f, 1.0f);
    TexCoord = vec2(texCoord.x, texCoord.y);
}
