#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>


Sprite::Sprite()
{
    //Always initialize your buffer IDs to 0
    _vboID = 0;
}


Sprite::~Sprite()
{
    //Always remember to delete your buffers when
    //you are done!
    if (_vboID != 0) {
        glDeleteBuffers(1, &_vboID);
    }
}

//Initializes the sprite VBO. x, y, width, and height are
//in the normalized device coordinate space. so, [-1, 1]
void Sprite::init(float x, float y, float width, float height) {
    //Set up our private vars
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    
    //Generate the buffer if it hasn't already been generated
    if (_vboID == 0) {
        glGenBuffers(1, &_vboID);
    }
    
    //This array will hold our vertex data.
    //We need 6 vertices, and each vertex has 2
    //floats for X and Y
    Vertex vertexData[6];
    
    //Triangle + Triangle = Square;
    //First Triangle
    
     //Top Right
    vertexData[0].position.x = x + width;
    vertexData[0].position.y = y + height;
    
    //Top Left
    vertexData[1].position.x = x ;
    vertexData[1].position.y = y + height;
    
    //Bottom Left
    vertexData[2].position.x = x;
    vertexData[2].position.y = y;
    
    //Second Triangle
    
    //Bottom Left
    vertexData[3].position.x = x;
    vertexData[3].position.y = y;
    
    //Bottom Right
    vertexData[4].position.x = x + width;
    vertexData[4].position.y = y;
    
    //Top Right
    vertexData[5].position.x = x + width;
    vertexData[5].position.y = y + height;
    
    for(int i = 0;i < 6;i++){
        
        vertexData[i].color.red = 0;
        vertexData[i].color.green = 0;
        vertexData[i].color.blue = 255;
        vertexData[i].color.alpha = 255;
        
    }
    
    vertexData[1].color.red = 0;
    vertexData[1].color.green = 255;
    vertexData[1].color.blue = 0;
    vertexData[1].color.alpha = 255;
    
    vertexData[4].color.red = 255;
    vertexData[4].color.green = 0;
    vertexData[4].color.blue = 0;
    vertexData[4].color.alpha = 255;
    
    
    //Tell opengl to bind our vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    //Upload the data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    //Unbind the buffer (optional)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
}

//Draws the sprite to the screen
void Sprite::Draw() {
    
    //bind the buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    //Tell opengl that we want to use the first
    //attribute array. We only need one array right
    //now since we are only using position.
    glEnableVertexAttribArray(0);
    
    //This is the position attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex, position));
    
    //This is the color attribute pointer
    glVertexAttribPointer(1,4,GL_UNSIGNED_BYTE,GL_TRUE, sizeof(Vertex),(void*)offsetof(Vertex, color));
    
    //Draw the 6 vertices to the screen
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    //Disable the vertex attrib array. This is not optional.
    glDisableVertexAttribArray(0);
    
    //Unbind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}