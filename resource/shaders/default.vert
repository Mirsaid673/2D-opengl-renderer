#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 uv;

uniform mat3 m;
uniform mat3 v;
uniform mat4 p;
void main() 
{
    gl_Position = p * mat4(v) * mat4(m) * vec4(aPos, 0.0f, 1.0f);
    
    uv = aTexCoord;
}