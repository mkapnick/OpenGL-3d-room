#ifndef FP_Hallway_h
#define FP_Hallway_h

#include "Cube.h"
#include <vector>
using namespace std;




/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Hallway
{
public:
    
    Hallway(vector<Cube> cubes);
    Hallway();
    virtual void handleTick();
    virtual void update(GLfloat z, bool positive);

protected:
    vector<Cube> cubes;

};
#endif