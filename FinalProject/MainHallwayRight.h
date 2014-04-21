#ifndef FP_MainHallwayRight_h
#define FP_MainHallwayRight_h

#include "Sprite.h"


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class MainHallwayRight: public Sprite
{
public:
    
    MainHallwayRight(GLfloat offset);
    MainHallwayRight();
    void handleTick();
    void keyPressed(unsigned char key, int x, int y);
    void setRotation(int ang, int axis);
    void setPosition(int position);
    
private:
    GLfloat             offsetX, offsetY;
    GLfloat             theta[3];
    GLint               axis;
    GLfloat             angle[3];
    int                 rotation;
    int                 direction;
    int                 position;
    
    
};
#endif