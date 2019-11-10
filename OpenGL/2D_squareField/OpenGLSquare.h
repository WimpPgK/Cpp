#include "GL/glew.h"
#include "GLFW/glfw3.h"


#pragma once
class OpenGLSquare
{
		
	public:
		GLfloat vertices[18];
		OpenGLSquare();
		void setSize(GLfloat a);
		void setScale(GLfloat a);
		void setPosition(GLfloat x, GLfloat y);
		


	
};

