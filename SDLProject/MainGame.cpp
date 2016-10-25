//
//  MainGame.cpp
//  SDLProject
//
//  Created by Eyitayo Adedeji on 29/07/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#include "MainGame.h"
#include "Sprite.h"
#include "Errors.h"

#include <iostream>
#include <string>
#include <OpenGL/gl3.h>

using namespace std;

MainGame::MainGame():
    _screenWidth(800),
    _screenHeight(600),
    _time(0),
    _window(nullptr),
    _gameState(GameState::PLAY)
{
    
    
    
}

MainGame::~MainGame(){
    
    
    
}

void MainGame::run(){
    
    initSystems();
    
    _sprite.init(-0.5f, -0.5f, 1.0f, 1.0f);
    
    gameLoop();
    
}

void MainGame::initSystems(){
    
    //Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    
    _window = SDL_CreateWindow("Eyitayo's Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    
    if (_window == nullptr) {
        
        fatalError("SDL window could not be created!\n");
        
    }
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
    
    SDL_GLContext glcontext = SDL_GL_CreateContext(_window);
    
    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    
    if (glcontext == nullptr) {
        
        fatalError("SDL_GL context could not be created!\n");
        
    }
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
    
    initShaders();
    
}

void MainGame::initShaders(){
    
    _colorProgram.compileShaders("/Users/Eyitayo/Documents/SDLProject/SDLProject/Shaders/colorShader.vert",
                                 "/Users/Eyitayo/Documents/SDLProject/SDLProject/Shaders/colorShader.frag");
    
    _colorProgram.addAttribute("vertexPosition");
    _colorProgram.addAttribute("vertexColor");
    _colorProgram.linkShaders();
}

void MainGame::gameLoop(){
    
    while (_gameState != GameState::EXIT) {
        
        processInput();
        _time += 0.02;
        drawGame();
        
    }
    
}

void MainGame::processInput(){
    
    SDL_Event evnt;
    
    while(SDL_PollEvent(&evnt)){
        
        switch (evnt.type) {
                
            case SDL_QUIT:
                
                _gameState = GameState::EXIT;
                break;
                
            case SDL_MOUSEMOTION:
                
                //cout << "X = " << evnt.motion.x << " " << "Y = " << evnt.motion.y << "\n";
                
                break;
                
            
        }
        
    }
    
}

void MainGame::drawGame(){
    
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    _colorProgram.use();
    
    GLuint timeLocation = _colorProgram.getUniformLocation("time");
    glUniform1f(timeLocation, _time);

    _sprite.Draw();
    
    _colorProgram.unUse();

    SDL_GL_SwapWindow(_window);
    
}

