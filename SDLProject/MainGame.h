//
//  MainGame.h
//  SDLProject
//
//  Created by Eyitayo Adedeji on 29/07/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#pragma once

//#ifndef __SDLProject__MainGame__
//#define __SDLProject__MainGame__

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <OpenGL/gl3.h>
#include "Sprite.h"
#include "GLSLProgram.h"



enum class GameState {PLAY, EXIT};

class MainGame{
    
public:
    
    MainGame();
    ~MainGame();
    
    void run();
    
private:
    
    void initSystems();
    void initShaders();
    void gameLoop();
    void processInput();
    void drawGame();
    
    SDL_Window* _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;
    
    Sprite _sprite;
    
    GLSLProgram _colorProgram;
    
    float _time;
    
};

//#endif /* defined(__SDLProject__MainGame__) */
