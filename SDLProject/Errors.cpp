//
//  Errors.cpp
//  SDLProject
//
//  Created by Eyitayo Adedeji on 30/07/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#include "Errors.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>

using namespace std;

void fatalError(string errorString){
    
    cout << errorString << endl;
    cout << "Enter any key to quit...";
    
    int tmp;
    cin >> tmp;
    SDL_Quit();
    exit(1);
}