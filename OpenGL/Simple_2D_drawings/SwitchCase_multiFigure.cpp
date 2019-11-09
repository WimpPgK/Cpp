/* NOT FINISHED */
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"


using namespace std;

// Global Variables
const char* APP_TITLE = "My basic window ";
const int gWindowWidth = 1200;
const int gWindowHeight = 600;
GLFWwindow* gWindow = NULL;

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
void showFPS(GLFWwindow* window);
bool initOpenGL();
void createSquare(GLfloat* tab, float x, float y, float x_step, float y_step);



const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"void main()"
"{"
"   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";
const GLchar* fragmentShaderSrc =
"#version 330 core\n"
"out vec4 frag_color;"
"void main()"
"{"
"   frag_color = vec4(0.5f, 0.4f, 0.3f, 0.0f);"
"}";






GLfloat* createRandomLines(int n)
{
	srand(time(NULL));
	GLfloat* vertices = new GLfloat[n];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if ((i + 1) % 3 == 0)
		{
			vertices[i] = 1.0f;
		}
		else
		{
			vertices[i] = GLfloat((rand() % 2000) / 1000.0 - 1);

		}
		cout << vertices[i] << endl;

	}
	return vertices;
}

GLfloat* createSimpleTriangle()
{
	GLfloat* vertices = new GLfloat[9];

	vertices[0] = 0.0f;
	vertices[1] = 0.5f;
	vertices[2] = 0.0f;
	vertices[3] = 0.5f;
	vertices[4] = -0.5f;
	vertices[5] = 0.0f;
	vertices[6] = -0.5f;
	vertices[7] = -0.5f;
	vertices[8] = 0.0f;
	return  vertices;
}

GLfloat* create_2d_triangleField(int x, int y)
{
	GLfloat* vertices = new GLfloat[x * y * 18];
	int i,j,k = 0;

	GLfloat x_step = 2 / x;
	GLfloat y_step = 2 / y;
	GLfloat x_distance = 0;
	GLfloat y_distance = 0;
	
	GLfloat* tab_for_square = new GLfloat[18];	
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j+= 18)
		{	
			createSquare(tab_for_square, x_distance, y_distance, x_step, y_step);
			for (k = 0; k < 18; k++)
			{
				vertices[(i * x)*9 + j + k] = tab_for_square[k] -1;
			}
			x_distance += x_step;
		}
		x_distance = 0;
		y_distance += y_step;
	}
	delete tab_for_square;

	return vertices;
}

void createSquare(GLfloat* tab, float x, float y, float x_step, float y_step)
{
	tab[0] = x;
	tab[1] = y;
	tab[2] = 0;
	tab[3] = x + x_step;
	tab[4] = y;
	tab[5] = 0;
	tab[6] = x + x_step;
	tab[7] = y + y_step;
	tab[8] = 0;
	tab[9] = x;
	tab[10] = y;
	tab[11] = 0;
	tab[12] = x + x_step;
	tab[13] = y + y_step;
	tab[14] = 0;
	tab[15] = x;
	tab[16] = y + y_step;
	tab[17] = 0;
}


//-----------------------------------------------------------------------------
// Main Application Entry Point
//-----------------------------------------------------------------------------
int main()
{	
	int n = 999;
	int x = 3;
	int y = 3;
	int choice;
	cin >> choice;
	GLfloat* vertices;
	switch (choice)
	{
		case 1:
			vertices = createSimpleTriangle();
			n = 4;
			break;
		case 2:
			vertices = createRandomLines(n);
			break;
		case 3:
		
			n = x * y * 18;
			vertices = create_2d_triangleField(x, y);
			break;
		default:
			cout << "zjebalo sie";
			return -1;
	}

	/*
	for (int i = 0; i < n; i++)
	{	
		if ((i+1) % 3 == 0)
		{
			cout << endl;
		}
		cout << vertices[i] << endl;

	}
	*/
	if (!initOpenGL())
	{
		cout << "GLFW initialization failed" << endl;
		return false;
	}
	
	
	GLuint vbo, vao;

	glGenBuffers(1, &vbo);					// Generate an empty vertex buffer on the GPU
	glBindBuffer(GL_ARRAY_BUFFER, vbo);		// "bind" or set as the current buffer we are working with
	glBufferData(GL_ARRAY_BUFFER, n*sizeof(GLfloat), vertices, GL_STATIC_DRAW);	// copy the data from CPU to GPU

	glGenVertexArrays(1, &vao);				// Tell OpenGL to create new Vertex Array Object
	glBindVertexArray(vao);					// Make it the current one

	glVertexAttribPointer(
		0,							// Attribute index, "0".  The vertex shader should have layout "0" for the position of the vertex
		3,							// Number of components of attribute "0". In this case 3 floats for x,y,z
		GL_FLOAT,					// The data type of each component
		GL_FALSE,					// Normalize component values to [-1, 1]? No, not for floating point component types
		0,							// Stride, number of bytes between two instances of the attribute in the buffer. This buffer is "Tightly packed"
		NULL);						// Offset inside the structure to find the attribute


	glEnableVertexAttribArray(0);	// Enable the first attribute or attribute "0"

	// 3. Create vertex shader
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexShaderSrc, NULL);
	glCompileShader(vs);

	// Check for compile errors
	GLint result;
	GLchar infoLog[512];
	glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(vs, sizeof(infoLog), NULL, infoLog);
		std::cout << "Error! Vertex shader failed to compile. " << infoLog << std::endl;
	}

	// 4. Create fragment shader
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fs);

	// Check for compile errors
	glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(fs, sizeof(infoLog), NULL, infoLog);
		std::cout << "Error! Fragment shader failed to compile. " << infoLog << std::endl;
	}

	// 5. Create shader program and link shaders to program
	GLint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);
	glLinkProgram(shaderProgram);

	// Check for linker errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
		std::cout << "Error! Shader program linker failure " << infoLog << std::endl;
	}

	// Clean up shaders, do not need them anymore since they are linked to a shader program
	glDeleteShader(vs);
	glDeleteShader(fs);




	// Rendering loop
	while (!glfwWindowShouldClose(gWindow))
	{

		showFPS(gWindow);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);



		// Render the triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(vao);
		glDrawArrays(GL_LINES, 0, n/3);
		glBindVertexArray(0);
		
		glfwSwapBuffers(gWindow);
	}

	// Clean up
	glDeleteProgram(shaderProgram);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

	glfwTerminate();
	return 0;
	
}


bool initOpenGL()
{
	if (!glfwInit())
	{
		cout << "GLFW initialization failed" << endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	gWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, APP_TITLE, NULL, NULL);
	if (gWindow == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(gWindow);
	glfwSetKeyCallback(gWindow, glfw_onKey);


	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed to initialize GLEW" << endl;
		return false;
	}

	glClearColor(0.11f, 0.22f, 0.33f, 1.0f);
	return true;
}

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		cout << "You pressed 1. " << endl;
	}
}

void showFPS(GLFWwindow* window)
{
	static double previousSeconds = 0.0;
	static int frameCount = 0;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime(); // returns number of seconds since GLFW started, as double float

	elapsedSeconds = currentSeconds - previousSeconds;

	// Limit text updates to 4 times per second
	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerFrame = 1000.0 / fps;

		// The C++ way of setting the window title
		std::ostringstream outs;
		outs.precision(3);	// decimal places
		outs << std::fixed
			<< APP_TITLE << "    "
			<< "FPS: " << fps << "    "
			<< "Frame Time: " << msPerFrame << " (ms)";
		glfwSetWindowTitle(window, outs.str().c_str());

		// Reset for next average.
		frameCount = 0;
	}

	frameCount++;
}
