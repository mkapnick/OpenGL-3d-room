#ifndef FP_Cube_h
#define FP_Cube_h

#include "Sprite.h"

/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Cube: public Sprite
{
public:
    Cube(GLfloat offset);
    void handleTick();
    void mouseClicked(int button, int state, int x, int y);
    
    
private:
    GLfloat   offset;
    GLfloat   theta[3];
    GLint     axis;
    
};
#endif