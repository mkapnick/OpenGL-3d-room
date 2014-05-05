#ifndef FP_JmuMiddleHallway_h
#define FP_JmuMiddleHallway_h

#include "Cube.h"
#include <vector>
#include "Hallway.h"
using namespace std;


/**
 * The Middle Hallway in the JMU CS Department
 *
 * @author  Michael Kapnick
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