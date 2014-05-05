#ifndef FP_RoomWithBackAndSides_h
#define FP_RoomWithBackAndSides_h

#include "CubeProperties.h"
#include "Cube.h"
#include <vector>



/**
 * A room that only has its sides and back visible (drawn) in the world
 *
 * @author  Michael Kapnick
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