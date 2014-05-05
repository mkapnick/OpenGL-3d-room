#ifndef FP_Hallway_h
#define FP_Hallway_h

#include "Cube.h"
#include <vector>
using namespace std;




/**
 * A representation of a hallway. (Really a collection of cubes)
 *
 * @author  Michael Kapnick
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