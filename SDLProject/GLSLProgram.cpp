//
//  GLSLProgram.cpp
//  SDLProject
//
//  Created by Eyitayo Adedeji on 30/07/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#include "GLSLProgram.h"
#include "Errors.h"

#include <fstream>
#include <vector>
#include <string>

using namespace std;

GLSLProgram::GLSLProgram(): _programID(0),_vertexShaderID(0),_fragmentShaderID(0),_numAttributes(0)
{
    
    
    
}

GLSLProgram::~GLSLProgram(){
    
    
    
}

GLint GLSLProgram::getUniformLocation(const string& uniformName){
    
    GLint location = glGetUniformLocation(_programID, uniformName.c_str());
    
    if(location == GL_INVALID_INDEX){
        
        fatalError("Uniform " + uniformName + "not found in shader!");
        
    }
        
    return location;
    
}


void GLSLProgram::compileShaders(const string& vertexShaderFilePath,const string& fragmentShaderFilePath){
    
    glCreateProgram();
    
    //Create Shaders
    _vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    
    if (_vertexShaderID == 0) {
        
        fatalError("Vertex shader failed to be created!");
        
    }
    
    _fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    if (_fragmentShaderID == 0) {
        
        fatalError("Fragment shader failed to be created!");
       
    }
    
    //Compile the vertex shader
    compileShader(vertexShaderFilePath, _vertexShaderID);
    
    //Compile the fragment shader
    compileShader(fragmentShaderFilePath, _fragmentShaderID);
    
}

void GLSLProgram::compileShader(const string& FilePath,GLuint id){
    
    //Vertex and fragment shaders are successfully compiled.
    //Now time to link them together into a program.
    //Get a program object.
    _programID = glCreateProgram();
    
    //Get the filepaths of the vertex shaders
    std::ifstream vertexFile(FilePath);
    if(vertexFile.fail()){
        
        perror(FilePath.c_str());
        fatalError(FilePath + " failed to be loaded!");
        
    }
    
    //Load the vertex shader files
    std::string fileContent = "";
    std::string line;
    
    while (std::getline(vertexFile,line)) {
        
        fileContent += line + "\n";
        
    }
    
    vertexFile.close();
    
    const char* contentPointer = fileContent.c_str();
    
    glShaderSource(id, 1, &contentPointer, nullptr);
    
    glCompileShader(id);
    
    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    
    if (success == GL_FALSE) {
        
        GLint maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        
        // The maxLength includes the NULL character
        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
        
        // Provide the infolog in whatever manor you deem best.
        // Exit with failure.
        glDeleteShader(id); // Don't leak the shader.
        
        std::printf("%s \n", &(errorLog[0]));
        fatalError("Shader" + FilePath + "failed to compile");
        
    }

    
}


void GLSLProgram::linkShaders(){
    
    //Attach our shaders to our program
    glAttachShader(_programID, _vertexShaderID);
    glAttachShader(_programID, _fragmentShaderID);
    
    //Link our program
    glLinkProgram(_programID);
    
    //Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
    if(isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);
        
        //The maxLength includes the NULL character
        std::vector<char> errorLog(maxLength);
        glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);
        
        //We don't need the program anymore.
        glDeleteProgram(_programID);
        //Don't leak shaders either.
        glDeleteShader(_vertexShaderID);
        glDeleteShader(_fragmentShaderID);
        
        //Use the infoLog as you see fit.
        std::printf("%s \n", &(errorLog[0]));
        fatalError("Shaders failed to link!");
    
    }
    
    //Always detach shaders after a successful link.
    glDetachShader(_programID, _vertexShaderID);
    glDetachShader(_programID, _fragmentShaderID);
    glDeleteShader(_vertexShaderID);
    glDeleteShader(_fragmentShaderID);
}

void GLSLProgram::addAttribute(const string& attributeName){
    
    glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
    
}

void GLSLProgram::use(){
    
    glUseProgram(_programID);
    for (int i = 0; i < _numAttributes; i++) {
        
        glEnableVertexAttribArray(i);
        
    }
    
}

void GLSLProgram::unUse(){
    
    glUseProgram(0);
    for (int i = 0; i < _numAttributes; i++) {
        
        glDisableVertexAttribArray(i);
        
    }
    
}

