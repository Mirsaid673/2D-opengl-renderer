#pragma once

#include <GL/glew.h>

class Texture
{
private:
	GLuint ID;
	int width;
	int height;

public:
	Texture() {}
	Texture(const char *file, GLenum filter = GL_LINEAR);

	void load(const char *file, GLenum filter = GL_LINEAR);
	void bind();
	void unbind();
	void use(GLenum unit = GL_TEXTURE0);
	void destroy();

	int getWidth() const {return width;}
	int getHeight() const {return height;}
};