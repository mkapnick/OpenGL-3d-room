#ifndef FP_JmuBackHallway_h
#define FP_JmuBackHallway_h

#include "Cube.h"
#include <vector>
#include "Hallway.h"
#include "CubeFactory.h"
using namespace std;


/**
 * The Back Hallway in the JMU CS Department
 *
 * @author  Michael Kapnick
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
    void drawLinuxLab();
    void drawEducationRoom();
    void drawMacLab();
    void draw488Classroom();
    void drawEngineeringLab();
    void drawOtherClassroom();
    GLfloat classroom1X, classroom1Y, classroom1Z, classroom2X, classroom2Y, classroom2Z;
};
#endif