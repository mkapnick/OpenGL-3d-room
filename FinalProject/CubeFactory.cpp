#include "CubeFactory.h"


/******************** Faces **********************/
static GLint faces[][4]    = {{4,5,6,7}, //front
    {1,2,6,5}, // right
    {0,1,5,4}, // bottom
    {0,3,2,1}, // back
    {0,4,7,3}, // left
    {2,3,7,6}  // top
};
static GLint facesLeftHallway [][4] =
{{4,5,6,7}, // front
    {-1,-1,-1,-1},    //take out the right face
    {0,1,5,4},  // bottom
    {0,3,2,1},  // back
    {0,4,7,3},  // left
    {2,3,7,6}   // top
};
static GLint facesRightHallway [][4] =
{{4,5,6,7}, //front
    {1,2,6,5}, // right
    {0,1,5,4}, // bottom
    {0,3,2,1}, // back
    {-1,-1,-1,-1},  // take out the left face
    {2,3,7,6}  // top
};

static GLint facesMiddleHallway[][4] =
{{4,5,6,7}, //front
    {-1,-1,-1,-1}, // right
    {0,1,5,4}, // bottom
    {0,3,2,1}, // back
    {-1,-1,-1,-1}, // left
    {2,3,7,6}  // top
};

static GLint facesLeftHallwayExcept[][4] =
{{-1,-1,-1,-1}, // front
    {1,2,6,5},   // right
    {-1,-1,-1,-1},  // bottom
    {-1,-1,-1,-1},  // back
    {-1,-1,-1,-1},  // left
    {-1,-1,-1,-1}   // top
};
static GLint facesRightHallwayExcept[][4] =
{{-1,-1,-1,-1}, // front
    {-1,-1,-1,-1}, //right
    {-1,-1,-1,-1},  // bottom
    {-1,-1,-1,-1},  // back
    {0,4,7,3},  // left
    {-1,-1,-1,-1}   // top
};

static GLint facesMiddleHallwayExcept[][4] =
{{-1,-1,-1,-1}, // front
    {1,2,6,5},    //right
    {-1,-1,-1,-1},  // bottom
    {-1,-1,-1,-1},  // back
    {0,4,7,3},  // left
    {-1,-1,-1,-1}   // top
};

/***************** Vertices ***********************/
static GLfloat wideVertices[][3] = {{-20.0,-10.0,-70.0},
    { 20.0,-10.0,-70.0},
    { 20.0, 10.0,-70.0},
    {-20.0, 10.0,-70.0},
    {-20.0,-10.0, 70.0},
    { 20.0,-10.0, 70.0},
    { 20.0, 10.0, 70.0},
    {-20.0, 10.0, 70.0}
};

static GLfloat vertices[][3] = {{-10.0,-10.0,-70.0},
    { 10.0,-10.0,-70.0},
    { 10.0, 10.0,-70.0},
    {-10.0, 10.0,-70.0},
    {-10.0,-10.0, 70.0},
    { 10.0,-10.0, 70.0},
    { 10.0, 10.0, 70.0},
    {-10.0, 10.0, 70.0}
};
static GLfloat leftVerticesOnExcept[][3] =
{{-10.0,-10.0,-70.0},
    { 10.0,-10.0,-50.0},
    { 10.0, 10.0,-50.0},
    {-10.0, 10.0,-70.0},
    {-10.0,-10.0, 70.0},
    { 10.0,-10.0, 50.0},
    { 10.0, 10.0, 50.0},
    {-10.0, 10.0, 70.0}
};
static GLfloat rightVerticesOnExcept[][3] =
{{-10.0,-10.0,-50.0},
    { 10.0,-10.0,-70.0},
    { 10.0, 10.0,-70.0},
    {-10.0, 10.0,-50.0},
    {-10.0,-10.0, 50.0},
    { 10.0,-10.0, 70.0},
    { 10.0, 10.0, 70.0},
    {-10.0, 10.0, 50.0}
};

static GLfloat middleVerticesOnExcept[][3] =
{{-20.0,-10.0,-50.0},
    { 20.0,-10.0,-50.0},
    { 20.0, 10.0,-50.0},
    {-20.0, 10.0,-50.0},
    {-20.0,-10.0, 50.0},
    { 20.0,-10.0, 50.0},
    { 20.0, 10.0, 50.0},
    {-20.0, 10.0, 50.0}
};


CubeFactory::CubeFactory()
{
    // nothing
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



