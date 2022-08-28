#pragma once

#include "mesh2D.h"
#include "texture.h"
#include "shader.h"
#include "transform.h"

#include <glm/glm.hpp>

class Model
{
private:
	Mesh2D mesh;
	Texture texture;
	Shader *shader;

public:
	Transform transform;

	Model(const Mesh2D &m, const Texture &t) : mesh(m), texture(t) {}
	Model(const char *path);
	void draw();

	void setShader(Shader *s) { shader = s; }
	void cleanup();
};