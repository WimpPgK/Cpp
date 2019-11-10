#include "SquareMesh.h"
#include "OpenGLSquare.h"
#include <iostream>
using namespace std;

SquareMesh::SquareMesh(int x, int y, float gap)
{
	this->x = x;
	this->y = y;
	this->gap = gap;

	double position_x = 0;
	double position_y = 0;

	vertices = new GLfloat[x * y * 18];
	int i, j, k;
	for (i = 0; i < x; i++)
	{
		
		for (j = 0; j < y; j++)
		{
			
			OpenGLSquare square;
			square.setPosition(position_x, position_y);
			for (k = 0; k < 18; k++)
			{
				vertices[(i * x + j) * 18 + k] = square.vertices[k]+1;
			}
			position_x += (2.0 + gap);
		}
		position_y += (2.0+ gap);
		position_x = 0;
		
		
	}
}

void SquareMesh::printVertices()
{
	int i;
	for (i = 0; i < x * y * 18; i++)
	{
		cout << vertices[i] << endl;
		if ((i + 1) % 3 == 0)
		{
			cout << endl;
		}
	}
}

GLfloat* SquareMesh::getVertices()
{
	return vertices;
}

void SquareMesh::normalizeVertices()
{
	GLfloat max = 0;
	int i;
	for (i=0; i < x * y * 18; i++)
	{
		if (vertices[i] > max)
		{
			max = vertices[i];
		}
	}

	max = max / 2;
	for (i = 0; i < x * y * 18; i++)
	{	
		if ((i + 1) % 3 == 0)
		{
			vertices[i] = 1.0;

		}
		else
		{
			vertices[i] = vertices[i] / max - 1.0;
			
		}
		
	}

}