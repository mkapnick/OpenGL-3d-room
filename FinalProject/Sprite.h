#ifndef FP_Sprite_h
#define FP_Sprite_h

#include "GLUT/glut.h"


/**
 * A Sprite is a geometric object that "plays" on a Stage
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Sprite
{
public:
    virtual void handleTick() = 0; // A pure virtual (i.e., abstract) method
    
    virtual void keyPressed(unsigned char key, int x, int y);
    
    virtual void mouseClicked(int button, int state, int x, int y);
    
    void timerTicked();
    
private:
    int position;
    
};

#endif