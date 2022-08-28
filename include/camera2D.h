#pragma once

#include "transform.h"

class Camera2D
{
private:
	glm::mat4 projection;

public:
	Transform transform;

	Camera2D() : projection(1.0f) {}

	void othographic(float left, float right, float bottom, float top, float near = -1.0f, float far = 1.0f);

	const glm::mat4 &getProjection() const { return projection; }
};