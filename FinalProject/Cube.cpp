#include "Cube.h"

/**
 * A Cube is a cube-shaped Sprite that rotates
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */


/**
 * Constructor
 */
Cube::Cube(GLfloat offset)
{
    this->offset = offset;
    
    theta[0] = 0.0; theta[1] = 0.0; theta[2] = 0.0;
    
    axis  = 2;
}


/**
 * Handle clock tick events
 *
 * A Cube rotates itself in response to clock tick events
 */
void Cube::handleTick()
{
    // Reset the transformation matrix
    glLoadIdentity();
    
    // Offset
    glTranslatef(offset, 0.0, 0.0);
    
    // Build the rotation matrix
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
    
    glutSolidCube(1.0);
}




/**
 * Handle "mouse clicked" events
 *
 * A Cube changes its axis of rotation in response to
 * "mouse clicked" events
 *
 * @param button The button (e.g., GLUT_LEFT_BUTTON)
 * @param state  The state (e.g., GLUT_UP or GLUT_DOWN)
 * @param x      The x-position of the mouse
 * @param y      The y-position of the mouse
 */
void Cube::mouseClicked(int button, int state, int x, int y)
{
    
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 1;
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        axis = 2;
    
    // Asjust the rotation angle
    
    for(int i =0; i < 20; i++)
    {
        theta[axis] += 1;
        if(theta[axis] > 360.0) theta[axis] = 0.0;
        
        // Reset the transformation matrix
        glLoadIdentity();
        
        // Offset
        glTranslatef(offset, 0.0, 0.0);
        
        // Build the rotation matrix
        glRotatef(theta[0], 1.0, 0.0, 0.0);
        glRotatef(theta[1], 0.0, 1.0, 0.0);
        glRotatef(theta[2], 0.0, 0.0, 1.0);
        
        glutSolidCube(1.0);
        
    }
}

