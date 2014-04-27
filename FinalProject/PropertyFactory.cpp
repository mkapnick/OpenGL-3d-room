//
//  PropertyFactory.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 4/26/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "PropertyFactory.h"


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



PropertyFactory::PropertyFactory()
{
    
}

CubeProperties PropertyFactory::getLeftCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesLeftHallway, facesLeftHallwayExcept, vertices, leftVerticesOnExcept, "Users/michaelk18/image");
    
    return properties;
}
CubeProperties PropertyFactory::getRightCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesRightHallway, facesRightHallwayExcept, vertices, rightVerticesOnExcept, "Users/michaelk18/image");
    
    return properties;
}
CubeProperties PropertyFactory::getFrontCubeProperties()
{
    return getLeftCubeProperties();
}
CubeProperties PropertyFactory::getBackCubeProperties()
{
    return getLeftCubeProperties();
}
CubeProperties PropertyFactory::getMiddleCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesMiddleHallway, facesMiddleHallwayExcept, wideVertices, middleVerticesOnExcept, "Users/michaelk18/image");
    return properties;
}





