#ifndef FP_JmuRightHallway_h
#define FP_JmuRightHallway_h

#include "Cube.h"
#include <vector>
#include "Hallway.h"
using namespace std;


/**
 * The right hallway in the JMU CS Department
 *
 * @author  Michael Kapnick
 * @version 1.0
 */
class JmuRightHallway: public Hallway
{
public:
    
    JmuRightHallway(vector<Cube> cubes);
    JmuRightHallway();
    
    void handleTick();
    void update(GLfloat z, bool positive);
    
private:
    void setUpVisibleFaces();
};
#endif