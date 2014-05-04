#ifndef FP_Cube_h
#define FP_Cube_h

#include "Sprite.h"
#include "CubeProperties.h"
#include "Orientation.h"


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Cube: public Sprite
{
public:
    
    Cube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition, GLfloat startingAngle[3], CubeProperties* properties);
    Cube();
    void handleTick();
    void keyPressed(unsigned char key, int x, int y);
    GLfloat* getOffsetX();
    GLfloat* getOffsetY();
    GLfloat* getOffsetZ();
    GLfloat* getAngleArray();
    CubeProperties* getCubeProperties();
    
private:
    GLfloat             offsetX, offsetY, offsetZ;
    GLfloat             angle[3];
    void draw(int face);
    CubeProperties* properties;
    
};
#endif