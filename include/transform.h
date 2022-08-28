#pragma once

#include <glm/glm.hpp>

class Transform
{
public:
    glm::mat2 rotation;
    glm::vec2 position;

    void translate(const glm::vec2 &v);
    void rotate(float angle);
    void setRotation(float angle);
    void scale(const glm::vec2 &v);
    void lookAt(const glm::vec2 &target);

    float getRotation();

    glm::mat4 getMatrix() const { return glm::mat4(glm::vec4(rotation[0], 0, 0), glm::vec4(rotation[1], 0, 0), glm::vec4(0, 0, 1, 0), glm::vec4(position, 0, 1)); }

    Transform() : rotation(glm::mat3(1.0f)) {}
};