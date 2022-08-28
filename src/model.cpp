#include "model.h"

Model::Model(const char* path)
{
	texture.load(path);
}

void Model::draw()
{
	shader->use();
	shader->setMat3("m", transform.getMatrix());

	shader->setScalar("tex", 0);
	texture.use(GL_TEXTURE0);

	mesh.draw();
}