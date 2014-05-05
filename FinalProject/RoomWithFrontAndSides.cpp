//
//  RoomWithFrontAndSides.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/4/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "RoomWithFrontAndSides.h"
#include <math.h>

RoomWithFrontAndSides::RoomWithFrontAndSides(vector<Cube> cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
}

RoomWithFrontAndSides::RoomWithFrontAndSides()
{
    //nothing
}

vector<Cube> RoomWithFrontAndSides::getCubes()
{
    return this->cubes;
}

void RoomWithFrontAndSides::setUpVisibleFaces()
{
    Cube            cube;
    size_t          size;
    size_t          half;
    Faces           face;
    CubeProperties*  properties;
    
    size = this->cubes.size();
    half = floor(size/2);
    
    
    for(int i =0; i < this->cubes.size(); i++)
    {
        cube        = this->cubes[i];
        properties  = cube.getCubeProperties();
        
        if(i == size - 1)
        {
            face = Faces::BACK;
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

