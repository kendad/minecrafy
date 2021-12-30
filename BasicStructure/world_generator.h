#pragma once
//Graphics Library
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Math Library
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>


class Cube {
public:
	bool isActive;
	int blockType;
	int x;
	int y;
	int z;
	Cube(int x=0,int y=0,int z=0){
		isActive = true;
		blockType = 0;
		Cube::x = x;
		Cube::y = y;
		Cube::z = z;
	}
};


class WorldGenerator {
public:
	Cube blocks[1][1][1];
	WorldGenerator() {
		//16x16x16 world of cubes
		for (int x = 0; x < 1; x++) {
			for (int y = 0; y < 1; y++) {
				for (int z = 0; z < 1; z++) {
					Cube cubeObj(x, y, z);
					blocks[x][y][z] = cubeObj;
				}
			}
		}
	}

	void draw(int* modelLoc) {
		//type-1
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f,0.0f,0.0f));
		glUniformMatrix4fv(*modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36*50*50*50);
		////type-2
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -50*0.5*2));
		//glUniformMatrix4fv(*modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 0, 36 * 50 * 50 * 50);
		//////type-3
		//model = glm::translate(model, glm::vec3(50*0.5*2, 0.0f, 0.0f));
		//glUniformMatrix4fv(*modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 0, 36 * 50 * 50 * 50);
		////////type4
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, 50 * 0.5 * 2));
		//glUniformMatrix4fv(*modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		//glDrawArrays(GL_TRIANGLES, 0, 36 * 50 * 50 * 50);
	}

	void drawEditableBlock(int* modelLoc, glm::vec3 cameraPos,glm::vec3 cameraDirection,int objectLocation,float translationX=0.5,float translationY=0.5,float translationZ=0.5) {
		glm::mat4 model = glm::mat4(1.0f);
		//UP =0.5
		model = glm::translate(model, glm::vec3(vectorVertices[objectLocation+35].x+translationX, vectorVertices[objectLocation+35].y+translationY, vectorVertices[objectLocation+35].z+translationZ));
		glUniformMatrix4fv(*modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
};
