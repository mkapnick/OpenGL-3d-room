//
//  CubeProperties.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/26/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "CubeProperties.h"
#include<stdio.h>


CubeProperties::CubeProperties(GLint faces[6][4], GLint replacedFaces[6][4], GLfloat vertices[8][3], GLfloat replacedVertices[8][3], char* filename)
{
    initializeFaces();
    initializeVertices();
    setFaces(faces);
    setReplacedFaces(replacedFaces);
    setVertices(vertices);
    setReplacedVertices(replacedVertices);
    setTextureMap(filename);
}

CubeProperties::CubeProperties(){}

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

void CubeProperties::setTextureMap(char* filename)
{
    /* Read the "image"
    GLbyte image[256][256][3];
    readRAWImage(filename, image);
    
    //[name
    // Get a name for the texture
    glGenTextures(1, &textureName);
    //]name
    
    //[bind
    // Bind the texture object to its name
    glBindTexture(GL_TEXTURE_2D, textureName);
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
    //]enable*/
    
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

void CubeProperties::drawCube(int face)
{
    if(faces[face][0] != -1)
    {
        glBegin(GL_POLYGON);
        int v;
        
        v = faces[face][0];
        glColor3f(0, 0, 0);
        //glTexCoord2f(0.0,0.0);  // Map to the bottom left texel
        glVertex3fv(vertices[v]);
        
        v = faces[face][1];
        glColor3f(0, 0, 1);

        //glTexCoord2f(0.0,1.0);  // Map to the bottom right texel
        glVertex3fv(vertices[v]);
        
        v = faces[face][2];
        glColor3f(0, 0, 1);

        //glTexCoord2f(1.0,1.0); // Map to the top right texel
        glVertex3fv(vertices[v]);
        
        v = faces[face][3];
        glColor3f(0, 0, 0);

        //glTexCoord2f(1.0,0.0); // Map to the top left texel
        glVertex3fv(vertices[v]);
        glEnd();
    }
    else
    {
        drawReplacedFace(face);
    }
}

void CubeProperties::drawReplacedFace(int face)
{
    glBegin(GL_POLYGON);
    int v;
    
    v = replacedFaces[face][0];
    //glTexCoord2f(0.0,0.0);  // Map to the bottom left texel
    glColor3f(0, 0, 0);
    glVertex3fv(replacedVertices[v]);
    
    v = replacedFaces[face][1];
    //glTexCoord2f(0.0,1.0);  // Map to the bottom right texel
    glColor3f(0, 0, 1);
    glVertex3fv(replacedVertices[v]);
    
    v = replacedFaces[face][2];
    glColor3f(0, 0, 1);
    glVertex3fv(replacedVertices[v]);
    
    v = replacedFaces[face][3];
    //glTexCoord2f(1.0,0.0); // Map to the top left texel
    glColor3f(0, 0, 0);
    glVertex3fv(replacedVertices[v]);
    glEnd();
    
    
}
