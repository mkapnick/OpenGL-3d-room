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
    
    Cube(GLfloat xPosition, GLfloat yPosition, GLfloat zPosition, GLfloat size);
    Cube();
    void handleTick();
    void keyPressed(unsigned char key, int x, int y);
    void mouseClicked(int button, int state, int x, int y);
    GLfloat* getOffsetX();
    GLfloat* getOffsetY();
    GLfloat* getOffsetZ();
    GLfloat* getAngleArray();
    void setTextureMap(char* filename);
    
    
private:
    GLfloat     offsetX, offsetY, offsetZ;
    GLfloat             theta[3];
    GLint               axis;
    int                 rotation;
    int                 direction;
    int                 position;
    GLfloat             angle[3];
    GLfloat             size;
    void readRAWImage(char* filename, GLbyte data[256][256][3]);
    static GLuint       textureName;

    
};
#endif