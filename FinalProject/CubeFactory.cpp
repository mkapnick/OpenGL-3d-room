#include "CubeFactory.h"


CubeFactory::CubeFactory()
{
    // nothing
    //Test: Cube cube;
}

vector<Cube> CubeFactory::createUniformCubes(GLfloat x,GLfloat y , GLfloat z, int numberOfCubes, GLfloat startingAngles[3], CubeProperties properties, int stepX, int stepY, int stepZ)
{
    vector <Cube> cubes1;
    Cube cube;

    CubeProperties* copy;
    //Copy Constructor for CubeProperties?
     for (int i =0; i < numberOfCubes; i++)
     {
         copy = new CubeProperties(properties);
         cube = Cube(x, y, z, startingAngles, copy);
         cubes1.push_back(cube);
         x+= stepX;
         y+= stepY;
         z+=stepZ;
     }
    
    return cubes1;
}



