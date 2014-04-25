//
//  MainHallway.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/16/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include<stdio.h>
#include "Cube.h"


Cube::Cube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition, GLfloat size)
{
    offsetX     = xPosition;
    offsetY     = yPosition;
    offsetZ     = zPosition;
    axis        = 1;
    angle[0] = 0;
    angle[1] = 0;
    angle[2] = 0;
    this->size = size;
    //this->textureName = 1;
}
Cube::Cube()
{
}
void Cube::handleTick()
{
    GLfloat   color[] = {1.0, 1.0, 1.0};
    GLint radius = 4;

    glTranslated(offsetX, offsetY, offsetZ);
    // Create a cube
    glMaterialfv(GL_BACK, GL_AMBIENT,  color);
    glMaterialfv(GL_BACK, GL_DIFFUSE,  color);
    glMaterialfv(GL_BACK, GL_SPECULAR, color);
    glMaterialf(GL_BACK, GL_SHININESS, 80);
    
    glutSolidCube(size);
    glTranslated(0, -radius, 0);
    
    //glutWireTeapot(2);
    //glutWireTeapot(1);
    
    glTranslated(-offsetX, -offsetY + radius, -offsetZ); //translate back to the center
}

void Cube::mouseClicked(int button, int state, int x, int y)
{
    //nothing
}

GLfloat* Cube::getOffsetX()
{
    return &offsetX;
}
GLfloat* Cube::getOffsetY()
{
    return &offsetY;
}
GLfloat* Cube::getOffsetZ()
{
    return &offsetZ;
}

GLfloat* Cube::getAngleArray()
{
    return angle;
}

void Cube::keyPressed(unsigned char key, int x, int y)
{
    //nothing
}
//[image
/**
 * Fill the given matrix with a RAW image
 *
 * @param data          The matrix to fill
 */
void Cube::readRAWImage(char* filename, GLbyte data[256][256][3])
{
    FILE * file;
    
    file = fopen( filename, "rb" );
    if (file != NULL)
    {
        fread(data, 256 * 256 * 3, 1, file);
        fclose(file);
    }
}

void Cube::setTextureMap(char* filename)
{
    // Read the "image"
    GLbyte image[256][256][3];
    readRAWImage(filename, image);
    
    //[name
    // Get a name for the texture
    //glGenTextures(1, &textureName);
    //]name
    
    //[bind
    // Bind the texture object to its name
    //glBindTexture(GL_TEXTURE_2D, textureName);
    //]bind
    
    //[parameters
    // Specify the parameters
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    //]parameters
    
    //[mode
    // Specify the application mode
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    //]mode
    
    //[create
    // Create the texture object
    glTexImage2D(GL_TEXTURE_2D,
                 0,                 // One resolution (i.e. level 0)
                 3,                 // 3 components (i.e., RGB)
                 256,               // Width
                 256,               // Height
                 0,                 // Border width
                 GL_RGB,            // Format
                 GL_UNSIGNED_BYTE,  // Data type of the texels
                 image);
    //]create
    
    //[enable
    // Enable textures
    glEnable(GL_TEXTURE_2D);
    //]enable

}
















