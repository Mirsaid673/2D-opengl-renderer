#include "camera2D.h"

#include <glm/gtc/matrix_transform.hpp>

void Camera2D::othographic(float left, float right, float bottom, float top, float near, float far)
{
	projection = glm::orthoLH(left, right, bottom, top, near, far);
}