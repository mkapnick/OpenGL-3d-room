#ifndef FP_RoomWithFrontAndSides_h
#define FP_RoomWithFrontAndSides_h

#include "CubeProperties.h"
#include "Cube.h"
#include <vector>



/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class RoomWithFrontAndSides
{
public:
    
    RoomWithFrontAndSides(vector<Cube> cubes);
    RoomWithFrontAndSides();
    vector<Cube> getCubes();
private:
    void setUpVisibleFaces();
    vector<Cube> cubes;
};
#endif