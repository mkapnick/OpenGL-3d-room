#ifndef FP_PropertyFactory_h
#define FP_PropertyFactory_h

#include "Sprite.h"
#include "CubeProperties.h"

/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class PropertyFactory
{
public:
    
    PropertyFactory();
    CubeProperties getLeftCubeProperties();
    CubeProperties getRightCubeProperties();
    CubeProperties getFrontCubeProperties();
    CubeProperties getBackCubeProperties();
    CubeProperties getMiddleCubeProperties();


};
#endif