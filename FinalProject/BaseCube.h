#ifndef FP_BaseCube_h
#define FP_BaseCube_h

#include "Cube.h"


/**
 * A BaseCube is the main point in the world
 *
 * @author  Michael Kapnick
 * @version 1.0
 */
class BaseCube: public Cube
{
public:
    
    BaseCube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition, GLfloat size);
    BaseCube();
    void handleTick();
    void setOffsetY(GLfloat y);
    void setOffsetZ(GLfloat z, bool isPositive);
    void setOffsetX(GLfloat x);
    void setAngleArray(GLfloat * ang);

    GLfloat* getOffsetX();
    GLfloat* getOffsetY();
    GLfloat* getOffsetZ();
    GLfloat* getAngleArray();

private:
    GLfloat             offsetX, offsetY, offsetZ;
    int                 direction;
    GLfloat             angle[3];
    GLfloat size;
};
#endif