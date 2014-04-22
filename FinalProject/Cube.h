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
    
    Cube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition);
    Cube();
    void handleTick();
    void keyPressed(unsigned char key, int x, int y);
    void mouseClicked(int button, int state, int x, int y);
    virtual void setOffsetX(GLfloat x);
    virtual void setOffsetY(GLfloat y);
    virtual void setOffsetZ(GLfloat z, bool isPositive);
    virtual void setAngleArray(GLfloat * ang);
    GLfloat getOffsetX();
    GLfloat getOffsetY();
    GLfloat getOffsetZ();
    GLfloat* getAngleArray();
    
    
private:
    GLfloat     offsetX, offsetY, offsetZ;
    GLfloat             theta[3];
    GLint               axis;
    int                 rotation;
    int                 direction;
    int                 position;
    GLfloat             angle[3];
};
#endif