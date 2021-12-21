#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>

//SOME GOLBAL VALUES
glm::vec3* cameraFrontPtr;
float* yawPtr;
float* pitchPtr;
float* lastXPtr;
float* lastYPtr;

//function templates
typedef void(*mouseCallbackPtr)(GLFWwindow*, double, double);
void mouseCallback(GLFWwindow* window, double xPos, double yPos);


class Camera {
public:
	glm::vec3 cameraFront;
	glm::vec3 cameraPos;
	glm::vec3 cameraUp;
	glm::mat4 view;

	float yaw;
	float pitch;
	float lastX;
	float lastY;

	//pointing to mouseCallback function
	mouseCallbackPtr mcPtr;

	Camera(float width,float height) {
		yaw = -90.0f;
		pitch = 0.0f;
		lastX = width / 2.0f;
		lastY = height / 2.0f;

		//camera initial values
		cameraFront = glm::vec3(0.0f,0.0f,-1.0f);
		cameraPos = glm::vec3(0.0f,0.0f,40.0f);
		cameraUp = glm::vec3(0.0f,1.0f,0.0f);

		//assigning this values to the ptrs
		cameraFrontPtr = &cameraFront;
		yawPtr = &yaw;
		pitchPtr = &pitch;
		lastXPtr = &lastX;
		lastYPtr = &lastY;

		//assigning value to function pointers
		mcPtr = mouseCallback;
	}

	glm::mat4 viewMatrix() {
		return glm::lookAt(cameraPos,cameraPos+cameraFront,cameraUp);
	}

	void processInput(GLFWwindow* window,float deltaTime) {
		//camera controls
		float cameraSpeed = 20 * deltaTime;
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {//move camera forward
			cameraPos += cameraSpeed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {//move camera backwards
			cameraPos -= cameraSpeed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {//move camera left
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {//move camera right
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}
	}
};

void mouseCallback(GLFWwindow* window, double xPos, double yPos) {
	//configuring the variables

	float xOffset = xPos - *lastXPtr;
	float yOffset = *lastYPtr - yPos;
	*lastXPtr = xPos;
	*lastYPtr = yPos;

	//sensitivity of mouse movements
	float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	*yawPtr += xOffset;
	*pitchPtr += yOffset;

	//limit pitch values
	if (*pitchPtr > 89.0f)
		*pitchPtr = 89.0f;
	if (*pitchPtr < -89.0f)
		*pitchPtr = -89.0f;

	//create the direction vector
	glm::vec3 front;
	front.x = cos(glm::radians(*yawPtr)) * cos(glm::radians(*pitchPtr));
	front.y = sin(glm::radians(*pitchPtr));
	front.z = sin(glm::radians(*yawPtr)) * cos(glm::radians(*pitchPtr));
	*cameraFrontPtr = glm::normalize(front);

	//std::cout <<glm::to_string(*cameraFrontPtr) << std::endl;
}
