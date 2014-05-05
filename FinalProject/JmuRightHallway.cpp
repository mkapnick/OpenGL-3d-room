//
//  JmuRightHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "JmuRightHallway.h"
#include <math.h>

JmuRightHallway::JmuRightHallway(vector<Cube>cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
}

void JmuRightHallway::setUpVisibleFaces()
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
            properties->changeImage(LEFTWALL,"/raws/exit_2704.raw");

            face = Faces::LEFT;
            properties->setFacesExcept(face);
            face = Faces::BACK;
            properties->setFacesExcept(face);
            face = Faces::FRONT;
            properties->setFacesExcept(face);
        }
        else if (i == 1)
        {
            properties->changeImage(FRONTWALL,"/raws/IMG_2363.raw");
            face = Faces::BACK;
            properties->setFacesExcept(face);

        }
        else if(i == size -1)
        {
            properties->changeImage(LEFTWALL,"/raws/grove_door_end.raw");
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
    //end face must not have left face set
    
    //middle 4 faces must not have left faces to set
    
    //last 4 faces must not have right set
    
}

void JmuRightHallway::handleTick()
{
    Cube cube;
    for(int i =0; i < this->cubes.size(); i++)
    {
        cube = cubes[i];
        cube.handleTick();
    }
}

void JmuRightHallway::update(GLfloat deltaZ, bool positive)
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