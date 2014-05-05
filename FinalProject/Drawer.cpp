//
//  Drawer.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/3/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "Drawer.h"

Drawer::Drawer(CubeProperties* properties)
{
    this->properties = properties;
    initializeMapping(mapping);
}

void Drawer::bindFace(int face)
{
    OrientationFactory  orientationFactory;
    orientationFactory = OrientationFactory();
    
    switch(face)
    {
        case 0:
            //printf("0 getting front mapping\n");
            orientationFactory.getFrontMapping(mapping);
            break;
        case 1:
            //printf("1 getting right mapping\n");
            orientationFactory.getRightWallMapping(mapping);
            break;
        case 2:
            //printf("2 getting back mapping\n");
            orientationFactory.getBackMapping(mapping);
            break;
        case 3:
           //printf("3 getting back mapping\n");
            orientationFactory.getBackMapping(mapping);
            break;
        case 4:
           //printf("4 getting left mapping\n");
            orientationFactory.getLeftWallMapping(mapping);
            break;
        case 5:
            //printf("5 getting right mapping\n");
            orientationFactory.getRightWallMapping(mapping);
            break;
        case 6:
            //printf("6 getting right mapping\n");
            orientationFactory.getRightWallMapping(mapping);
            break;
    }
    
}

void Drawer::draw(int face)
{
    bindFace(face);
    if(properties->faces[face][0] != -1)
    {
        glBegin(GL_POLYGON);
        int v;
        
        v = properties->faces[face][0];
        glTexCoord2f(mapping[0][0],mapping[0][1]);  // Map to the bottom left texel
        glVertex3fv(properties->vertices[v]);
        
        v = properties->faces[face][1];
        glTexCoord2f(mapping[1][0],mapping[1][1]);  // Map to the bottom right texel
        glVertex3fv(properties->vertices[v]);
        
        v = properties->faces[face][2];
        glTexCoord2f(mapping[2][0],mapping[2][1]); // Map to the top left texel
        glVertex3fv(properties->vertices[v]);
        
        v = properties->faces[face][3];
        glTexCoord2f(mapping[3][0],mapping[3][1]); // Map to the top left texel
        glVertex3fv(properties->vertices[v]);
        
        glEnd();
    }
}

void Drawer::initializeMapping(GLfloat**& mapping)
{
    mapping = new GLfloat * [4];
    
    for(int i =0; i < 4; i++)
    {
        mapping[i] = new GLfloat[2];
    }
}


