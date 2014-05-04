//
//  Hallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "Hallway.h"

Hallway::Hallway()
{
    //nothing
}
Hallway::Hallway(vector<Cube> cubes)
{
    this-> cubes = cubes;
}

void Hallway::handleTick()
{
    for (int i =0; i < this->cubes.size(); i++)
    {
        this->cubes[i].handleTick();
    }
}

void Hallway::update(GLfloat deltaZ, bool positive)
{
    GLfloat* cubeZ;
    
    for(int i =0; i < cubes.size(); i++)
    {
        cubeZ = cubes[i].getOffsetZ();
        
        if(positive)
            *cubeZ += deltaZ;
        else
            *cubeZ -= deltaZ;
    }
}
