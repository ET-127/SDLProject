//
//  main.cpp
//  SDLProject
//
//  Created by Eyitayo Adedeji on 29/07/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "MainGame.h"

using namespace std;

int main(int argc,char** argv) {
    
    MainGame mainGame;
    
    mainGame.run();

    return 0;
}
