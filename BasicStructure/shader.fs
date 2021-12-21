#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 TextCoord;

uniform vec4 ourColor;

//uniform textures
uniform sampler2D texture1;
uniform sampler2D texture2;

void main(){
	//FragColor=vec4(vertexColor,1.0);
	//FragColor=ourColor;
	//FragColor=texture(texture1,TextCoord);
	FragColor=mix(texture(texture1,TextCoord),texture(texture2,TextCoord),0.2);
}