#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "mesh_type.h"

class VertexBuffer{
public:
	unsigned int VAO;
	//constructor
	VertexBuffer(unsigned int (*indices)[6]=nullptr) {
		generateBuffer(indices);
	}

	void generateBuffer(unsigned int(*indices)[6] = nullptr) {
		unsigned int VBO;
		unsigned int EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		//bind the VAO first
		glBindVertexArray(VAO);

		//bind the VBO and use it to store data
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vectorVertices.size() * sizeof(Vertex), &vectorVertices[0], GL_STATIC_DRAW);

		//ATTRIBUTE DEFINATIONS
		//telling the GPU how to process the stored data
		//at location 0
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		//at location 1 
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		//at location 2 
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		//at location3
		glVertexAttribPointer(3, 1, GL_INT, GL_FALSE, 6 * sizeof(float), (void*)(5 * sizeof(float)));
		glEnableVertexAttribArray(3);

		//check if EBO is necessary and then create the EBO
		if (indices != nullptr) {
			glGenBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(*indices), *indices, GL_STATIC_DRAW);
		}

		//unbinding everything here
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
};
