//
//  JmuFrontHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "JmuFrontHallway.h"
#include <math.h>

JmuFrontHallway::JmuFrontHallway(vector<Cube>cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
}

void JmuFrontHallway::setUpVisibleFaces()
{
    //beginning face must not have left face set
    Cube            cube;
    size_t          size;
    size_t          half;
    Faces           face;
    CubeProperties*  properties;
    
    size = this->cubes.size();
    half = floor(size/2);
    
    for(int i =0; i < size; i++)
    {
        cube        = this->cubes[i];
        properties  = cube.getCubeProperties();
        
        face = Faces::FRONT;
        properties->setFacesExcept(face);
        face = Faces::BACK;
        properties->setFacesExcept(face);
        
        if(i > (half + 1))
        {
            properties->changeImage(2, "/raws/rug.raw");
        }
        if (i == half || i == (half + 1) || i == (half - 1))
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            face = Faces::LEFT;
            properties->setFacesExcept(face);
            face = Faces::TOP;
            properties->setFacesExcept(face);
            face = Faces::BOTTOM;
            properties->setFacesExcept(face);
        }
        else if (i == 0 || i == size - 1)
        {
            face = Faces::TOP;
            properties->setFacesExcept(face);
            face = Faces::BOTTOM;
            properties->setFacesExcept(face);
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
         
        }
        
    }
}

void JmuFrontHallway::handleTick()
{
    Cube cube;
    for(int i =0; i < this->cubes.size(); i++)
    {
        cube = cubes[i];
        cube.handleTick();
    }
}

void JmuFrontHallway::update(GLfloat deltaZ, bool positive)
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