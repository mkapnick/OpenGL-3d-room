#ifndef FP_Drawer_h
#define FP_Drawer_h


#include "OrientationFactory.h"
#include "CubeProperties.h"

/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Drawer
{
public:
    
    Drawer(CubeProperties* properties);
    void initializeMapping(GLfloat**& mapping);
    void bindFace(int face);
    void draw(int face);
    
private:
    CubeProperties* properties;
    GLfloat ** mapping;
};
#endif