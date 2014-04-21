//
//  MainHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include<stdio.h>
#include "MainHallwayLeft.h"

#define WEST 0
#define EAST 1
#define NORTH 2
#define SOUTH 3

MainHallwayLeft::MainHallwayLeft(GLfloat value)
{
    offsetX     = value;
    offsetY     = 0;
    axis        = 1;
    direction   = WEST;
    position    = -15;
    angle[0] = 0;
    angle[1] = 0;
    angle[2] = 0;
}
MainHallwayLeft::MainHallwayLeft()
{
}
void MainHallwayLeft::handleTick()
{
    GLfloat   color[] = {1.0, 1.0, 1.0};

    glTranslated(offsetX,offsetY,position);
    
    glRotatef(angle[0], 1.0, 0.0, 0.0);
    glRotatef(angle[1], 0.0, 1.0, 0.0);
    glRotatef(angle[2], 0.0, 0.0, 1.0);
    
    // Create a cube
    glMaterialfv(GL_FRONT, GL_AMBIENT,  color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color);
    glMaterialf(GL_FRONT, GL_SHININESS, 80);

    glutSolidCube(10.0);
    glutWireTeapot(2);
    glutWireTeapot(1);
    
    glTranslated(-offsetX, -offsetY, -position); //translate back to the center
}

void MainHallwayLeft::mouseClicked(int button, int state, int x, int y)
{
    
}
void MainHallwayLeft::setRotation(int ang, int axis)
{
    angle[axis] = ang;
}

void MainHallwayLeft::setPosition(int pos)
{
    position = pos;
}

void MainHallwayLeft::keyPressed(unsigned char key, int x, int y)
{
    
}
