#ifndef FP_JmuLeftHallway_h
#define FP_JmuLeftHallway_h

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
class JmuLeftHallway: public Hallway
{
public:
    
    JmuLeftHallway(vector<Cube> cubes);
    JmuLeftHallway();
    
    void handleTick();
    void update(GLfloat z, bool positive);
    
private:
    void setUpVisibleFaces();
};
#endif