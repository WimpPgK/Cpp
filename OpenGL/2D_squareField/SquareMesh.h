#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class SquareMesh
{
		int x;
		int y;
		float gap;

		GLfloat* vertices;
	
	public:
		SquareMesh(int, int, float);
		void printVertices();
		void normalizeVertices();
		GLfloat* getVertices();

};

