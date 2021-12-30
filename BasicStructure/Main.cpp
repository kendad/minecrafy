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
int objectLocation = 0;
bool activateEditableBlock=false;
bool enableEditMode = false;
float translationX = 0.5;
float translationY = 0.5;
float translationZ = 0.5;

//function template defined here
void call_on_window_resize(GLFWwindow* window,int width,int height);//called on every window resized
void processInput(GLFWwindow* window);//processes User Input
void raycast();
float calculateT(glm::vec3 normal,glm::vec3 position);
void transparentBlock();

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
	Shader blockShader("block.vs","block.fs");

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
	VertexBuffer bufferObject(vectorVertices);
	VertexBuffer editableBufferObject(editableVectorVertices);
	vertexBufferObject = &bufferObject;

	//creating the texture
	Texture texture1("minecraft.png", "PNG", ourShader.ID, 1, "texture2", true);
	Texture texture2("minecraft.png", "PNG", blockShader.ID, 2, "texture2", true);
	//activate the texture
	texture1.activateTexture();
	texture2.activateTexture();
	//#######################################################################################


	//In case you are using the uniform varibales in shaders
	int ourColorLocation = glGetUniformLocation(ourShader.ID,"ourColor");
	int modelLoc = glGetUniformLocation(ourShader.ID, "model");
	int viewLoc = glGetUniformLocation(ourShader.ID, "view");
	int projectionLoc = glGetUniformLocation(ourShader.ID,"projection");
	int eyePosLoc = glGetUniformLocation(ourShader.ID,"eyePos");
	int collidedObjectLoc = glGetUniformLocation(ourShader.ID, "collidedObject");
	//uniforms for the editable block
	int ourColorLocation_editableBlock = glGetUniformLocation(blockShader.ID, "ourColor");
	int modelLoc_editableBlock = glGetUniformLocation(blockShader.ID, "model");
	int viewLoc_editableBlock = glGetUniformLocation(blockShader.ID, "view");
	int projectionLoc_editableBlock = glGetUniformLocation(blockShader.ID, "projection");
	int eyePosLoc_editableBlock = glGetUniformLocation(blockShader.ID, "eyePos");
	int collidedObjectLoc_editableBlock = glGetUniformLocation(blockShader.ID, "collidedObject");

	//activate the depth buffer
	glEnable(GL_DEPTH_TEST);
	//activate face culling
	glEnable(GL_CULL_FACE);
	//render loop
	while (!glfwWindowShouldClose(window)) {
		//process the user input
		processInput(window);
		vertexBufferObject->clearBuffer();
		vertexBufferObject->generateBuffer();
		//calculate delta Time
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		camera.processInput(window,deltaTime);

		//clear the window with a certain color
		glClearColor(0.0f,0.0f,0.0f,0.0f);//setting window fill color
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//filling the buffer with that color

		//activate the shader to use
		ourShader.use();

		////setting the uniform values only after we have activated the shader
		glUniform4f(ourColorLocation, 0.3f, 0.3f, 0.3f, 1.0f);
		texture1.setUniform();
		glm::mat4 view = camera.viewMatrix();
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projectionLoc,1,GL_FALSE,glm::value_ptr(projection));
		glUniform3fv(eyePosLoc,1,glm::value_ptr(camera.cameraPos));

		//Activate the VAO
		//glBindVertexArray(VAO);
		glBindVertexArray(bufferObject.VAO);

		//Draw the world
		raycast();
		worldGenerator.draw(&modelLoc);

		//for editable block
		if (activateEditableBlock) {
			blockShader.use();
			texture2.setUniform();
			glUniform4f(ourColorLocation_editableBlock, 0.3f, 0.3f, 0.3f, 1.0f);
			glUniformMatrix4fv(viewLoc_editableBlock, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(projectionLoc_editableBlock, 1, GL_FALSE, glm::value_ptr(projection));
			glUniform3fv(eyePosLoc_editableBlock, 1, glm::value_ptr(camera.cameraPos));
			glBindVertexArray(editableBufferObject.VAO);
			worldGenerator.drawEditableBlock(&modelLoc_editableBlock, camera.cameraPos, camera.cameraFront,objectLocation,translationX,translationY,translationZ);
		}

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
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
		if (activateEditableBlock == false) {
			activateEditableBlock = true;
		}
		else {
			activateEditableBlock = false;
		}
	}

	//translate the editable block commands
	//X
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		if (translationX+=(0.5*3) > vectorVertices[objectLocation+35].x+(0.5 * 3)) {
			translationX = 0.5 * 3;
		}
		else {
			translationX += (0.5 * 3);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		if (translationX-=(0.5*1) < vectorVertices[objectLocation + 35].x - (0.5 * 1)) {
			translationX = -(0.5 * 1);
		}
		else {
			translationX -= (0.5 * 1);
		}
	}
	//Y
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		if (translationY += (0.5 * 1) < vectorVertices[objectLocation + 35].y + (0.5 * 1)) {
			translationY = (0.5 * 1);
		}
		else {
			translationY += (0.5 * 1);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		if (translationY -= (0.5 * 3) < vectorVertices[objectLocation + 35].y - (0.5 * 3)) {
			translationY = -(0.5 * 3);
		}
		else {
			translationY -= (0.5 * 3);
		}
	}
	//Z
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
		if (translationZ -= (0.5 * 1) < vectorVertices[objectLocation + 35].z - (0.5 * 1)) {
			translationZ = -(0.5 * 1);
		}
		else {
			translationZ -= (0.5 * 1);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		if (translationZ += (0.5 * 3) < vectorVertices[objectLocation + 35].z + (0.5 * 1)) {
			translationZ = (0.5 * 3);
		}
		else {
			translationZ += (0.5 * 3);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		enableEditMode = true;
		std::cout << enableEditMode << std::endl;
	}
	if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS) {
		if (enableEditMode == true) {
			for (int i = 0; i < sizeof(plainCube) / sizeof(plainCube[0]); i += 12) {
				Vertex tmpVertex;
				tmpVertex.x = plainCube[i];
				tmpVertex.y = plainCube[i + 1];
				tmpVertex.z = plainCube[i + 2];

				tmpVertex.u = plainCube[i + 3];
				tmpVertex.v = plainCube[i + 4];

				tmpVertex.nx = plainCube[i + 5];
				tmpVertex.ny = plainCube[i + 6];
				tmpVertex.nz = plainCube[i + 7];

				tmpVertex.r = plainCube[i + 8];
				tmpVertex.g = plainCube[i + 9];
				tmpVertex.b = plainCube[i + 10];
				tmpVertex.a = plainCube[i + 11];
				//update the vector vertices
				tmpVertex.x += vectorVertices[objectLocation+35].x+translationX;
				tmpVertex.y += vectorVertices[objectLocation+35].y+translationY;
				tmpVertex.z += vectorVertices[objectLocation+35].z-translationZ;
				vectorVertices.push_back(tmpVertex);
			}
			vertexBufferObject->clearBuffer();
			vertexBufferObject->generateBuffer();
			enableEditMode = false;
		}
	}
}

void nullTransparentBlock() {
	for (int i = 0; i < 36; i++) {
		vectorVertices[objectLocation + i].r = 1.0f;
		vectorVertices[objectLocation + i].g = 1.0f;
		vectorVertices[objectLocation + i].b = 1.0f;
		vectorVertices[objectLocation + i].a = 1.0f;
	}
}

void raycast() {
	glm::vec3 ray = camera.cameraPos + (camera.cameraFront * 3.5);
	for (int i = 0; i < vectorVertices.size(); i += 36) {
		glm::vec3 max = glm::vec3(vectorVertices[i+32].x, vectorVertices[i+32].y, vectorVertices[i+32].z);
		glm::vec3 min = glm::vec3(vectorVertices[i+28].x, vectorVertices[i+28].y, vectorVertices[i+28].z);
		bool condition1 = min.x <= ray.x && ray.x <= max.x;
		bool condition2 = min.y <= ray.y && ray.y <= max.y;
		bool condition3 = max.z <= ray.z && ray.z <= min.z;
		if (condition1 == true && condition2 == true && condition3 == true) {
			nullTransparentBlock();
			objectLocation = i;
			//std::cout << "hit detected at:-> "<<i << std::endl;
			transparentBlock();
		}
	}
}

float calculateT(glm::vec3 normal,glm::vec3 position) {
	glm::vec3 origin = camera.cameraPos;
	glm::vec3 direction = camera.cameraFront;
	float delta = glm::dot(normal,position);
	if (glm::dot(direction, normal) == 0) {//if denominator=0 then no intersection
		return -1.0f;
	}
	float t = ((glm::dot(origin, normal)) + delta) / (glm::dot(direction, normal));
	return t;
}

void transparentBlock() {
	translationX = 0.5;
	translationY = 0.5;
	translationZ = 0.5;
	for (int i = 0; i < 36; i++) {
		vectorVertices[objectLocation+i].r = 0.3f;
		vectorVertices[objectLocation+i].g = 0.3f;
		vectorVertices[objectLocation+i].b = 0.3f;
		vectorVertices[objectLocation+i].a = 1.0f;
	}
}

