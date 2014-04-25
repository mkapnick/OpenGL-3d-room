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
     //Cubes
     Cube           centerLeftFront1, centerLeftFront2, centerLeftFront3, centerRightFront1,                  centerRightFront2, centerRightFront3, centerCenterBack1, centerLeftBack1, centerLeftBack2, centerLeftBack3, centerRightBack1, centerRightBack2, centerRightBack3, leftSide1, leftSide2, leftSide3, leftSide4, leftSide5, rightSide1, rightSide2, rightSide3, rightSide4, rightSide5, middleCenter1, middleCenter2, middleCenter3, middleCenter4, middleCenter5, middleCenter6;
     
     Cube classRoom1, classRoom2;
     
     //Display Lists
     static GLuint dlCenterLeftFront1;
     
     //Hallways
     Hallway hallway1, hallway2, hallway3, hallway4, hallway5, middleHallway;
     
     //Base cube
     BaseCube       middle;
     
     vector<Cube>   cubes1, cubes2, cubes3, cubes4, cubes5;
     GLfloat        startingAngles[3];
     
     centerLeftFront1   = Cube(-10, 0, -15, 10.0);
     centerLeftFront2   = Cube(-20, 0, -15, 10.0);
     centerLeftFront3   = Cube(-30, 0, -15, 10.0);
     middle             = BaseCube(0,0, -15, 10.0);
     centerRightFront1  = Cube(10,0,-15, 10.0);
     centerRightFront2  = Cube(20, 0, -15, 10.0);
     centerRightFront3  = Cube(30, 0, -15, 10.0);
     
     centerLeftBack1    = Cube(-10,0,-65, 10.0);
     centerLeftBack2    = Cube(-20,0, -65, 10.0);
     centerLeftBack3    = Cube(-30,0, -65, 10.0);
     centerCenterBack1  = Cube(0, 0, -65, 10.0);
     centerRightBack1   = Cube(10,0,-65, 10.0);
     centerRightBack2   = Cube(20, 0, -65, 10.0);
     centerRightBack3   = Cube(30, 0, -65, 10.0);
     
     leftSide1          = Cube(-30,0, -25, 10.0);
     leftSide2          = Cube(-30, 0, -35, 10.0);
     leftSide3          = Cube(-30, 0, -45, 10.0);
     leftSide4          = Cube(-30, 0, -55, 10.0);
     
     rightSide1         = Cube(30, 0,-25, 10.0);
     rightSide2         = Cube(30, 0, -35, 10.0);
     rightSide3         = Cube(30, 0, -45, 10.0);
     rightSide4         = Cube(30, 0, -55, 10.0);
     
     middleCenter1      = Cube(0,0,5, 10.0);
     middleCenter2      = Cube(0,0,-5, 10.0);
     middleCenter3      = Cube(0,0,-25, 10.0);
     middleCenter4      = Cube(0,0,-35, 10.0);
     middleCenter5      = Cube(0,0, -45, 10.0);
     middleCenter6      = Cube(0,0, -55, 10.0);

     classRoom1         = Cube(10, 0, -40, 10.0);
     classRoom2         = Cube(-10,0, -40, 10.0);
     
     //front row
     cubes1.push_back(centerLeftFront1);
     cubes1.push_back(centerLeftFront2);
     cubes1.push_back(centerLeftFront3);
     cubes1.push_back(centerRightFront1);
     cubes1.push_back(centerRightFront2);
     cubes1.push_back(centerRightFront3);

     //back row
     cubes2.push_back(centerLeftBack1);
     cubes2.push_back(centerLeftBack2);
     cubes2.push_back(centerLeftBack3);
     cubes2.push_back(centerCenterBack1);
     cubes2.push_back(centerRightBack1);
     cubes2.push_back(centerRightBack2);
     cubes2.push_back(centerRightBack3);

     //left row
     cubes3.push_back(leftSide1);
     cubes3.push_back(leftSide2);
     cubes3.push_back(leftSide3);
     cubes3.push_back(leftSide4);
     
     //right row
     cubes4.push_back(rightSide1);
     cubes4.push_back(rightSide2);
     cubes4.push_back(rightSide3);
     cubes4.push_back(rightSide4);
     
     //middle row
     cubes5.push_back(middleCenter1);
     cubes5.push_back(middleCenter2);
     cubes5.push_back(middleCenter3);
     cubes5.push_back(middleCenter4);
     cubes5.push_back(middleCenter5);
     cubes5.push_back(middleCenter6);

     //starting angles
     startingAngles[0] = 0;
     startingAngles[1] = 0;
     startingAngles[2] = 0;
     
     //hallways
     hallway1       = Hallway(cubes1, middle, startingAngles);
     hallway2       = Hallway(cubes2, middle, startingAngles);
     hallway3       = Hallway(cubes3, middle, startingAngles);
     hallway4       = Hallway(cubes4, middle, startingAngles);
     middleHallway  = Hallway(cubes5, middle, startingAngles);
     //hallway5 = Hallway(cubes5, middle, startingAngles);
     
     /**************************************************************/
     //Display list
     //glNewList(dlCenterLeftFront1, GL_COMPILE);
     
     
     //glEndList();
     
     
     /*************************************************************/
     
     delay = 20;
     
     stage.addSprite(&hallway1);
     stage.addSprite(&hallway2);
     stage.addSprite(&hallway3);
     stage.addSprite(&hallway4);
     stage.addSprite(&middleHallway);

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
