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
	struct LoadConfguration
	{
		glm::vec2 left_top;
		glm::vec2 right_bottom;
		GLint filter = GL_LINEAR;
	};

	Transform transform;

	Model(const Mesh2D &m, const Texture &t) : mesh(m), texture(t), shader(&Shader::default_shader) {}
	Model(const char *path, const LoadConfguration& lc);
	Model(const char *path);
	~Model();

	void draw();

	void setShader(Shader *s) { shader = s; }
	void cleanup();
};