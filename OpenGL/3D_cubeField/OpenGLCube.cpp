#include "OpenGLCube.h"

OpenGLCube::OpenGLCube()
{
    //ctor

    float pom[] = {
		// front face
		-1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
		 1.0f, -1.0f,  1.0f, 1.0f, 0.0f,
		 1.0f,  1.0f,  1.0f, 1.0f, 1.0f,
		-1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f,  1.0f, 0.0f, 0.0f,
		 1.0f, -1.0f,  1.0f, 1.0f, 0.0f,

		// back face
		-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
		 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
		 1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
		-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
		 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,

		// left face
		-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f,  1.0f, 1.0f, 0.0f,
		-1.0f,  1.0f,  1.0f, 1.0f, 1.0f,
		-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
		-1.0f, -1.0f,  1.0f, 1.0f, 0.0f,

		// right face
		 1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
		 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
		 1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
		 1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
		 1.0f, -1.0f,  1.0f, 0.0f, 0.0f,
		 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,

		 // top face
		-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
		 1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
		 1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
		-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f,  1.0f,  1.0f, 0.0f, 0.0f,
		 1.0f,  1.0f,  1.0f, 1.0f, 0.0f,

		 // bottom face
		-1.0f, -1.0f,  1.0f, 0.0f, 1.0f,
		 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
		 1.0f, -1.0f,  1.0f, 1.0f, 1.0f,
		-1.0f, -1.0f,  1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
		 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
    };
    for(int i = 0 ; i < 180 ; i++)
    {
        vertices[i] = pom[i];
    }

}

void OpenGLCube::setPosition(float x, float y, float z)
{
    int i;
	for(i = 0 ; i < 180 ; i+= 4)
    {
       vertices[i] +=  x;
       vertices[i+1] +=  y;
       vertices[i+2] +=  z;
       vertices[i+3] +=  1;
    }
}



OpenGLCube::~OpenGLCube()
{
    //dtor
}

