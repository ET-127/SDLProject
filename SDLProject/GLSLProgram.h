//
//  GLSLProgram.h
//  SDLProject
//
//  Created by Eyitayo Adedeji on 30/07/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>
#include <OpenGL/gl3.h>

using namespace std;

class GLSLProgram{
    
public:
    
    GLSLProgram();
    ~GLSLProgram();

    void compileShaders(const string& vertexShaderFilePath,const string& fragmentShaderFilePath);
    void addAttribute(const string& attributeName);
    
    GLint getUniformLocation(const string& uniformName);
    
    void linkShaders();
    void use();
    void unUse();
    
private:
    
    void compileShader(const string& FilePath,GLuint id);
    
    GLuint _programID;
    
    GLuint _vertexShaderID;
    GLint _fragmentShaderID;
    
    int _numAttributes;


};

