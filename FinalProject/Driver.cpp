#include "Stage.h"
#include "Cube.h"
#include "MainHallway.h"
#include "MainHallwayRight.h"
#include<stdio.h>

#define WEST 0
#define EAST 1
#define NORTH 2
#define SOUTH 3

/**
 * The driver for a simple animation
 *
 * To avoid having to deal with the complexities of C++ method pointers,
 * this driver is written in C
 *
 * @author  Prof. David Bernstein, James Madison University
 * @version 1.0
 */

static int            selectedSprite = 0;
static GLint          delay;
static Stage          stage;
int                   window;

/**
 * Create a window
 *
 * @param title   The title
 * @param width   The width (in pixels)
 * @param height  The height (in pixels)
 * @param x       The x position
 * @param y       The y position
 * @return        The window id
 */
int createWindow(char* title, int width, int height, int x, int y)
{
    int id;
    
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x, y);
    id = glutCreateWindow(title);
    
    return id;
}

/**
 * The display callback
 */
void display()
{
    stage.paint();
}

/**
 * The keyboard callback
 */
void keyboard(unsigned char key, int x, int y)
{
    // Don't forward these events. In this application they are used to
    // select a Sprite.
    // Don't forward these events. In this application they are used to
    // select a Sprite.
    selectedSprite = key - 48;
    for(int i =0; i < MAX_SPRITES; i++)
    {
        stage.keyPressed(key, x, y, i);
    }
}


/**
 * The mouse callback
 *
 * @param button The button (e.g., GLUT_LEFT_BUTTON)
 * @param state  The state (e.g., GLUT_UP or GLUT_DOWN)
 * @param x      The x-position of the mouse
 * @param y      The y-position of the mouse
 */
void mouse(int button, int state, int x, int y)
{
    for(int i =0; i < MAX_SPRITES; i++)
    {
        stage.mouseClicked(button, state, x, y, i);
    }
}


/**
 * The reshape callback
 *
 * @param width   The new width
 * @param height  The new height
 */
void reshape(int width, int height)
{
    stage.reshape(width, height);
}


/**
 * The timer callback
 *
 * @param value   The ID
 */
void timer(int value)
{
    stage.onTimer();
    
    // Re-start the timer
    glutTimerFunc(delay, timer, 1);
}

void keySpecial (int key, int x, int y)
{
    for(int i =0; i < MAX_SPRITES; i++)
    {
        stage.keyPressed(key, x, y, i);
    }
}



/**
 * The entry point of the application.
 *
 * @param argc  The number of command line arguments
 * @param argv  The array of command line arguments
 * @return      A status code
 */
int main(int argc, char **argv)
 {
     //Cube        a(-0.75), b(0.75);
 
     MainHallway mainHallway(.75);
     MainHallwayLeft left(-10);
     MainHallwayRight right(10);
 
     delay = 20;

     stage.addSprite(&mainHallway);

 
     glutInit(&argc, argv);
     window = createWindow("Stage", 640, 480, 0, 0);

     glutDisplayFunc(display);
     glutMouseFunc(mouse);
     glutKeyboardFunc(keyboard);
     glutSpecialFunc(keySpecial);
     glutTimerFunc(delay, timer, 0);
 
     stage.start();
 
     return 0;
 }
