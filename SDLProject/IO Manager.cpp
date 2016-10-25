//
//  IO Manager.cpp
//  Dimensional Game Engine
//
//  Created by Eyitayo Adedeji on 18/09/2015.
//  Copyright (c) 2015 Eyitayo Adedeji. All rights reserved.
//

#include "IO Manager.h"
#include <fstream>
#include <iostream>

using namespace std;

bool IOManager::readFileToBuffer(string filePath,vector<char>& buffer){
    
    ifstream file(filePath,std::ios::binary);
    
    if(file.fail()){
        
        perror(filePath.c_str());
        return false;
        
    }
    
    //seek to the end
    file.seekg(0,std::ios::beg);
    
    //get file size
    
    int fileSize = file.tellg();
    file.seekg(0,std::ios::beg);
    
    //Reduce the file size by any headers that may be present
    fileSize -= file.tellg();
    
    buffer.resize(fileSize);
    file.read(&(buffer[0]), fileSize);
    file.close();
    
    return true;

}
