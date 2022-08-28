#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include "camera2D.h"

std::string get_file_contents(const char *filename);

class Shader
{
private:
	GLuint ID;

public:
	Shader(const char *vertexFile, const char *fragmentFile);
	void use();
	void destroy();
	operator GLuint() { return ID; }

	template<typename T>
	void setScalar(const char *name, T value);

	void setVec2(const char *name, float value1, float value2);
	void setVec2(const char *name, float *values);
	void setVec2(const char *name, const glm::vec2 &v);

	void setVec3(const char *name, float value1, float value2, float value3);
	void setVec3(const char *name, float *values);
	void setVec3(const char *name, const glm::vec3 &v);

	void setMat2(const char *name, float *m);
	void setMat2(const char *name, const glm::mat2 &m);

	void setMat3(const char *name, float *m);
	void setMat3(const char *name, const glm::mat3 &m);

	void setMat4(const char *name, float *m);
	void setMat4(const char *name, const glm::mat4 &m);

	void setCamera(const Camera2D& c);

private:
	void compileErrors(unsigned int shader, const char *type);
};