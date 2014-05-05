//
//  JmuMiddleHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "JmuMiddleHallway.h"
#include <math.h>

JmuMiddleHallway::JmuMiddleHallway(vector<Cube>cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
}

void JmuMiddleHallway::handleTick()
{
    Cube cube;
    for(int i =0; i < this->cubes.size(); i++)
    {
        cube = cubes[i];
        cube.handleTick();
    }
}

void JmuMiddleHallway::setUpVisibleFaces()
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
        
        if(i == 0)
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            face = Faces::LEFT;
            properties->setFacesExcept(face);
            face = Faces::BACK;
            properties->setFacesExcept(face);
        }
        
        else if(i == size -1)
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            face = Faces::LEFT;
            properties->setFacesExcept(face);
            face = Faces::FRONT;
            properties->setFacesExcept(face);
            
        }
        else
        {
            face = Faces::FRONT;
            properties->setFacesExcept(face);
            face = Faces::BACK;
            properties->setFacesExcept(face);
        }
    }
}

void JmuMiddleHallway::update(GLfloat deltaZ, bool positive)
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