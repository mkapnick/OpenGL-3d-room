#ifndef FP_CubeFactory_h
#define FP_CubeFactory_h

#include "CubeProperties.h"
#include "Cube.h"



/**
 * A Factory for generating Cubes given the correct parameters
 *
 * @author  Michael Kapnick
 * @version 1.0
 */
class CubeFactory
{
public:
    
    CubeFactory();
    vector<Cube> createUniformCubes(GLfloat x,GLfloat y , GLfloat z, int numberOfCubes, GLfloat startingAngles[3], CubeProperties properties, int stepX, int stepY, int stepZ);
};
#endif