#include "Stage.h"
#include "Cube.h"
#include "Model.h"
#include "PropertyFactory.h"
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
static GLuint         dlCenterLeftFront1;
int                   window;
static GLint facesFrontHallway;
static GLint facesBackHallway;


//static GLfloat verticesRightHallway[][3];




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
     delay = 20;
     glutInit(&argc, argv);
     window = createWindow("Stage", 640, 480, 0, 0);
     glutDisplayFunc(display);
     glutMouseFunc(mouse);
     glutKeyboardFunc(keyboard);
     glutSpecialFunc(keySpecial);
     glutTimerFunc(delay, timer, 0);
     
     Cube               leftHallway, rightHallway, backHallway, frontHallway, middleHallway;
     CubeProperties     leftHallwayProperties, righHallwayProperties, frontHallwayProperties,backHallwayProperties, middleHallwayProperties;
     PropertyFactory    factory;
     Model              model;
     BaseCube           middle;
     vector<Cube>       cubes1;
     GLfloat            startingAngles[3];
     
     startingAngles[0] = 0;
     startingAngles[1] = 0;
     startingAngles[2] = 0;
     
     factory                = PropertyFactory();
     leftHallwayProperties  = factory.getLeftCubeProperties();
     righHallwayProperties  = factory.getRightCubeProperties();
     frontHallwayProperties = factory.getFrontCubeProperties();
     backHallwayProperties  = factory.getBackCubeProperties();
     middleHallwayProperties= factory.getMiddleCubeProperties();
     
     middle             = BaseCube(0, 0, -15, 10.0);
     leftHallway        = Cube(-60, 0, -15, startingAngles, leftHallwayProperties);
     rightHallway       = Cube(60, 0, -15, startingAngles, righHallwayProperties);
     middleHallway      = Cube(0,0,-15,startingAngles, middleHallwayProperties);

     startingAngles[1]  = 90;
     frontHallway       = Cube(0, 0, 45, startingAngles, frontHallwayProperties);
     backHallway        = Cube(0, 0, -75, startingAngles, backHallwayProperties);
     startingAngles[1]  = 0;
    
     cubes1.push_back(leftHallway);
     cubes1.push_back(rightHallway);
     cubes1.push_back(frontHallway);
     cubes1.push_back(backHallway);
     cubes1.push_back(middleHallway);

     model       = Model(cubes1, middle, startingAngles);
     stage.addSprite(&model);
     stage.start();
     return 0;
 }
