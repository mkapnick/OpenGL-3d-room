#include <stdio.h>
#include "Sprite.h"


/**
 * A Sprite is a geometric object that "plays" on a Stage
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */

/**
 * Handle "key pressed" events
 *
 * By default, a Sprite does nothing in response to mouse clicks
 *
 * @param key   The key
 * @param x      The x-position of the mouse
 * @param y      The y-position of the mouse
 */
void Sprite::keyPressed(unsigned char key, int x, int y)
{
    // Do nothing
}


/**
 * Handle "mouse clicked" events
 *
 * By default, a Sprite does nothing in response to mouse clicks
 *
 * @param button The button (e.g., GLUT_LEFT_BUTTON)
 * @param state  The state (e.g., GLUT_UP or GLUT_DOWN)
 * @param x      The x-position of the mouse
 * @param y      The y-position of the mouse
 */
void Sprite::mouseClicked(int button, int state, int x, int y)
{
    // Do nothing
}


/**
 * Handle timer events
 */
void Sprite::timerTicked()
{
    // Save the current transformation
    glPushMatrix();
    
    // Handle the tick
    handleTick();
    
    // Restore the transformation
    glPopMatrix();
}
