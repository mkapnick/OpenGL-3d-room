#ifndef FP_OrientationFactory_h
#define FP_OrientationFactory_h

#include "Sprite.h"

/**
 * Maintains the orientations needed when texture mapping textures
 * to walla
 *
 * @author  Michael Kapnick
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