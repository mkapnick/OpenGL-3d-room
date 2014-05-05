//
//  BaseCube.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//
//  Where every object in the world rotates around
//

#include "BaseCube.h"
#include<stdio.h>


BaseCube::BaseCube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition, GLfloat size)
{
    offsetX     = xPosition;
    offsetY     = yPosition;
    offsetZ     = zPosition;
    
    angle[0] = 0;
    angle[1] = 0;
    angle[2] = 0;
    
    this->size = size;
}
BaseCube::BaseCube()
{
}
void BaseCube::handleTick()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glRotatef(angle[0], 1.0, 0.0, 0.0);
    glRotatef(angle[1], 0.0, 1.0, 0.0);
    glRotatef(angle[2], 0.0, 0.0, 1.0);
    
    glTranslated(-offsetX, -offsetY, offsetZ*-2);
}

GLfloat* BaseCube::getAngleArray()
{
    return angle;
}

GLfloat* BaseCube::getOffsetX()
{
    return &offsetX;
}
GLfloat* BaseCube::getOffsetY()
{
    return &offsetY;
}
GLfloat* BaseCube::getOffsetZ()
{
    return &offsetZ;
}
void BaseCube::setAngleArray(GLfloat * ang)
{
    angle[0] = ang[0];
    angle[1] = ang[1];
    angle[2] = ang[2];
}
void BaseCube::setOffsetX(GLfloat x)
{
    offsetX = x;
}

void BaseCube::setOffsetY(GLfloat y)
{
    offsetY = y;
}

void BaseCube::setOffsetZ(GLfloat z, bool isPositive)
{
    offsetZ = z;
}





