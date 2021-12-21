#pragma once

#include <vector>

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
};

//Chuck Generator
typedef struct {
    float x, y, z;//positions
    float u, v;//texture co-ordinates
    float isActive;
}
Vertex;

std::vector<Vertex> vectorVertices;

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

        int numberOfCubes = 16;//NxNxN world
        for (int x = 0; x < numberOfCubes; x++) {
            for (int y = 0; y < numberOfCubes; y++) {
                for (int z = 0; z < numberOfCubes; z++) {
                    for (int i = 0; i < sizeof(baseCube) / sizeof(baseCube[0]); i += 5) {
                        Vertex tmpVertex;
                        tmpVertex.x = baseCube[i];
                        tmpVertex.y = baseCube[i + 1];
                        tmpVertex.z = baseCube[i + 2];
                        tmpVertex.u = baseCube[i + 3];
                        tmpVertex.v = baseCube[i + 4];
                        tmpVertex.isActive = 1.0f;
                        //change vertex positions here
                        tmpVertex.x += ((2*(float)x) * 0.5f);
                        tmpVertex.y += ((2*(float)y) * 0.5f);
                        tmpVertex.z += ((2*(float)z) * -0.5f);
                        if (tmpVertex.isActive == 1.0f) {
                            vectorVertices.push_back(tmpVertex);
                        }
                    }
                }
            }
        }
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
};