#ifndef FP_Hallway_h
#define FP_Hallway_h

#include "Sprite.h"
#include "Cube.h"
#include "BaseCube.h"
#include <vector>
using namespace std;


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */

class Hallway: public Sprite
{
public:
    
    Hallway(vector<Cube> cubes, BaseCube base, GLfloat* angles);
    void handleTick();
    void keyPressed(unsigned char key, int x, int y);
    void mouseClicked(int button, int state, int x, int y);
    
private:
    int rotation;
    int direction;
    bool firstPersonMode;
    vector<Cube> cubes;
    BaseCube        base;
    GLfloat deg2rad(GLfloat degrees);
    
    
};
#endif