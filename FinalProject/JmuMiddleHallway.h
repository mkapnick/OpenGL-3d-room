#ifndef FP_JmuMiddleHallway_h
#define FP_JmuMiddleHallway_h

#include "Cube.h"
#include <vector>
#include "Hallway.h"
using namespace std;


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class JmuMiddleHallway: public Hallway
{
public:
    
    JmuMiddleHallway(vector<Cube> cubes);
    JmuMiddleHallway();
    
    void handleTick();
    void update(GLfloat z, bool positive);
    
private:
    void setUpVisibleFaces();
};
#endif