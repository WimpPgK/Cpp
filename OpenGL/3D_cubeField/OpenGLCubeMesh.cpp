#include "FileOperator.h"
#include "OpenGLCube.h"
#include "OpenGLCubeMesh.h"
#include <iostream>

using namespace std;

OpenGLCubeMesh::OpenGLCubeMesh(int x, int y, int z, float gap)
{
    this->x = x;
	this->y = y;
	this->z = z;
	this->gap = gap;

	//std::cout << x <<  "  " << y << "  " << z << std::endl;

	float position_x = 0;
	float position_y = 0;
	float position_z = 0;

	vertices = new float[x * y * z * 180];
	int counter = 0;
	int i, j, k, m = 0;
	for (i = 0; i < x; i++)
	{

		for (j = 0; j < y; j++)
		{
			for (k = 0 ; k <  z ; k++)
            {
                OpenGLCube cube;
                cube.setPosition(position_x, position_y, position_z);

                for (m = 0; m < 180; m++)
                {
                    //cout << "[" << i << "][" <<j << "][" << k <<"]"<< endl;

                    vertices[counter+m] = cube.vertices[m]+1;
                    //vertices[counter+m] = counter+m;
                }
                counter +=180;
                //cout << counter << endl;
                position_x += (2.0 + gap);
            }
            position_y += (2.0+ gap);
            position_x = 0;
		}
		position_z += (2.0+ gap);
		position_y = 0;

	}

}



void OpenGLCubeMesh::printVertices()
{
    int i;
    for(i = 0 ; i < x*y*z*180 ; i++)
    {
        cout << vertices[i] << "  ";
        if((i+1)%4 == 0)
        {
            std::cout << std::endl;
        }
    }
}



void OpenGLCubeMesh::normalizeVertices()
{
    float max = 0;
	int i;
	for (i=0; i < x * y * z * 180; i++)
	{
		if (vertices[i] > max)
		{
			max = vertices[i];
		}
	}

	max = max / 2;
	for (i = 0; i < x * y * z * 180; i+=5)
	{
		
		vertices[i] = vertices[i] / max - 1.0;
		vertices[i+1] = vertices[i+1] / max - 1.0;
		vertices[i+2] = vertices[i+2] / max - 1.0;
		
	}
}


void OpenGLCubeMesh::saveToFile()
{
    FileOperator f1;
    int n = x*y*z*180;
    f1.saveToFile(vertices,n);
}


float* OpenGLCubeMesh::getVertices()
{

    return vertices;

}







OpenGLCubeMesh::~OpenGLCubeMesh()
{
    delete vertices;
}
