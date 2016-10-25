//
//  Vertex.h
//  SDLProject
//
//  Created by Eyitayo Adedeji on 18/08/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#pragma once

#include <OpenGL/gl3.h>

struct Position{
    
    float x;
    float y;
    
};

struct Color{
    
    GLubyte red;
    GLubyte green;
    GLubyte blue;
    GLubyte alpha;
    
};

struct Vertex {
    
    Position position;
    Color color;
    
};
