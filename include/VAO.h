#pragma once

#include <GL/glew.h>

class VAO
{
private:
	GLuint ID;

public:
	void create();
	void bind();
	void unbind();
	void destroy();
	void linkAttrib(GLuint layout, GLuint num_components, GLsizeiptr stride, GLvoid *offset);
};