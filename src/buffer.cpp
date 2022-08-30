#include "buffer.h"

Buffer::Buffer(GLenum target, GLvoid *arr, GLuint size)
{
	create();
	
	type = target;
	glBindBuffer(type, ID);
	glBufferData(type, size, arr, GL_STATIC_DRAW);
}

void Buffer::set_data(GLenum target, GLvoid *arr, GLuint size)
{
	type = target;
	glBindBuffer(type, ID);
	glBufferData(type, size, arr, GL_STATIC_DRAW);
}

void Buffer::bind()
{
	glBindBuffer(type, ID);
}

void Buffer::unbind()
{
	glBindBuffer(type, 0);
}

void Buffer::destroy()
{
	glDeleteVertexArrays(1, &ID);
}
