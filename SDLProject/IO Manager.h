//
//  IO Manager.h
//  Dimensional Game Engine
//
//  Created by Eyitayo Adedeji on 18/09/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#pragma once
#include <vector>

using namespace std;

class IOManager {
    
    
public:
    
    static bool readFileToBuffer(string filePath,vector<char>& buffer);
    
};