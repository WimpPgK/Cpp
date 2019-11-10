#include "OpenGLSquare.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"


OpenGLSquare::OpenGLSquare()
{
	vertices[0] = -1;
	vertices[1] = 1;
	vertices[2] = 0;
	
	vertices[3] = 1;
	vertices[4] = 1;
	vertices[5] = 0;
	
	vertices[6] = 1;
	vertices[7] = -1;
	vertices[8] = 0;
	
	vertices[9] = -1;
	vertices[10] = 1;
	vertices[11] = 0;
	
	vertices[12] = 1;
	vertices[13] = -1;
	vertices[14] = 0;
	
	vertices[15] = -1;
	vertices[16] = -1;
	vertices[17] = 0;
}

void OpenGLSquare::setPosition(GLfloat x, GLfloat y)
{
	vertices[0] += x;
	vertices[3] += x;
	vertices[6] += x;
	vertices[9] += x;
	vertices[12] += x;
	vertices[15] += x;

	vertices[1] += y;
	vertices[4] += y;
	vertices[7] += y;
	vertices[10] += y;
	vertices[13] += y;
	vertices[16] += y;

}
