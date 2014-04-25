//
//  MainHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "BaseCube.h"
#include<stdio.h>


BaseCube::BaseCube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition, GLfloat size)
{
    offsetX     = xPosition;
    offsetY     = yPosition;
    offsetZ     = zPosition;
    axis        = 1;
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
    GLfloat   color[] = {1.0, 1.0, 1.0};
    GLint radius = 4;
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Work on the Model View Matrix
    //printf("offset x for basecube is: %f\n ", offsetX);
    glTranslated(offsetX, offsetY, offsetZ);
    
    glRotatef(angle[0], 1.0, 0.0, 0.0);
    glRotatef(angle[1], 0.0, 1.0, 0.0);
    glRotatef(angle[2], 0.0, 0.0, 1.0);
    
    // Create a BaseCube
    glMaterialfv(GL_BACK, GL_AMBIENT,  color);
    glMaterialfv(GL_BACK, GL_DIFFUSE,  color);
    glMaterialfv(GL_BACK, GL_SPECULAR, color);
    glMaterialf(GL_BACK, GL_SHININESS, 80);
    
    glutSolidCube(10.0);
    //glTranslated(0, -radius, 0);
    //glutWireTeapot(2);
    //glutWireTeapot(1);
    
    glTranslated(0, -offsetY, -offsetZ);
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

GLfloat* BaseCube::getAngleArray()
{
    return angle;
}
void BaseCube::setAngleArray(GLfloat * ang)
{
    angle[0] = ang[0];
    angle[1] = ang[1];
    angle[2] = ang[2];
}


