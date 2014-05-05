#ifndef FP_NTelosRoom_h
#define FP_NTelosRoom_h

#include "CubeProperties.h"
#include "Cube.h"
#include <vector>



/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class NTelosRoom
{
public:
    
    NTelosRoom(vector<Cube> cubes);
    NTelosRoom();
    vector<Cube> getCubes();
private:
    void setUpVisibleFaces();
    vector<Cube> cubes;
};
#endif