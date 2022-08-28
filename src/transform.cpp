#include "transform.h"

void Transform::translate(const glm::vec2 &v)
{
    position += glm::vec2(glm::dot(rotation[0], v), glm::dot(rotation[1], v));
}

void Transform::rotate(float angle)
{
    glm::mat2 r;
    float s = std::sin(angle);
    float c = std::cos(angle);
    r = glm::mat2(c, -s, s, c);

    rotation = r * rotation;
}

void Transform::setRotation(float angle)
{
    float s = std::sin(angle);
    float c = std::cos(angle);
    rotation = glm::mat2(c, -s, s, c);
}

void Transform::scale(const glm::vec2 &v)
{
    rotation[0] *= v.x;
    rotation[1] *= v.y;
}
