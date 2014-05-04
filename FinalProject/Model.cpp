//  Model.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include<stdio.h>
#include "Model.h"
#include <math.h>


Model::Model(vector<Hallway*> list, BaseCube base, GLfloat* angles)
{
    hallways        = list;
    this->base      = base;
    
    //Keep track of original values.. worry about this later
    
    /*originalZValues = new GLfloat[list.size()];
    originalYValues = new GLfloat[list.size()];
    originalXValues = new GLfloat[list.size()];
    
    Cube tmp;
    for(int i =0; i < list.size() + 1; i++)
    {
        tmp = list[i];
        originalZValues[i] = *tmp.getOffsetZ();
        originalYValues[i] = *tmp.getOffsetY();
        originalXValues[i] = *tmp.getOffsetX();
    }*/
}
Model::Model()
{
    
}

/**
 * Convert degrees to radians
 *
 * @param degrees   The angle in degrees
 * @return          The angle in radians
 */
GLfloat Model::deg2rad(GLfloat degrees)
{
    return degrees*M_PI/180.0;
}

void Model::handleTick()
{
    this->base.handleTick();
    
    for(int i =0; i < hallways.size(); i++)
    {
        hallways[i]->handleTick();
    }
}

void Model::mouseClicked(int button, int state, int x, int y)
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

void Model::keyPressed(unsigned char key, int x, int y)
{
    GLfloat deltaX, deltaZ;
    GLfloat *offsetX, *offsetY, *offsetZ, *cubeZ, *angle;
    bool    positive, restart;
    
    offsetX = base.getOffsetX();
    offsetY = base.getOffsetY();
    offsetZ = base.getOffsetZ();
    
    angle       = base.getAngleArray();
    positive    = true;
    restart     = false;
    deltaX      = 0;
    deltaZ      = 0;
    
    /**************** Update coordinate system! *******************/
    if (key == 'f')
    {
        deltaX      = sin(deg2rad(angle[1]));
        deltaZ      = cos(deg2rad(angle[1]));
        *offsetX += deltaX;
        *offsetZ -= deltaZ;
        positive = false;
    }
    else if (key == 'b')
    {
        deltaX      = sin(deg2rad(angle[1]));
        deltaZ      = cos(deg2rad(angle[1]));
        *offsetX -= deltaX;
        *offsetZ += deltaZ;
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

    /********* Update all hallways associated with this model *********/
    
    for(int i =0; i < hallways.size(); i++)
    {
        hallways[i]->update(deltaZ, positive);
    }
}

