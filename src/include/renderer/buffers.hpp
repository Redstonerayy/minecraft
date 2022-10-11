#pragma once

#include <glad/gl.h>
#include <string>
#include <iostream>
#include <vector>
#include "structs.hpp"

// class VBO;
// class EBO;
class VBO {
public:
	unsigned int vboID;
	std::vector<Vertex> vertices;

	VBO(std::vector<Vertex> vertices);

    void bind();
	void fillBuffer();
    void updateBuffer();
};

class EBO {
public:
	unsigned int eboID;
	std::vector<unsigned int> indices;

	EBO(std::vector<unsigned int> indices);

    void bind();
	void fillBuffer();
    void updateBuffer();
};

class VAO {
public:
	unsigned int vaoID;
	VBO* vbo;
	EBO* ebo;
	
	VAO();

	void bind();
	void fill(bool pos, bool tex, bool normal);
    void update();
	void setAttribPointer(int attribID, int length, int type, bool normalized, int stride, int offset);

private:
	unsigned int vboallid;
	unsigned int eboallid;
};
