//  MainHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include<stdio.h>
#include "MainHallway.h"

#define WEST 0
#define EAST 1
#define NORTH 2
#define SOUTH 3

MainHallway::MainHallway(GLfloat value)
{
    offsetX     = 0;
    offsetY     = 0;
    position    = -15;
    right       = MainHallwayRight(10);
    left        = MainHallwayLeft(-10);
    rotation    = 0;
    direction   = NORTH;
    axis        = 2;
    firstPersonMode = true;
    
    angle[0]    = 0.0;
    angle[1]    = 0.0;
    angle[2]    = 0.0;
    
    
}
void MainHallway::handleTick()
{
    
    GLfloat   color[] = {1.0, 1.0, 1.0};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT,  color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, color);
    glMaterialf(GL_FRONT, GL_SHININESS, 80);
    
    // Work on the Model View Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslated(offsetX, offsetY, position);
    
    glRotatef(angle[0], 1.0, 0.0, 0.0);
    glRotatef(angle[1], 0.0, 1.0, 0.0);
    glRotatef(angle[2], 0.0, 0.0, 1.0);
    glutSolidCube(10.0);
    glTranslated(-offsetX, -offsetY, -position); //translate back to the center
    
    left.handleTick();
    right.handleTick();
}

void MainHallway::setRotation(int ang)
{
    angle[axis] = ang;
}

void MainHallway::mouseClicked(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            axis = 1;
            angle[axis] +=2;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            axis = 1;
            angle[axis] -=2;
        }
    }
}

void MainHallway::keyPressed(unsigned char key, int x, int y)
{
    if (key == 'f')
        position +=2;
    else if  (key == 'b')
        position -= 2;
    
    right.setPosition(position);
    left.setPosition(position);
    
    if(key == 'u')
    {
        axis = 0;
        angle[axis] +=2;
    }
    else if (key =='d')
    {
        axis = 0;
        angle[axis] -=2;
    }
    
}