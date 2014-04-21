#ifndef FP_MainHallway_h
#define FP_MainHallway_h

#include "Sprite.h"
#include "MainHallwayRight.h"
#include "MainHallwayLeft.h"


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class MainHallway: public Sprite
{
public:
    
    MainHallway(GLfloat offset);
    void handleTick();
    void keyPressed(unsigned char key, int x, int y);
    void setRotation(int angle);
    void mouseClicked(int button, int state, int x, int y);
    
private:
    GLfloat             offsetX, offsetY;
    GLfloat             theta[3];
    GLint               axis;
    GLfloat             angle[3];
    int                 position;
    MainHallwayRight    right;
    MainHallwayLeft     left;
    int rotation;
    int direction;
    bool firstPersonMode;

    
};
#endif