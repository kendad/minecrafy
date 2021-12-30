#version 330 core

layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aColor;
layout(location=2) in vec2 aTextureCoordinate;
layout(location=3) in vec3 aNormal;

out vec3 vertexColor;
out vec2 TextCoord;
out vec3 Normal;
out vec3 FragPos;

//transformation matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
//gl_Position=vec4(aPos,1.0);
gl_Position=projection*view*model*vec4(aPos,1.0);

//Output to fragment shader
vertexColor=aColor;
TextCoord=aTextureCoordinate;
Normal=aNormal;
FragPos=vec3(model*vec4(aPos,1.0));
}