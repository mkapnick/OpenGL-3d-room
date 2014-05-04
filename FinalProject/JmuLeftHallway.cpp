//
//  JmuLeftHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "JmuLeftHallway.h"
#include <math.h>

JmuLeftHallway::JmuLeftHallway(vector<Cube>cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
}

void JmuLeftHallway::setUpVisibleFaces()
{
    //beginning face must not have left face set
    Cube            cube;
    size_t          size;
    size_t          half;
    Faces           face;
    CubeProperties*  properties;
    
    size = this->cubes.size();
    
    for(int i =0; i < size; i++)
    {
        cube        = this->cubes[i];
        properties  = cube.getCubeProperties();
        
        face = Faces::FRONT;
        properties->setFacesExcept(face);
        face = Faces::BACK;
        properties->setFacesExcept(face);
        if(i == 0 || i == size -1)
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
        }
    }
    //end face must not have left face set
    
    //middle 4 faces must not have left faces to set
    
    //last 4 faces must not have right set
    
}

void JmuLeftHallway::handleTick()
{
    Cube cube;
    for(int i =0; i < this->cubes.size(); i++)
    {
        cube = cubes[i];
        cube.handleTick();
    }
}

void JmuLeftHallway::update(GLfloat deltaZ, bool positive)
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