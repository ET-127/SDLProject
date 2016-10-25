//
//  Sprite.h
//  SDLProject
//
//  Created by Eyitayo Adedeji on 29/07/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#pragma once
#include <OpenGL/gl3.h>

class Sprite{
    
public:
    
    Sprite();
    ~Sprite();
    
    void init(float x,float y,float width,float height);
    
    void Draw();
    
private:
    
    float _x;
    float _y;
    float _width;
    float _height;
    
    GLuint _vboID;
    
};
