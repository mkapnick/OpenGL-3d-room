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
    cubes       = list;
    this->base  = base;
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
    this->base.handleTick();
    
    for(int i =0; i < cubes.size(); i++)
    {
        cubes[i].handleTick();
    }
}

void Hallway::mouseClicked(int button, int state, int x, int y)
{
    GLfloat* angle;
    angle = base.getAngleArray();
    
    if (state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            angle[1] +=2;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            angle[1] -=2;
        }
    }
}

void Hallway::keyPressed(unsigned char key, int x, int y)
{
    GLfloat deltaX, deltaZ, offsetX, offsetY, offsetZ;
    GLfloat* angle;
    bool    positive;
    
    offsetX = base.getOffsetX();
    offsetY = base.getOffsetY();
    offsetZ = base.getOffsetZ();
    
    angle       = base.getAngleArray();
    positive    = true;
    deltaX      = 0;
    deltaZ      = 0;

    if (key == 'b')
    {
        deltaX      = sin(deg2rad(angle[0]));
        deltaZ      = cos(deg2rad(angle[2]));
        offsetX += deltaX;
        offsetZ -= deltaZ;
        positive = false;

    }
    else if (key == 'f')
    {
        deltaX      = sin(deg2rad(angle[0]));
        deltaZ      = cos(deg2rad(angle[2]));
        offsetX -= deltaX;
        offsetZ += deltaZ;
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
    }
    
    if(key == 'u')
    {
        angle[0] +=2;
    }
    else if (key =='d')
    {
        angle[0] -=2;
    }
    
    /*** Update everyone ***/
    base.setOffsetZ(offsetZ, positive);
    base.setOffsetY(offsetY);
    base.setOffsetX(offsetX);
    
    for(int i =0; i < cubes.size(); i++)
    {
        cubes[i].setOffsetZ(deltaZ, positive);
    }
}
