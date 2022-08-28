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

    glm::mat3 getMatrix() const { return glm::mat3(glm::vec3(rotation[0], 0.0f), glm::vec3(rotation[1], 0.0f), glm::vec3(position, 0.0f)); }

    Transform() : rotation(1.0f) {}
};