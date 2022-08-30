#include "model.h"

Model::Model(const char *path, const LoadConfguration &lc) : shader(&Shader::default_shader)
{
	load(path, lc);
}

Model::Model(const char *path) : shader(&Shader::default_shader)
{
	load(path);
}

void Model::load(const Mesh2D &m, const Texture &t)
{
	mesh = m;
	texture = t;
}

void Model::load(const char *path)
{
	texture.load(path);

	glm::vec2 left_top;
	glm::vec2 right_bottom;

	int w = texture.getWidth();
	int h = texture.getHeight();

	if (w < h)
	{
		float aspect = (float)h / ((float)w * 2);
		left_top.x = -0.5f;
		left_top.y = aspect;
		right_bottom.x = 0.5f;
		right_bottom.y = -aspect;
	}
	else
	{
		float aspect = (float)w / ((float)h * 2);
		left_top.y = 0.5f;
		left_top.x = -aspect;
		right_bottom.y = -0.5f;
		right_bottom.x = aspect;
	}

	std::vector<Vertex2D> v{
		Vertex2D{glm::vec2(left_top.x, right_bottom.y), glm::vec2(0, 0)},
		Vertex2D{glm::vec2(left_top.x, left_top.y), glm::vec2(0, 1)},
		Vertex2D{glm::vec2(right_bottom.x, left_top.y), glm::vec2(1, 1)},
		Vertex2D{glm::vec2(right_bottom.x, right_bottom.y), glm::vec2(1, 0)},
	};

	std::vector<GLuint> i{
		0,
		1,
		2,
		0,
		2,
		3,
	};
	mesh.load(v, i);
}

void Model::load(const char *path, const LoadConfguration &lc)
{
	texture.load(path, lc.filter);

	std::vector<Vertex2D> v{
		Vertex2D{glm::vec2(lc.left_top.x, lc.right_bottom.y), glm::vec2(0, 0)},
		Vertex2D{glm::vec2(lc.left_top.x, lc.left_top.y), glm::vec2(0, 1)},
		Vertex2D{glm::vec2(lc.right_bottom.x, lc.left_top.y), glm::vec2(1, 1)},
		Vertex2D{glm::vec2(lc.right_bottom.x, lc.right_bottom.y), glm::vec2(1, 0)},
	};

	std::vector<GLuint> i{
		0,
		1,
		2,
		0,
		2,
		3,
	};
	mesh.load(v, i);
}

void Model::draw()
{
	shader->use();
	shader->setMat3x2("m", transform.getMatrix());
	shader->setScalar("tex", 0);

	texture.use(GL_TEXTURE0);

	mesh.draw();
}

Model::~Model()
{
	texture.destroy();
	mesh.destroy();
}