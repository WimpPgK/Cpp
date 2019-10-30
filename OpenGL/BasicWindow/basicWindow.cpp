#include<iostream>

#include<glew.h> // ta musi byc przed glfw3.h
#include<glfw3.h>
#include<glm.hpp>


using namespace std;

int main()
{

		//INIT GLFW
		glfwInit();

		//CREATE WINDOW
		const int WINDOW_WIDTH = 640;
		const int WINDOW_HEIGHT = 480;
		int framebufferWidth = 0;
		int framebufferHeight = 0;

		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MAC OS

		GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "YOUTUBE_TUTORIAL", NULL, NULL);

		glfwGetFramebufferSize(window, &framebufferWidth , &framebufferHeight);
		//IMPORTANT WHITH PERSPECTIVE MATRIX!!!
		//glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
		//glViewport(0, 0, framebufferWidth, framebufferHeight);

		glfwMakeContextCurrent(window); //IMPORTANT!!

		//INIT GLEW (NEEDS WINDOW AND OPENGL CONTEXT)
		glewExperimental = GL_TRUE;

		//Error
		if (glewInit() != GLEW_OK)
		{
			std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << "\n";
			glfwTerminate();
		}

		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();

			glClearColor(1.f, 0.f, 0.f, 1.f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			


			glfwSwapBuffers(window);
			glFlush();
		}
		return 0;
}