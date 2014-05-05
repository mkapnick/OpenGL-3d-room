#ifndef FP_Drawer_h
#define FP_Drawer_h


#include "OrientationFactory.h"
#include "CubeProperties.h"

/**
 * Responsible drawing an individual face into the world. Also
 * responsible for binding each face to its correct mapping
 *
 * @author  Michael Kapnick
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