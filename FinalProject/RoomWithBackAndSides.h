#ifndef FP_RoomWithBackAndSides_h
#define FP_RoomWithBackAndSides_h

#include "CubeProperties.h"
#include "Cube.h"
#include <vector>



/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class RoomWithBackAndSides
{
public:
    
    RoomWithBackAndSides(vector<Cube> cubes);
    RoomWithBackAndSides();
    vector<Cube> getCubes();
private:
    void setUpVisibleFaces();
    vector<Cube> cubes;
};
#endif