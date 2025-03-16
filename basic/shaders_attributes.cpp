

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)\
		glfwSetWindowShouldClose(window, true);

}



int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/*std::cout << "Hello World C++";
	return 0;*/

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);





	//float vertices[] = {
	//	// positions // colors
	//	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
	//	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
	//	0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top
	//};




	////Process Vertex Buffer Object & vertex array object
	//unsigned int VBO;
	//glGenBuffers(1, &VBO);

	//unsigned int VAO;
	//glGenVertexArrays(1, &VAO);
	//glBindVertexArray(VAO);
	//// 0. Copy our vertices array in a buffer for OpenGL to use
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//// 1. then set the vertex attributes pointers
	////Linking vertex attributes
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	//glEnableVertexAttribArray(1);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);


	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//while (!glfwWindowShouldClose(window))
	//{
	//	processInput(window);

	//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//	glClear(GL_COLOR_BUFFER_BIT);

	//	//glUseProgram(shaderProgram);
	//	glBindVertexArray(VAO);
	//	glDrawArrays(GL_TRIANGLES, 0, 3);


	//	glfwSwapBuffers(window);
	//	glfwPollEvents();
	//}
	 
	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteProgram(shaderProgram);

	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);




	glfwTerminate();
	return 0;

}

