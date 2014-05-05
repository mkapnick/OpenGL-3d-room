//
//  JmuBackHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "JmuBackHallway.h"
#include <math.h>

JmuBackHallway::JmuBackHallway(vector<Cube>cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
    drawClassroom1();
    drawClassroom2();
}

void JmuBackHallway::setUpVisibleFaces()
{
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
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
        }
    }
}

void JmuBackHallway::handleTick()
{
    Cube cube;
    for(int i =0; i < this->cubes.size(); i++)
    {
        cube = cubes[i];
        cube.handleTick();
    }
}

void JmuBackHallway::update(GLfloat deltaZ, bool positive)
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

void JmuBackHallway::drawClassroom1()
{
    Cube leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes, cubes2;
    Faces               face;
    
    startingAngles[0] = 0;
    startingAngles[1] = 0;
    startingAngles[2] = 0;
    
    properties = CubeProperties();
    factory    = CubeFactory();
    
    properties.setCubeVertices(20, 10, 35);
    properties.setImages(RIGHTH);
    face = Faces::FRONT;
    properties.setFacesExcept(face);
    face = Faces::BACK;
    properties.setFacesExcept(face);
    cubes = factory.createUniformCubes(extensionX- 10, extensionY, 90, 1, startingAngles, properties, 0, 0, 10);
    /** Customize **/
    
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
    
    

    
}