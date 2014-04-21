#ifndef FP_Stage_h
#define FP_Stage_h

#include <stdlib.h>
#include "GLUT/glut.h"
#include "Sprite.h"
#define  MAX_SPRITES 10

/**
 * A Stage is a "window" that contains animated Sprite objects
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */
class Stage
{
public:
    Stage();
    void addSprite(Sprite* s);
    void keyPressed(unsigned char key, int x, int y, int id);
    void mouseClicked(int button, int state, int x, int y, int id);
    void onTimer();
    void paint();
    void reshape(int width, int height);
    void start();
    ~Stage();
    
private:
    int     size;
    GLfloat light0Position[4];
    GLfloat colorWhite[4];
    Sprite* sprite[MAX_SPRITES];
    
    void init();
};

#endif
