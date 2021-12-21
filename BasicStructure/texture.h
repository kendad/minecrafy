#pragma once
//Graphics Library
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//image Library
#include "stb_image.h"

#include <iostream>

class Texture {
public:
	unsigned int texture;
	unsigned int shaderID;
	int textureUnit;
	const char* attributeName;

	Texture(const char* filename,const char* imgType,unsigned int shaderID,int textureUnit,const char* attributeName,bool flipTexture=false) {
		//setting up the variables
		Texture::shaderID = shaderID;
		Texture::textureUnit = textureUnit;
		Texture::attributeName = attributeName;

		//create the texture buffer
		glGenTextures(1,&texture);
		glBindTexture(GL_TEXTURE_2D,texture);
		//1->texture wrapping
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		//2->texture filtering
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		//3->loading the texture
		int width, height, noOfColorChannels;
		if (flipTexture) {
			stbi_set_flip_vertically_on_load(true);
		}
		unsigned char* data = stbi_load(filename,&width,&height,&noOfColorChannels,0);

		//generate the mipmap and texture
		if (data) {
			if (imgType == "JPG") {
				glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			if (imgType == "PNG") {
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
		}
		//free my storage image
		stbi_image_free(data);
	}

	void activateTexture() {
		glActiveTexture(GL_TEXTURE0 + textureUnit);
		glBindTexture(GL_TEXTURE_2D,texture);
	}

	void setUniform() {
		glUniform1i(glGetUniformLocation(shaderID,attributeName),textureUnit);
	}

};
