#include "Stage.h"
#include "Cube.h"
#include "Model.h"
#include "CubeFactory.h"
#include "Faces.h"
#include "Hallway.h"
#include "JmuFrontHallway.h"
#include "JmuBackHallway.h"
#include "JmuLeftHallway.h"
#include "JmuRightHallway.h"
#include "JmuMiddleHallway.h"

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
    
    
    glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE | GLUT_RGB);
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

     
     char* testImages[] = {"/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/left_hallways_floor.raw", "/raws/plain_wall.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"};
     
     CubeFactory        factory;
     Model              model;
     BaseCube           middle;
     vector<Cube>       cubes;
     vector<Hallway*>   hallways;
     Cube               nTelasRoom, nTelasRoomHallway;
     CubeProperties     properties;
     GLfloat            startingAngles[3];
     Hallway           *jmuFront, *jmuBack, *jmuRight, *jmuLeft, *jmuMiddle;
     Position           position;
     
     startingAngles[0] = 0;
     startingAngles[1] = 0;
     startingAngles[2] = 0;
     
     properties = CubeProperties();
     factory    = CubeFactory();
     
     /***Front Hallway ***/
     startingAngles[1]  = 90;
     properties.setCubeVertices(10, 10, 10);
     properties.setImages(FRONTH);
     cubes      = factory.createUniformCubes(-120, 0, 45, 13, startingAngles, properties, 20, 0,0);
     jmuFront = new JmuFrontHallway(cubes);
     hallways.push_back(jmuFront);
          
     /***Back Hallway ***/
     startingAngles[1]  = -90;
     properties.setImages(BACKH);
     cubes      = factory.createUniformCubes(-120, 0, -195, 13, startingAngles, properties, 20,0,0);
     jmuBack    = new JmuBackHallway(cubes);
     hallways.push_back(jmuBack);
     
     startingAngles[1]  = 0;
     
     /***Left Hallway ***/
     properties.setImages(LEFTH);
     cubes      = factory.createUniformCubes(-120, 0, 45, 13, startingAngles, properties, 0,0,-20);
     jmuLeft    = new JmuLeftHallway(cubes);
     hallways.push_back(jmuLeft);
     
     /***Right Hallway ***/
     properties.setImages(RIGHTH);
     cubes      = factory.createUniformCubes(120, 0, 45, 13, startingAngles, properties, 0,0,-20);
     jmuRight   = new JmuRightHallway(cubes);
     hallways.push_back(jmuRight);
     
     /***Middle Hallway ***/
     properties.setCubeVertices(30, 10, 10);
     properties.setImages(MIDDLEH);
     cubes      = factory.createUniformCubes(0, 0, 45, 13, startingAngles, properties, 0,0,-20);
     jmuMiddle  = new JmuMiddleHallway(cubes);
     hallways.push_back(jmuMiddle);

     /*leftHallwayProperties      = factory.getLeftCubeProperties();
     righHallwayProperties      = factory.getRightCubeProperties();
     frontHallwayProperties     = factory.getFrontCubeProperties();
     backHallwayProperties      = factory.getBackCubeProperties();
     middleHallwayProperties    = factory.getMiddleCubeProperties();*/
     
     /*nTelasProperties           = factory.getCubeProperties(40, 10, 30, testImages);
     
     leftHallway        = Cube(-60, 0, -15, startingAngles, leftHallwayProperties);
     rightHallway       = Cube(60, 0, -15, startingAngles, righHallwayProperties);
     middleHallway      = Cube(0,0,-15,startingAngles, middleHallwayProperties);
     nTelasRoom         = Cube(-50,0,-150, startingAngles, nTelasProperties);
     
     nTelasProperties = factory.getCubeProperties(10, 10, 20, testImages);
     nTelasRoomHallway  = Cube(-50,0,-100, startingAngles, nTelasProperties);

     startingAngles[1]  = 90;
     frontHallway       = Cube(0, 0, 45, startingAngles, frontHallwayProperties);
     
     startingAngles[1]  = -90;
     backHallway        = Cube(0, 0, -75, startingAngles, backHallwayProperties);
     startingAngles[1]  = 0;*/
    
     /*cubes1.push_back(leftHallway);
     cubes1.push_back(rightHallway);
     cubes1.push_back(backHallway);
     cubes1.push_back(frontHallway);
     cubes1.push_back(middleHallway);
     cubes1.push_back(nTelasRoom);
     cubes1.push_back(nTelasRoomHallway);
     */
     
     middle      = BaseCube(0, 0, -15, 10.0);
     model       = Model(hallways, middle, startingAngles);
     stage.addSprite(&model);
     stage.start();
     
     return 0;
 }

