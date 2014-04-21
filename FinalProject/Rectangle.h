#ifndef FP_Rectangle_h
#define FP_Rectangle_h

#include "Sprite.h"

/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Rectangle: public Sprite
{
public:
    Rectangle(GLfloat offset);
    void handleTick();
    void mouseClicked(int button, int state, int x, int y);
    void keyPressed(unsigned char key, int state, int x, int y);
    
    
private:
    GLfloat   offset;
    GLfloat   theta[3];
    GLint     axis;
    
    
};
#endif