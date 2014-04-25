#ifndef FP_Hallway_h
#define FP_Hallway_h

#include "Sprite.h"
#include "Cube.h"
#include "BaseCube.h"
#include <vector>
#define FIRST_PERSON_PERSPECTIVE -12
#define THRESHOLD 1
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
    Hallway();
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
    GLfloat* originalZValues, *originalXValues, *originalYValues;
    void updateLocation();
    bool isClose(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2);
    
};
#endif