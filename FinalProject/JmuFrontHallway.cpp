//
//  JmuFrontHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "JmuFrontHallway.h"
#include "RoomWithBackAndSides.h"
#include "RoomWithFrontAndSides.h"
#include <math.h>

JmuFrontHallway::JmuFrontHallway(vector<Cube>cubes)
{
    this->cubes = cubes;
    setUpVisibleFaces();
    drawNTelosRoom();
    drawExtensionWithCouches();
    drawGradLounge();
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
            properties->changeImage(FLOOR, "/raws/rug.raw");
        }
        if (i == (half + 3))
        {
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            face = Faces::LEFT;
            properties->setFacesExcept(face);
            nTelosX = *cube.getOffsetX();
            nTelosY = *cube.getOffsetY();
            nTelosZ = *cube.getOffsetZ();
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
        else if (i == 0)
        {
            face = Faces::TOP;
            properties->setFacesExcept(face);
            face = Faces::BOTTOM;
            properties->setFacesExcept(face);
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
         
        }
        else if( i == size - 1)
        {
            face = Faces::TOP;
            properties->setFacesExcept(face);
            face = Faces::BOTTOM;
            properties->setFacesExcept(face);
            face = Faces::RIGHT;
            properties->setFacesExcept(face);
            face = Faces::LEFT;
            properties->setFacesExcept(face);
            
            extensionX = *cube.getOffsetX();
            extensionY = *cube.getOffsetY();
            extensionZ = *cube.getOffsetZ();
        }
        else if (i == size - 2)
        {
            face = Faces::LEFT;
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

void JmuFrontHallway::drawExtensionWithCouches()
{
    Cube leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes, cubes2;
    Faces               face;
    RoomWithBackAndSides roomWithBackAndSides;


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
    
    //draw couches

}

void JmuFrontHallway::drawNTelosRoom()
{
    Cube leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes;
    Faces               face;
    RoomWithBackAndSides          roomWithBackAndSides;
    
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
    cubes = factory.createUniformCubes(nTelosX, 0, 90, 1, startingAngles, properties, 0, 0, 10);
    
    /** Customize **/
    
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
    
    properties = CubeProperties();

    properties.setImages(FRONTH);
    properties.setCubeVertices(40, 10, 35);

    cubes = factory.createUniformCubes(nTelosX + 20, 0, 160, 20, startingAngles, properties, 0, 0, 10);

    roomWithBackAndSides = RoomWithBackAndSides(cubes);
    cubes = roomWithBackAndSides.getCubes();

    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }
}

void JmuFrontHallway::drawGradLounge()
{
    Cube leadingHallway;
    CubeProperties      properties;
    CubeFactory         factory;
    GLfloat             startingAngles[3];
    vector<Cube>        cubes, cubes2;
    Faces               face;
    RoomWithBackAndSides* r;
    
    
    startingAngles[0] = 0;
    startingAngles[1] = 0;
    startingAngles[2] = 0;
    
    properties = CubeProperties();
    factory    = CubeFactory();
    
    properties.setCubeVertices(20, 10, 25);
    properties.setImages(ROOM_WITH_SIDES_AND_BACK);
    cubes = factory.createUniformCubes(nTelosX, 0, 10,2,startingAngles, properties,0, 0, -10);
    /** Customize **/
    
    r = new RoomWithBackAndSides(cubes);
    cubes = r->getCubes();
    for(int i =0; i < cubes.size(); i++)
    {
        this->cubes.push_back(cubes[i]);
    }

    
}