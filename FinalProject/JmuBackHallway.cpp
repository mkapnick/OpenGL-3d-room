//
//  JmuBackHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "JmuBackHallway.h"
#include "RoomWithBackAndSides.h"
#include "RoomWithFrontandSides.h"
#include <math.h>

JmuBackHallway::JmuBackHallway(vector<Cube>cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
    drawClassroom1();
    drawClassroom2();
    drawClassroom3();
    drawClassroom4();
    drawClassroom5();
    drawClassroom6();
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
            face = Faces::LEFT;
            properties->setFacesExcept(face);
        }
        else if(i == (half+3))
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            face = Faces::LEFT;
            properties->setFacesExcept(face);
            
            classroom1X = *cube.getOffsetX();
            classroom1Y = *cube.getOffsetY();
            classroom1Z = *cube.getOffsetZ();
        }
        else if (i == (half + 4))
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            
            classroom2X = *cube.getOffsetX();
            classroom2Y = *cube.getOffsetY();
            classroom2Z = *cube.getOffsetZ();
        }
        
        else if(i == (half-3))
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            face = Faces::LEFT;
            properties->setFacesExcept(face);
            
            classroom1X = *cube.getOffsetX();
            classroom1Y = *cube.getOffsetY();
            classroom1Z = *cube.getOffsetZ();
        }
        else if (i == (half - 4))
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            
            classroom2X = *cube.getOffsetX();
            classroom2Y = *cube.getOffsetY();
            classroom2Z = *cube.getOffsetZ();
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
    RoomWithFrontAndSides r;
    
    startingAngles[0] = 0;
    startingAngles[1] = 0;
    startingAngles[2] = 0;
    
    properties = CubeProperties();
    factory    = CubeFactory();
    
    properties.setCubeVertices(20, 10, 35);
    properties.setImages(ROOM_WITH_SIDES_AND_BACK);
    cubes = factory.createUniformCubes(50.2, classroom1Y, classroom1Z + 45, 10, startingAngles, properties, 0, 0, 10);
    /** Customize **/
    
    r = RoomWithFrontAndSides(cubes);
    cubes = r.getCubes();
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
}

void JmuBackHallway::drawClassroom2()
{
    Cube                leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes, cubes2;
    Faces               face;
    RoomWithBackAndSides r;

    startingAngles[0] = 0;
    startingAngles[1] = 0;
    startingAngles[2] = 0;
    
    properties = CubeProperties();
    factory    = CubeFactory();
    
    properties.setCubeVertices(40, 10, 35);
    properties.setImages(ROOM_WITH_SIDES_AND_BACK_NO_RUG);
    cubes = factory.createUniformCubes(70, classroom1Y, classroom1Z - 45, 10, startingAngles, properties, 0, 0, -3);
    /** Customize **/
    
    r = RoomWithBackAndSides(cubes);
    cubes = r.getCubes();
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
}

void JmuBackHallway::drawClassroom3()
{
    Cube leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes, cubes2;
    Faces               face;
    RoomWithFrontAndSides r;

    
    startingAngles[0] = 0;
    startingAngles[1] = 0;
    startingAngles[2] = 0;
    
    properties = CubeProperties();
    factory    = CubeFactory();
    
    properties.setCubeVertices(19.5, 10, 35);
    properties.setImages(ROOM_WITH_SIDES_AND_BACK);
    cubes = factory.createUniformCubes(89.8, classroom1Y, classroom1Z + 45, 10, startingAngles, properties, 0, 0, 10);
    /** Customize **/
    
    r = RoomWithFrontAndSides(cubes);
    cubes = r.getCubes();
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
}

void JmuBackHallway::drawClassroom4()
{
    Cube leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes, cubes2;
    Faces               face;
    RoomWithFrontAndSides r;

    
    startingAngles[0] = 0;
    startingAngles[1] = 0;
    startingAngles[2] = 0;
    
    properties = CubeProperties();
    factory    = CubeFactory();
    
    properties.setCubeVertices(20, 10, 35);
    properties.setImages(ROOM_WITH_SIDES_AND_BACK);
    cubes = factory.createUniformCubes(-50.2, classroom1Y, classroom1Z + 45, 10, startingAngles, properties, 0, 0, 10);
    /** Customize **/
    
    r = RoomWithFrontAndSides(cubes);
    cubes = r.getCubes();
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
}

void JmuBackHallway::drawClassroom5()
{
    Cube leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes, cubes2;
    Faces               face;
    RoomWithBackAndSides r;

    
    startingAngles[0] = 0;
    startingAngles[1] = 0;
    startingAngles[2] = 0;
    
    properties = CubeProperties();
    factory    = CubeFactory();
    
    properties.setCubeVertices(40, 10, 35);
    properties.setImages(ROOM_WITH_SIDES_AND_BACK_NO_RUG);
    cubes = factory.createUniformCubes(-70, classroom1Y, classroom1Z - 45, 10, startingAngles, properties, 0, 0, -3);
    /** Customize **/
    
    r = RoomWithBackAndSides(cubes);
    cubes = r.getCubes();
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
}

void JmuBackHallway::drawClassroom6()
{
        Cube leadingHallway;
        CubeProperties      properties;
        CubeFactory         factory;
        GLfloat             startingAngles[3];
        vector<Cube>        cubes, cubes2;
        Faces               face;
        RoomWithFrontAndSides* r;

    
        startingAngles[0] = 0;
        startingAngles[1] = 0;
        startingAngles[2] = 0;
        
        properties = CubeProperties();
        factory    = CubeFactory();
        
        properties.setCubeVertices(19.5, 10, 35);
        properties.setImages(ROOM_WITH_SIDES_AND_BACK);
        cubes = factory.createUniformCubes(-89.8, classroom1Y, classroom1Z + 45, 10, startingAngles, properties, 0, 0, 10);
        /** Customize **/
    
    r = new RoomWithFrontAndSides(cubes);
    cubes = r->getCubes();
        for(int i =0; i < cubes.size(); i++)
        {
            this->cubes.push_back(cubes[i]);
        }
}

