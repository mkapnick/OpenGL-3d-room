#ifndef FP_RoomWithFrontAndSides_h
#define FP_RoomWithFrontAndSides_h

#include "CubeProperties.h"
#include "Cube.h"
#include <vector>



/**
 * A room that only has its sides and front visible (drawn) in the world
 *
 * @author  Michael Kapnick
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