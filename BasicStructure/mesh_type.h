#pragma once

#include <vector>
#include "perlin_noise.h"
#include "texture.h"

//Plane Mesh

//Plane Mesh---1
float planeMesh_1[] = {
	// positions          // colors           // texture coords
 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};
unsigned int planeMeshindices_1[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};


//Test Cube 
float TestCube[] = {
    // Back face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right         
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
    // Front face
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
    // Left face
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
    // Right face
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right         
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left     
    // Bottom face
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
    // Top face
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right     
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, // bottom-left

    ////////////////////////////////////////////////
    //test the face here
    // Back face
    -0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 0.0f, // Bottom-left
     0.5f, -0.5f, -0.5f + (2 * -0.5),  1.0f, 0.0f, // bottom-right         
     0.5f,  0.5f, -0.5f + (2 * -0.5),  1.0f, 1.0f, // top-right
     0.5f,  0.5f, -0.5f + (2 * -0.5),  1.0f, 1.0f, // top-right
    -0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 0.0f, // bottom-left
    -0.5f,  0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // top-left
    // Front face
    -0.5f, -0.5f,  0.5f+(2*-0.5),  0.0f, 0.0f, // bottom-left
     0.5f, -0.5f,  0.5f+(2*-0.5),  1.0f, 0.0f, // bottom-right
     0.5f,  0.5f,  0.5f+(2*-0.5),  1.0f, 1.0f, // top-right
     0.5f,  0.5f,  0.5f+(2*-0.5),  1.0f, 1.0f, // top-right
    -0.5f,  0.5f,  0.5f+(2*-0.5),  0.0f, 1.0f, // top-left
    -0.5f, -0.5f,  0.5f+(2*-0.5),  0.0f, 0.0f, // bottom-left
    // Left face
    -0.5f,  0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // top-right
    -0.5f,  0.5f, -0.5f + (2 * -0.5),  1.0f, 1.0f, // top-left
    -0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f,  0.5f + (2 * -0.5),  0.0f, 0.0f, // bottom-right
    -0.5f,  0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // top-right
    // Right face
     0.5f,  0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // top-left
     0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // bottom-right
     0.5f,  0.5f, -0.5f + (2 * -0.5),  1.0f, 1.0f, // top-right         
     0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // bottom-right
     0.5f,  0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // top-left
     0.5f, -0.5f,  0.5f + (2 * -0.5),  0.0f, 0.0f, // bottom-left     
    // Bottom face
    -0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // top-right
     0.5f, -0.5f, -0.5f + (2 * -0.5),  1.0f, 1.0f, // top-left
     0.5f, -0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // bottom-left
     0.5f, -0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // bottom-left
    -0.5f, -0.5f,  0.5f + (2 * -0.5),  0.0f, 0.0f, // bottom-right
    -0.5f, -0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // top-right
    // Top face
    -0.5f,  0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // top-left
     0.5f,  0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // bottom-right
     0.5f,  0.5f, -0.5f + (2 * -0.5),  1.0f, 1.0f, // top-right     
     0.5f,  0.5f,  0.5f + (2 * -0.5),  1.0f, 0.0f, // bottom-right
    -0.5f,  0.5f, -0.5f + (2 * -0.5),  0.0f, 1.0f, // top-left
    -0.5f,  0.5f,  0.5f + (2 * -0.5),  0.0f, 0.0f, // bottom-left
};

float baseCube[] = {
    // Back face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left 0.0f 0.6
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right  1.0f 1.0f
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right 1.0f 0.6f      
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right   1.0f 1.0f
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left 0.0f 0.6f 
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left    0.0f 1.0f
    // Front face
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
    // Left face
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
    // Right face
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right         
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left     
    // Bottom face
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
    // Top face
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right     
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
};

float plainCube[] = {
    // Back face
    -0.5f, -0.5f, -0.5f,     0.0f, 0.6f,      0.0f,0.0f, -1.0f,   1.0f,1.0f,1.0f,1.0f, // Bottom-left 0.0f 0.6
     0.5f,  0.5f, -0.5f,     1.0f, 1.0f,      0.0f,0.0f, -1.0f,   1.0f,1.0f,1.0f,1.0f,// top-right  1.0f 1.0f
     0.5f, -0.5f, -0.5f,     1.0f, 0.6f,      0.0f,0.0f, -1.0f,   1.0f,1.0f,1.0f,1.0f,// bottom-right 1.0f 0.6f      
     0.5f,  0.5f, -0.5f,     1.0f, 1.0f,      0.0f,0.0f, -1.0f,   1.0f,1.0f,1.0f,1.0f,// top-right   1.0f 1.0f
    -0.5f, -0.5f, -0.5f,     0.0f, 0.6f,      0.0f,0.0f, -1.0f,   1.0f,1.0f,1.0f,1.0f,// bottom-left 0.0f 0.6f 
    -0.5f,  0.5f, -0.5f,     0.0f, 1.0f,      0.0f,0.0f, -1.0f,   1.0f,1.0f,1.0f,1.0f,// top-left    0.0f 1.0f
    // Front face
    -0.5f, -0.5f,  0.5f,     0.0f, 0.6f,      0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
     0.5f, -0.5f,  0.5f,     1.0f, 0.6f,      0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f,  0.5f,     1.0f, 1.0f,      0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
     0.5f,  0.5f,  0.5f,     1.0f, 1.0f,      0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
    -0.5f,  0.5f,  0.5f,     0.0f, 1.0f,      0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
    -0.5f, -0.5f,  0.5f,     0.0f, 0.6f,      0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
    // Left face
    -0.5f,  0.5f,  0.5f,     1.0f, 1.0f,      -1.0f,0.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// top-right
    -0.5f,  0.5f, -0.5f,     0.0f, 1.0f,      -1.0f,0.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// top-left
    -0.5f, -0.5f, -0.5f,     0.0f, 0.6f,      -1.0f,0.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// bottom-left
    -0.5f, -0.5f, -0.5f,     0.0f, 0.6f,      -1.0f,0.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// bottom-left
    -0.5f, -0.5f,  0.5f,     1.0f, 0.6f,      -1.0f,0.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// bottom-right
    -0.5f,  0.5f,  0.5f,     1.0f, 1.0f,      -1.0f,0.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// top-right
    // Right face
     0.5f,  0.5f,  0.5f,     0.0f, 1.0f,      1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f, -0.5f, -0.5f,     1.0f, 0.6f,      1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f, -0.5f,     1.0f, 1.0f,      1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-right         
     0.5f, -0.5f, -0.5f,     1.0f, 0.6f,      1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f,  0.5f,     0.0f, 1.0f,      1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f, -0.5f,  0.5f,     0.0f, 0.6f,      1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left     
    // Bottom face
    -0.5f, -0.5f, -0.5f,     0.0f, 1.0f,      0.0f,-1.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// top-right
     0.5f, -0.5f, -0.5f,     1.0f, 1.0f,      0.0f,-1.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f, -0.5f,  0.5f,     1.0f, 0.0f,      0.0f,-1.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// bottom-left
     0.5f, -0.5f,  0.5f,     1.0f, 0.0f,      0.0f,-1.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// bottom-left
    -0.5f, -0.5f,  0.5f,     0.0f, 0.0f,      0.0f,-1.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// bottom-right
    -0.5f, -0.5f, -0.5f,     0.0f, 1.0f,      0.0f,-1.0f,0.0f,    1.0f,1.0f,1.0f,1.0f,// top-right
    // Top face
    -0.5f,  0.5f, -0.5f,     0.0f, 0.6f,      0.0f,1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f,  0.5f,  0.5f,     1.0f, 0.4f,      0.0f,1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f, -0.5f,     1.0f, 0.6f,      0.0f,1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-right     
     0.5f,  0.5f,  0.5f,     1.0f, 0.4f,      0.0f,1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
    -0.5f,  0.5f, -0.5f,     0.0f, 0.6f,      0.0f,1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
    -0.5f,  0.5f,  0.5f,     0.0f, 0.4f,      0.0f,1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
};

float waterCube[] = {
    // Back face
    -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,       0.0f, 0.0f, -1.0f,  1.0f,1.0f,1.0f,1.0f,// Bottom-left 
     0.5f,  0.5f, -0.5f,    1.0f, 0.3f,       0.0f, 0.0f, -1.0f,  1.0f,1.0f,1.0f,1.0f,// top-right  
     0.5f, -0.5f, -0.5f,    1.0f, 0.0f,       0.0f, 0.0f, -1.0f,  1.0f,1.0f,1.0f,1.0f,// bottom-right      
     0.5f,  0.5f, -0.5f,    1.0f, 0.3f,       0.0f, 0.0f, -1.0f,  1.0f,1.0f,1.0f,1.0f,// top-right   
    -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,       0.0f, 0.0f, -1.0f,  1.0f,1.0f,1.0f,1.0f,// bottom-left 
    -0.5f,  0.5f, -0.5f,    0.0f, 0.3f,       0.0f, 0.0f, -1.0f,  1.0f,1.0f,1.0f,1.0f,// top-left    
    // Front face
    -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,       0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
     0.5f, -0.5f,  0.5f,    1.0f, 0.0f,       0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f,  0.5f,    1.0f, 0.3f,       0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
     0.5f,  0.5f,  0.5f,    1.0f, 0.3f,       0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
    -0.5f,  0.5f,  0.5f,    0.0f, 0.3f,       0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
    -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,       0.0f,0.0f,1.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
    // Left face                                                  
    -0.5f,  0.5f,  0.5f,    1.0f, 0.3f,      -1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
    -0.5f,  0.5f, -0.5f,    0.0f, 0.3f,      -1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
    -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,      -1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
    -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,      -1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
    -0.5f, -0.5f,  0.5f,    1.0f, 0.0f,      -1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
    -0.5f,  0.5f,  0.5f,    1.0f, 0.3f,      -1.0f,0.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
    // Right face
     0.5f,  0.5f,  0.5f,    0.0f, 0.3f,      1.0f,0.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f, -0.5f, -0.5f,    1.0f, 0.0f,      1.0f,0.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f, -0.5f,    1.0f, 0.3f,      1.0f,0.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// top-right         
     0.5f, -0.5f, -0.5f,    1.0f, 0.0f,      1.0f,0.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f,  0.5f,    0.0f, 0.3f,      1.0f,0.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f, -0.5f,  0.5f,    0.0f, 0.0f,      1.0f,0.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// bottom-left     
    // Bottom face
    -0.5f, -0.5f, -0.5f,    0.0f, 0.3f,      0.0f,-1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
     0.5f, -0.5f, -0.5f,    0.0f, 0.3f,      0.0f,-1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f, -0.5f,  0.5f,    0.0f, 0.0f,      0.0f,-1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
     0.5f, -0.5f,  0.5f,    0.0f, 0.0f,      0.0f,-1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-left
    -0.5f, -0.5f,  0.5f,    1.0f, 0.0f,      0.0f,-1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// bottom-right
    -0.5f, -0.5f, -0.5f,    0.0f, 0.3f,      0.0f,-1.0f,0.0f,     1.0f,1.0f,1.0f,1.0f,// top-right
    // Top face
    -0.5f,  0.5f, -0.5f,    0.0f, 0.3f,      0.0f,1.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// top-left
     0.5f,  0.5f,  0.5f,    1.0f, 0.0f,      0.0f,1.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// bottom-right
     0.5f,  0.5f, -0.5f,    1.0f, 0.3f,      0.0f,1.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// top-right     
     0.5f,  0.5f,  0.5f,    1.0f, 0.0f,      0.0f,1.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// bottom-right
    -0.5f,  0.5f, -0.5f,    0.0f, 0.3f,      0.0f,1.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// top-left
    -0.5f,  0.5f,  0.5f,    0.0f, 0.0f,      0.0f,1.0f,0.0f,      1.0f,1.0f,1.0f,1.0f,// bottom-left
};

//Chuck Generator
typedef struct {
    float x, y, z;//positions
    float u, v;//texture co-ordinates
    float nx, ny, nz;//normal co-ordinates
    float r, g, b, a;//colors
}
Vertex;

std::vector<Vertex> vectorVertices;
std::vector<Vertex> editableVectorVertices;

class ChunkGenerator {
public:
    ChunkGenerator() {
        /*for (int i = 0; i < sizeof(baseCube)/sizeof(baseCube[0]); i += 5) {
            Vertex tmpVertex;
            tmpVertex.x = baseCube[i];
            tmpVertex.y = baseCube[i+1];
            tmpVertex.z = baseCube[i+2];
            tmpVertex.u = baseCube[i + 3];
            tmpVertex.v = baseCube[i + 4];
            vectorVertices.push_back(tmpVertex);
        }*/

        //int numberOfCubes = 16;//NxNxN world
        //for (int x = 0; x < numberOfCubes; x++) {
        //    for (int y = 0; y < numberOfCubes; y++) {
        //        for (int z = 0; z < numberOfCubes; z++) {
        //            for (int i = 0; i < sizeof(baseCube) / sizeof(baseCube[0]); i += 5) {
        //                Vertex tmpVertex;
        //                tmpVertex.x = baseCube[i];
        //                tmpVertex.y = baseCube[i + 1];
        //                tmpVertex.z = baseCube[i + 2];
        //                tmpVertex.u = baseCube[i + 3];
        //                tmpVertex.v = baseCube[i + 4];
        //                tmpVertex.isActive = 1.0f;
        //                //change vertex positions here
        //                tmpVertex.x += ((2*(float)x) * 0.5f);
        //                tmpVertex.y += ((2*(float)y) * 0.5f);
        //                tmpVertex.z += ((2*(float)z) * -0.5f);
        //                if (tmpVertex.isActive == 1.0f) {
        //                    vectorVertices.push_back(tmpVertex);
        //                }
        //            }
        //        }
        //    }
        //}
        generate_mesh_by_perlin_noise();
        generateEditableBlock();
    }

    void drawCircle() {
        vectorVertices.clear();
        int CHUNK_SIZE = 16;
        for (int x = 0; x < CHUNK_SIZE; x++) {
            for (int y = 0; y < CHUNK_SIZE; y++) {
                for (int z = 0; z < CHUNK_SIZE; z++) {
                    if (sqrt((float)(x - CHUNK_SIZE / 2) * (x - CHUNK_SIZE / 2) + (y - CHUNK_SIZE / 2) * (y - CHUNK_SIZE / 2) + (z - CHUNK_SIZE / 2) * (z - CHUNK_SIZE / 2)) > CHUNK_SIZE / 2) {
                        continue;
                    }
                    //this loop will create a single cube
                    for (int i = 0; i < sizeof(baseCube) / sizeof(baseCube[0]); i += 5) {
                        Vertex tmpVertex;
                        tmpVertex.x = baseCube[i];
                        tmpVertex.y = baseCube[i + 1];
                        tmpVertex.z = baseCube[i + 2];
                        tmpVertex.u = baseCube[i + 3];
                        tmpVertex.v = baseCube[i + 4];
                        //change vertex positions here
                        tmpVertex.x += ((2 * (float)x) * 0.5f);
                        tmpVertex.y += ((2 * (float)y) * 0.5f);
                        tmpVertex.z += ((2 * (float)z) * -0.5f);
                        //update the vector vertices
                        vectorVertices.push_back(tmpVertex);
                    }
                }
            }
        }
    }

    void generate_mesh_by_perlin_noise() {
        vectorVertices.clear();
        int avgHeight = avgInArray(fPerlinNoise2D,50*50);
        int numberOfCubes = 50;//NxNxN world
        int tmp = 0;
        for (int x = 0; x < numberOfCubes; x++) {
            for (int z = 0; z < numberOfCubes; z++) {
                int height=round(fPerlinNoise2D[tmp]*50);
                for (int y = 0; y < height; y++) {
                    if (height <= (avgHeight-2) && x>0 &&x<49 && z>0 && z<49) {
                        for (int i = 0; i < sizeof(waterCube) / sizeof(waterCube[0]); i += 12) {
                            Vertex tmpVertex;
                            tmpVertex.x = waterCube[i];
                            tmpVertex.y = waterCube[i + 1];
                            tmpVertex.z = waterCube[i + 2];

                            tmpVertex.u = waterCube[i + 3];
                            tmpVertex.v = waterCube[i + 4];

                            tmpVertex.nx = waterCube[i + 5];
                            tmpVertex.ny = waterCube[i + 6];
                            tmpVertex.nz = waterCube[i + 7];

                            tmpVertex.r = waterCube[i + 8];
                            tmpVertex.g = waterCube[i + 9];
                            tmpVertex.b = waterCube[i + 10];
                            tmpVertex.a = waterCube[i + 11];
                            //change vertex positions here
                            tmpVertex.x += ((2 * (float)x) * 0.5f);
                            tmpVertex.y += ((2 * (float)y) * 0.5f);
                            tmpVertex.z += ((2 * (float)z) * -0.5f);
                            //update the vector vertices
                            vectorVertices.push_back(tmpVertex);
                        }
                    }
                    else {
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
                            //change vertex positions here
                            tmpVertex.x += ((2 * (float)x) * 0.5f);
                            tmpVertex.y += ((2 * (float)y) * 0.5f);
                            tmpVertex.z += ((2 * (float)z) * -0.5f);
                            //update the vector vertices
                            vectorVertices.push_back(tmpVertex);
                        }
                    }
                }
                tmp += 1;
            }
        }
    }

    //find the max value in an array
    int avgInArray(float arr[], int n)
    {
        int i;
        // Initialize maximum element
        float total = arr[0];

        // Traverse array elements
        // from second and compare
        // every element with current max
        for (i = 1; i < n; i++)
            total += arr[i];
        return round(((total) / (50 * 50)) * 50);
    }

    void generateEditableBlock() {
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
            editableVectorVertices.push_back(tmpVertex);
        }
    }
};