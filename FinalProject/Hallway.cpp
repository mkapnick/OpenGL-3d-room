//  Hallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include<stdio.h>
#include "Hallway.h"
#include <math.h>


Hallway::Hallway(vector<Cube> list, BaseCube base, GLfloat* angles)
{
    vector<Cube>::iterator it;
    
    cubes           = list;
    it              = cubes.begin();

    //cubes.insert(it, base);
    this->base      = base;
    
    originalZValues = new GLfloat[list.size()];
    originalYValues = new GLfloat[list.size()];
    originalXValues = new GLfloat[list.size()];

    //first value is value of base value
    //originalZValues[0] = *base.getOffsetZ();
    //originalYValues[0] = *base.getOffsetY();
    //originalXValues[0] = *base.getOffsetX();
    
    //keep track of original values of cubes
    Cube tmp;
    for(int i =0; i < list.size() + 1; i++)
    {
        tmp = list[i];
        originalZValues[i] = *tmp.getOffsetZ();
        originalYValues[i] = *tmp.getOffsetY();
        originalXValues[i] = *tmp.getOffsetX();
    }
}
Hallway::Hallway()
{
    
}

void Hallway::updateLocation()
{
    Cube cube;
    GLfloat *x1, *y1, *z1, *x2,*y2,*z2;
    
    x1 = this->base.getOffsetX();
    y1 = this->base.getOffsetY();
    z1 = this->base.getOffsetZ();
    
    for(int i =0; i < this->cubes.size(); i++)
    {
        cube = this->cubes[i];
        x2    = cube.getOffsetX();
        y2    = cube.getOffsetY();
        z2    = cube.getOffsetZ();
        
        if(isClose(*x1, *y1, *z1, *x2, *y2, *z2))
        {

            //set cube to have values of current base
            this->cubes[i] = Cube(originalXValues[0], originalYValues[0], originalXValues[0], 10.0);
           
            //update the original values of the new base
            originalXValues[0] = originalXValues[i];
            originalYValues[0] = originalYValues[i];
            originalZValues[0] = originalZValues[i];
            
            //change the base
            this->base = BaseCube(originalXValues[0], originalYValues[0], originalZValues[0], 10.0);
        }
    }
}

bool Hallway::isClose(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2)
{
    GLfloat squared, root;
    
    squared = powf((x2 - x1), 2) + powf((y2-y1), 2) + powf((z2-z1), 2);
    root = sqrtf(squared);
    //printf("root is: %f\n", root);

    if(root < THRESHOLD)
    {
        printf("root is: %f\n", root);
        return true;
    }
    else
        return false;
    
}
/**
 * Convert degrees to radians
 *
 * @param degrees   The angle in degrees
 * @return          The angle in radians
 */
GLfloat Hallway::deg2rad(GLfloat degrees)
{
    return degrees*M_PI/180.0;
}

void Hallway::handleTick()
{
    
    //updateLocation();
    
    this->base.handleTick();
    
    for(int i =0; i < cubes.size(); i++)
    {
        cubes[i].handleTick();
    }
}

void Hallway::mouseClicked(int button, int state, int x, int y)
{
    GLfloat*    localOffsetX, *angle;
    GLfloat     deltaX;

    localOffsetX    = base.getOffsetX();
    angle           = base.getAngleArray();

    deltaX      = sin(deg2rad(angle[1]));
    
    if(deltaX == 0)
        deltaX = 2;

    if (state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            *localOffsetX +=deltaX;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            *localOffsetX -=deltaX;
        }
    }
}

void Hallway::keyPressed(unsigned char key, int x, int y)
{
    GLfloat deltaX, deltaZ;
    GLfloat *offsetX, *offsetY, *offsetZ, *localOffsetZ,
            *localOffsetX;
    GLfloat *angle;
    bool    positive, restart;
    
    offsetX = base.getOffsetX();
    offsetY = base.getOffsetY();
    offsetZ = base.getOffsetZ();
    
    angle       = base.getAngleArray();
    positive    = true;
    restart     = false;
    deltaX      = 0;
    deltaZ      = 0;

    if (key == 'b')
    {
        deltaX      = sin(deg2rad(angle[1]));
        deltaZ      = cos(deg2rad(angle[1]));
        *offsetX += deltaX;
        *offsetZ -= deltaZ;
        positive = false;
        
        printf("change in x is: %f\n", *offsetX);
    }
    else if (key == 'f')
    {
        deltaX      = sin(deg2rad(angle[1]));
        deltaZ      = cos(deg2rad(angle[1]));
        *offsetX -= deltaX;
        *offsetZ += deltaZ;
        
        printf("change in x is: %f\n", *offsetX);
    }
    
    if (key == 'r')
    {
        angle[1]+= 2.0;
        if (angle[1] > 360) angle[1] -= 360;
    }
    else if (key == 'l')
    {
        angle[1] -= 2.0;
        if (angle[1] < 0) angle[1] += 360;
    }
    
    if (key == ' ')
    {
        angle[0] = 0.0;
        angle[1] = 0.0;
        angle[2] = 0.0;
        *offsetX = 0;
        *offsetY = 0;
        *offsetZ = -15;
        restart = true;
    }
    
    if(key == 'd')
    {
        angle[0] +=2;
    }
    else if (key =='u')
    {
        angle[0] -=2;
    }
    
    //printf("angle is: %f\n", angle[1]);
    //printf("offsetZ is: %f\n", *offsetZ);
    
    /*** Update cubes as necessary ***/
    
    for(int i =0; i < cubes.size(); i++)
    {
        localOffsetZ = cubes[i].getOffsetZ();
        
        if(!restart)
        {
            if(positive)
                *localOffsetZ += deltaZ;
            else
                *localOffsetZ -= deltaZ;
        }
        else
        {
            *localOffsetZ = originalZValues[i];
        }
    }
}

