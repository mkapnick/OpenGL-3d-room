#ifndef FP_JmuLeftHallway_h
#define FP_JmuLeftHallway_h

#include "Cube.h"
#include <vector>
#include "Hallway.h"
using namespace std;


/**
 * The Left Hallway in the JMU CS Department
 *
 * @author  Michael Kapnick
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