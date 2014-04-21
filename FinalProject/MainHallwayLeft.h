#ifndef FP_MainHallwayLeft_h
#define FP_MainHallwayLeft_h

#include "Sprite.h"


/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class MainHallwayLeft: public Sprite
{
public:
    
    MainHallwayLeft(GLfloat offset);
    MainHallwayLeft();
    void handleTick();
    void keyPressed(unsigned char key, int x, int y);
    void setRotation(int angle, int axis);
    void setPosition(int position);
    void mouseClicked(int button, int state, int x, int y);

    
    
private:
    GLfloat             offsetX, offsetY;
    GLfloat             theta[3];
    GLint               axis;
    int                 rotation;
    int                 direction;
    int                 position;
    GLfloat             angle[3];

    
    
};
#endif