#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 TextCoord;
in vec3 Normal;
in vec3 FragPos;

uniform vec4 ourColor;

//uniform textures
uniform sampler2D texture1;//texture_atlas
uniform vec3 eyePos;//cameraPosition

void main(){
//material properties
vec3 ambientProp=vec3( 1.0f,1.0f,1.0f);
vec3 diffuseProp=vec3(1.0f, 0.829f, 0.829f);
vec3 specularProp=vec3(0.296648f, 0.296648f, 0.296648f);
float shininess=11.26f;
vec3 lightPos=vec3(0.0f,50.0f,0.0f);
vec3 lightColor=vec3(0.8f);

//calculating the direction vector
vec3 norm=normalize(Normal);
vec3 lightDir=normalize(lightPos-FragPos);
//calculating diffuse
float diff=max(dot(norm,lightDir),0.0);
vec3 diffuse=(diff*diffuseProp)*lightColor;
//step->creating specular lighting
vec3 viewDir=normalize(eyePos-FragPos);
vec3 reflectDir=reflect(-lightDir,norm);
float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);//32 is the shininess of the highlight..we can change it for diffrent effects
vec3 specular=(specularProp*spec)*lightColor;
//step->creating ambient light
vec3 ambient=(ambientProp)*vec3(1.0);//this vec3 is the light intensity
vec3 resultantColor=ambient+diffuse+specular;



FragColor=texture(texture1,TextCoord)*vec4(resultantColor,1.0);
	
}