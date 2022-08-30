#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 uv;

uniform mat3x2 m;
uniform mat3x2 v;
uniform mat4 p;

mat3x2 get_camear_space(mat3x2 camera, mat3x2 m)
{
    mat2 rot = mat2(camera[0][0], -camera[0][1], -camera[1][0], camera[1][1]) * mat2(m);
    vec2 og = m[2];
    vec2 t = vec2(dot(vec2(rot[0].x, rot[1].x), og), dot(vec2(rot[0].y, rot[1].y), og)) - camera[2];
    return mat3x2(rot[0], rot[1], t);
}

void main() 
{
    gl_Position = p * vec4(get_camear_space(v, m) * vec3(aPos, 1.0f), 0, 1);
    uv = aTexCoord;
}