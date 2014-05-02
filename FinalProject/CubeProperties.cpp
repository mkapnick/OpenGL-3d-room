//
//  CubeProperties.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/26/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "CubeProperties.h"
#include<stdio.h>
#include "OrientationFactory.h"


CubeProperties::CubeProperties(GLint faces[6][4], GLint replacedFaces[6][4], GLfloat vertices[8][3], GLfloat replacedVertices[8][3], char* filenames[6])
{    
    initializeFaces();
    initializeVertices();
    setFaces(faces);
    setReplacedFaces(replacedFaces);
    setVertices(vertices);
    setReplacedVertices(replacedVertices);
    setTextureMap(filenames);
}

CubeProperties::CubeProperties()
{
    //nothing
}

void CubeProperties::bindFace(int face, GLfloat**& mapping)
{
    OrientationFactory  orientationFactory;
    
    orientationFactory = OrientationFactory();
    initializeMapping(mapping);
    
    switch(face)
    {
        case 0:
            orientationFactory.getFrontMapping(mapping);
            break;
        case 1:
            orientationFactory.getRightWallMapping(mapping);
            break;
        case 2:
            orientationFactory.getBackMapping(mapping);
            break;
        case 3:
            orientationFactory.getBackMapping(mapping);
            break;
        case 4:
            orientationFactory.getLeftWallMapping(mapping);
            break;
        case 5:
            orientationFactory.getRightWallMapping(mapping);
            break;
        case 6:
            orientationFactory.getRightWallMapping(mapping);
            break;
    }
    
}

void CubeProperties::drawCube(int face)
{
    GLfloat**           mapping;
    bindFace(face, mapping);
    
    if(faces[face][0] != -1)
    {
        glBegin(GL_POLYGON);
        int v;
        
        v = faces[face][0];
        //glColor3f(0, 0, 0);
        glTexCoord2f(mapping[0][0],mapping[0][1]);  // Map to the bottom left texel
        glVertex3fv(vertices[v]);
        
        v = faces[face][1];
        //glColor3f(0, 0, 1);
        glTexCoord2f(mapping[1][0],mapping[1][1]);  // Map to the bottom right texel
        glVertex3fv(vertices[v]);
        
        v = faces[face][2];
        //glColor3f(0, 0, 1);
        glTexCoord2f(mapping[2][0],mapping[2][1]); // Map to the top left texel
        glVertex3fv(vertices[v]);
        
        v = faces[face][3];
        //glColor3f(0, 0, 0);
        glTexCoord2f(mapping[3][0],mapping[3][1]); // Map to the top left texel
        glVertex3fv(vertices[v]);
        
        glEnd();
    }
    else
    {
        drawReplacedFace(face, mapping);
    }
}

void CubeProperties::drawReplacedFace(int face, GLfloat**&mapping)
{
    glBegin(GL_POLYGON);
    int v;
    
    v = replacedFaces[face][0];
    glTexCoord2f(mapping[0][0],mapping[0][1]);  // Map to the bottom left texel
    //glColor3f(0, 0, 0);
    glVertex3fv(replacedVertices[v]);
    
    v = replacedFaces[face][1];
    glTexCoord2f(mapping[1][0],mapping[1][1]);  // Map to the bottom right texel
    //glColor3f(0, 0, 1);
    glVertex3fv(replacedVertices[v]);
    
    v = replacedFaces[face][2];
    glTexCoord2f(mapping[2][0],mapping[2][1]); // Map to the top left texel
    //glColor3f(0, 0, 1);
    glVertex3fv(replacedVertices[v]);
    
    v = replacedFaces[face][3];
    glTexCoord2f(mapping[3][0],mapping[3][1]); // Map to the top left texel
    //glColor3f(0, 0, 0);
    glVertex3fv(replacedVertices[v]);
    
    glEnd();
}


void CubeProperties::initializeFaces()
{
    this->faces = new GLint*[6];
    this->replacedFaces = new GLint*[6];
    
    for(int i =0; i < 6; i++)
    {
        this->faces[i] = new GLint[4];
        this->replacedFaces[i] = new GLint[4];
    }
}

void CubeProperties::initializeVertices()
{
    this->vertices = new GLfloat*[8];
    this->replacedVertices = new GLfloat*[8];
    
    for(int i =0; i < 8; i++)
    {
        this->vertices[i] = new GLfloat[3];
        this->replacedVertices[i] = new GLfloat[3];
    }
}

void CubeProperties::readRAWImage(char* filename, GLbyte data[256][256][3])
{
    FILE * file;
    
    file = fopen( filename, "rb" );
    if (file != NULL)
    {
        fread(data, 256 * 256 * 3, 1, file);
        fclose(file);
    }
}

void CubeProperties::setTextureMap(char* filenames[6])
{
    //Read the "image"
    GLbyte image[6][256][256][3];
    
    //read in each raw image for the cube
    for(int i =0; i < 6; i++)
    {
        readRAWImage(filenames[i], image[i]);
    }
    
    //[name
    // Get a name for the texture
    glGenTextures(6, textureNames);
    //]name
    
    for (int i=0; i<6; i++)
    {
        // Select the texture object
        glBindTexture(GL_TEXTURE_2D, textureNames[i]);
        
        // Set the parameters
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        
        // Create the texture object
        glTexImage2D(GL_TEXTURE_2D,0,3,256,256,0,GL_RGB,GL_UNSIGNED_BYTE,
                     image[i]);
    }
    
    // Enable textures
    glEnable(GL_TEXTURE_2D);
}

/**
 * Set the faces associated with this cube
 *
 */
void CubeProperties::setFaces(GLint f[6][4])
{
    for(int i =0; i < 6; i++)
    {
        for(int j =0; j < 4; j++)
        {
            this->faces[i][j] = f[i][j];
        }
    }
}

void CubeProperties::setReplacedFaces(GLint f[6][4])
{
    for(int i =0; i < 6; i++)
    {
        for(int j =0; j < 4; j++)
        {
            this->replacedFaces[i][j] = f[i][j];
        }
    }
}

/**
 * Set up the vertices associated with this cube
 *
 */
void CubeProperties::setVertices(GLfloat v[8][3])
{
    for(int i =0; i < 8; i++)
    {
        for(int j =0; j < 3; j++)
        {
            this->vertices[i][j] = v[i][j];
        }
    }
}

/**
 * Set up the vertices associated with this cube
 *
 */
void CubeProperties::setReplacedVertices(GLfloat v[8][3])
{
    for(int i =0; i < 8; i++)
    {
        for(int j =0; j < 3; j++)
        {
            this->replacedVertices[i][j] = v[i][j];
        }
    }
}

void CubeProperties::initializeMapping(GLfloat **& mapping)
{
    mapping = new GLfloat * [4];
    
    for(int i =0; i < 4; i++)
    {
        mapping[i] = new GLfloat[2];
    }
}


