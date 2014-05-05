#ifndef FP_CubeProperties_h
#define FP_CubeProperties_h

#include "Sprite.h"
#include "Faces.h"
#include "Position.h"
#include <vector>
#include "Location.h"
using namespace std;



/**
 * Encapsulates all the necessary properties needed for a cube
 * @author  Michael Kapnick
 * @version 1.0
 */
class CubeProperties
{
public:
    friend class Drawer;
    CubeProperties();
    CubeProperties(CubeProperties& properties);
    
    void setCubeImages(Position position);
    void setCubeVertices(GLfloat x, GLfloat y, GLfloat z);
    void setFacesExcept(Faces f [], int size);
    void setFacesExcept(Faces f);
    char *images[6];
    GLuint textureNames[6];
    void setImages(Position pos);
    void changeImage(Location location, char* image);
    
private:
    void updateFaces(int row);
    void initializeFaces();
    void setVertices(GLfloat x, GLfloat y, GLfloat z);
    void updateTextureMap();
    void readRAWImage(char* filename, GLbyte data[256][256][3]);
    GLfloat vertices [8][3];
    GLfloat alternateVertices[8][3];
    GLint faces [6][4];

    
    void copyFaces(GLint faces[6][4]);
    void copyVertices(GLfloat vertices[8][3]);
    void copyImages(char * images[6]);
    
};
#endif