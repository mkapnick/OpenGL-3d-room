#ifndef FP_JmuBackHallway_h
#define FP_JmuBackHallway_h

#include "Cube.h"
#include <vector>
#include "Hallway.h"
#include "CubeFactory.h"
using namespace std;


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class JmuBackHallway: public Hallway
{
public:
    
    JmuBackHallway(vector<Cube> cubes);
    JmuBackHallway();
    
    void handleTick();
    void update(GLfloat z, bool positive);
    
private:
    void setUpVisibleFaces();
    void drawClassroom1();
    void drawClassroom2();
    void drawClassroom3();
    void drawClassroom4();
    void drawClassroom5();
    void drawClassroom6();
    GLfloat classroom1X, classroom1Y, classroom1Z, classroom2X, classroom2Y, classroom2Z;
};
#endif