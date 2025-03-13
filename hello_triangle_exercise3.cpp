const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" 
"}\0";

const char* fragmentShaderSourceyellow = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{;\n"
"FragColor = vec4(1.0f, 1.0f, 0f, 1.0f);\n"
"};\n";



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




	//Process VertexShaders
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


	//Get error message
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//process FragmentShader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//get error message for fragmentShader
	int fsuccess;
	char finfoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fsuccess);
	if (!fsuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, finfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

	}
	//TODO -> CREATE A DELEGATE FUNCTION TO AVOID DUPLICATION


	unsigned int fragmentShaderyellow;
	fragmentShaderyellow = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderyellow, 1, &fragmentShaderSourceyellow, NULL);
	glCompileShader(fragmentShaderyellow);

	int fysuccess;
	char finfolog[512];
	glGetShaderiv(fragmentShaderyellow, GL_COMPILE_STATUS, &fysuccess);
	if (!fysuccess)
	{
		glGetShaderInfoLog(fragmentShaderyellow, 512, NULL, finfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

	}


	unsigned int shaderProgram;

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);


	unsigned int shaderProgramyellow;
	shaderProgramyellow = glCreateProgram();

	glAttachShader(shaderProgramyellow, vertexShader);
	glAttachShader(shaderProgramyellow, fragmentShaderyellow);
	glLinkProgram(shaderProgramyellow);


	// check if shader program link has failed
	int psuccess;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &psuccess);
	if (!psuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	}

	//Define coords
	float vertices1[] = {
   -0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0,   0.5f, 0.0f
	};
	float vertices2[] = {
	 0.5f, -0.5f, 0.0f,
	 0.0,   0.5f, 0.0f,
	 1.0f,0.5f,0.0f
	};

	//Process Vertex Buffer Object & verteex array object
	unsigned int VBO1;
	glGenBuffers(1, &VBO1);

	unsigned int VAO1;
	glGenVertexArrays(1, &VAO1);
	glBindVertexArray(VAO1);
	// 0. Copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
	// 1. then set the vertex attributes pointers
	//Linking vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	unsigned int VBO2;
	glGenBuffers(1, &VBO2);

	unsigned int VAO2;
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);
	// 0. Copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	// 1. then set the vertex attributes pointers
	//Linking vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO1);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderProgramyellow);
		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO1);
	glDeleteBuffers(1, &VBO1);
	glDeleteProgram(shaderProgram);

	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);




	glfwTerminate();
	return 0;

}
