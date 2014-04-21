//
//  MainHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include<stdio.h>
#include "MainHallwayRight.h"
#define WEST 0
#define EAST 1
#define NORTH 2
#define SOUTH 3

MainHallwayRight::MainHallwayRight(GLfloat value)
{
    offsetX     = value;
    offsetY     = 0;
    direction   = EAST;
    position    = -15;
    axis        = 1;
    
}
MainHallwayRight::MainHallwayRight()
{
    
}
void MainHallwayRight::handleTick()
{
    GLfloat   color[] = {1.0, 1.0, 1.0};

    
    // Transform
    //glPushMatrix();
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    
    glTranslated(offsetX,offsetY,position);
    glRotatef(angle[0], 1.0, 0.0, 0.0);
    glRotatef(angle[1], 0.0, 1.0, 0.0);
    glRotatef(angle[2], 0.0, 0.0, 1.0);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT,  color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color);
    glMaterialf(GL_FRONT, GL_SHININESS, 80);
    
    glutWireCube(10.0);
    glutWireTeapot(1);
    //glPopMatrix();
    
    glTranslated(-offsetX, -offsetY, -position); //translate back to the center
}

void MainHallwayRight::setRotation(int ang, int axis)
{
    angle[axis] = ang;
}

void MainHallwayRight::setPosition(int pos)
{
    position = pos;
}

void MainHallwayRight::keyPressed(unsigned char key, int x, int y)
{
 
}
