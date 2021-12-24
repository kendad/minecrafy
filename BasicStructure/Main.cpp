//Graphics Library
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Math Library
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//image Library
#include "stb_image.h"

#include <iostream>

//custom
#include "shader.h"
#include "texture.h"
#include "vertex_buffer.h"
#include "camera.h"
#include "mesh_type.h"
#include "world_generator.h"
#include "perlin_noise.h"

//Perlin Noise
PerlinNoise perlinNoise;
//chunk generator
ChunkGenerator chunkGenerator;
VertexBuffer* vertexBufferObject;

//function template defined here
void call_on_window_resize(GLFWwindow* window,int width,int height);//called on every window resized
void processInput(GLFWwindow* window);//processes User Input

//basic screen setting
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//All Matrix Intialization
glm::mat4 projection = glm::perspective(glm::radians(45.0f),(float)SCR_WIDTH/(float)SCR_HEIGHT,0.1f,100.0f);//->ProjectionMatrix

//Camera
Camera camera((float)SCR_WIDTH, (float)SCR_HEIGHT);
float deltaTime = 0.0f;
float lastFrame = 0.0f;

//World Generator
WorldGenerator worldGenerator;

int main() {
	//init glfw
	glfwInit();
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH,SCR_HEIGHT,"BasicStructure",NULL,NULL);
	if (window == NULL) {
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window,call_on_window_resize);
	glfwSetCursorPosCallback(window,camera.mcPtr);

	//hide the cursor
	glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);

	//initalize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to intialize GLAD" << std::endl;
		return -1;
	}

	//Initializing the Shader
	Shader ourShader("shader.vs","shader.fs");

	//describing our mesh here
	float vertices[] = {
		// positions          // colors           // texture coords
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};
	//#######################################################################################
	//creating the VBO...EBO and then using the VAO
	VertexBuffer bufferObject(&indices);
	vertexBufferObject = &bufferObject;

	//creating the texture
	Texture texture1("minecraft.png", "PNG", ourShader.ID, 1, "texture2", true);
	//activate the texture
	texture1.activateTexture();
	//#######################################################################################


	//In case you are using the uniform varibales in shaders
	int ourColorLocation = glGetUniformLocation(ourShader.ID,"ourColor");
	int modelLoc = glGetUniformLocation(ourShader.ID, "model");
	int viewLoc = glGetUniformLocation(ourShader.ID, "view");
	int projectionLoc = glGetUniformLocation(ourShader.ID,"projection");
	int eyePosLoc = glGetUniformLocation(ourShader.ID,"eyePos");

	//activate the depth buffer
	glEnable(GL_DEPTH_TEST);
	//activate face culling
	glEnable(GL_CULL_FACE);
	//render loop
	while (!glfwWindowShouldClose(window)) {
		//process the user input
		processInput(window);

		//calculate delta Time
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		camera.processInput(window,deltaTime);

		//clear the window with a certain color
		glClearColor(0.2f,0.3f,0.3f,1.0f);//setting window fill color
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//filling the buffer with that color

		//activate the shader to use
		ourShader.use();

		////setting the uniform values only after we have activated the shader
		glUniform4f(ourColorLocation, 0.0f, 1.0f, 0.0f, 1.0f);
		texture1.setUniform();
		glm::mat4 view = camera.viewMatrix();
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projectionLoc,1,GL_FALSE,glm::value_ptr(projection));
		glUniform3fv(eyePosLoc,1,glm::value_ptr(camera.cameraPos));

		//Activate the VAO
		//glBindVertexArray(VAO);
		glBindVertexArray(bufferObject.VAO);

		//Draw first cube
		worldGenerator.draw(&modelLoc);

		//swap the buffer
		glfwSwapBuffers(window);
		//listen to user input
		glfwPollEvents();
	}

	//terminate the program when once the render loop closes
	glfwTerminate();
	return 0;
}


//functions defined here
void call_on_window_resize(GLFWwindow* window,int height,int width) {
	glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		perlinNoise.updateSeed();
		perlinNoise.updatePerlinNoise();
		chunkGenerator.generate_mesh_by_perlin_noise();
		vertexBufferObject->clearBuffer();
		vertexBufferObject->generateBuffer();
	}
	 //update the scaling factor
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
		if (perlinNoise.fScalingBias < 2.8) perlinNoise.fScalingBias += 0.2;
		perlinNoise.updatePerlinNoise();
		chunkGenerator.generate_mesh_by_perlin_noise();
		vertexBufferObject->clearBuffer();
		vertexBufferObject->generateBuffer();
	}
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) {
		if (perlinNoise.fScalingBias > 0.2) perlinNoise.fScalingBias -= 0.2;
		perlinNoise.updatePerlinNoise();
		chunkGenerator.generate_mesh_by_perlin_noise();
		vertexBufferObject->clearBuffer();
		vertexBufferObject->generateBuffer();
	}
}
