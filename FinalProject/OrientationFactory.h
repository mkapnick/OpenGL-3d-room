#ifndef FP_OrientationFactory_h
#define FP_OrientationFactory_h

#include "Sprite.h"

/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class OrientationFactory
{
public:
    
    OrientationFactory();
    void getFloorMapping(GLfloat**& floor);
    void getCeilingMapping(GLfloat**& ceiling);
    void getWallMapping(GLfloat**& wall);
    void getBackMapping(GLfloat**& front);
    void getFrontMapping(GLfloat**& front);
    void getLeftWallMapping(GLfloat**& front);
    void getRightWallMapping(GLfloat**& front);

};
#endif