#ifndef FP_CubeProperties_h
#define FP_CubeProperties_h

#include "Sprite.h"


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class CubeProperties
{
public:
    
    CubeProperties(GLint f[6][4], GLint replacedFaces[6][4], GLfloat v[8][3], GLfloat replacedVertices[8][3], char* filename);
    CubeProperties();
    void drawCube(int face);
    GLuint              textureName;

private:
    GLfloat             **vertices;
    GLfloat             **replacedVertices;
    GLint               **faces;
    GLint               **replacedFaces;
    
    void readRAWImage(char* filename, GLbyte data[256][256][3]);
    void initializeVertices();
    void initializeFaces();
    void setTextureMap(char* filename);
    void setFaces(GLint f[6][4]);
    void setReplacedFaces(GLint f[6][4]);
    void setVertices(GLfloat v[8][3]);
    void setReplacedVertices(GLfloat v[8][3]);
    void drawReplacedFace(int face);
};
#endif