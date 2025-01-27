//
//  Cube.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include<stdio.h>
#include "Cube.h"
#include "Drawer.h"


Cube::Cube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition, GLfloat ang[3], CubeProperties* properties)
{
    offsetX     = xPosition;
    offsetY     = yPosition;
    offsetZ     = zPosition;
    
    angle[0] = ang[0];
    angle[1] = ang[1];
    angle[2] = ang[2];
    
    this->properties = properties;
}

Cube::Cube()
{}

/**
 * Add a face
 *
 * @param face   The face index
 */
void Cube::draw(int face)
{
    Drawer drawer = Drawer(this->properties);
    drawer.draw(face);
}

/**
 *
 */
GLfloat* Cube::getAngleArray()
{
    return angle;
}

/**
 *
 */
CubeProperties* Cube::getCubeProperties()
{
    return this->properties;
}

/**
 *
 */
GLfloat* Cube::getOffsetX()
{
    return &offsetX;
}

/**
 *
 */
GLfloat* Cube::getOffsetY()
{
    return &offsetY;
}

/**
 *
 */
GLfloat* Cube::getOffsetZ()
{
    return &offsetZ;
}

/**
 *
 */
void Cube::handleTick()
{
    GLfloat   color[] = {1.0, 1.0, 1.0};
    glEnable(GL_TEXTURE_2D);
    
    glPushMatrix();

    glTranslated(offsetX, offsetY, offsetZ);
        
    glRotated(angle[0], 1, 0, 0);
    glRotated(angle[1], 0, 1, 0);
    glRotated(angle[2], 0, 0, 1);


    //draw cube here with texture mapping
    for (int f=0; f<6; f++)
    {
        glBindTexture(GL_TEXTURE_2D, properties->textureNames[f]);
        draw(f);
    }
        
    glDisable(GL_TEXTURE_2D);
    
    glMaterialfv(GL_BACK, GL_AMBIENT,  color);
    glMaterialfv(GL_BACK, GL_DIFFUSE,  color);
    glMaterialfv(GL_BACK, GL_SPECULAR, color);
    glMaterialf(GL_BACK, GL_SHININESS, 80);

    glPopMatrix();
}

/**
 *
 */
void Cube::keyPressed(unsigned char key, int x, int y)
{
}


















