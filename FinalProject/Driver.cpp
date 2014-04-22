#include "Stage.h"
#include "Cube.h"
#include "Hallway.h"
#include<stdio.h>

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
     Cube   left1, right1,
     left2, right2;
     
     BaseCube middle1;
     
     vector<Cube> cubes1, cubes2;
     GLfloat angles1[3], angles2[3];
     
     left1  = Cube(-10, 0, -15);
     middle1 = BaseCube(0,0, -15);
     right1 = Cube(10,0,-15);
     
     left2 = Cube(-10,0, -35);
     right2 = Cube(-10,0, -45);
     
     cubes1.push_back(right1);
     cubes1.push_back(left1);
     
     cubes2.push_back(left2);
     //cubes2.push_back(right2);
     
     angles1[0] = 0;
     angles1[1] = 0;
     angles1[2] = 0;
     
     angles2[0] = 0;
     angles2[1] = 0;
     angles2[2] = 0;
     
     Hallway hallway1 = Hallway(cubes1, middle1, angles1);
     //Hallway hallway2 = Hallway(cubes2, middle1, angles2);
     delay = 20;
     
     //stage.addSprite(&hallway1);
     stage.addSprite(&hallway1);

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
