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

static char* images [][6] =
{
    /*middleHallway
    {"/raws/main_ceiling.raw", "/raws/main_floor.raw", "/raws/main_wall_brick.raw", "/raws/main_wall_brick.raw", "/raws/main_front_5282.raw", "/raws/exit_2704.raw"},
    
    //frontHallway
    {"/raws/ceiling.raw", "/raws/left_hallways_floor.raw", "/raws/plain_wall.raw", "/raws/IMG_5992.raw", "/raws/plain_wall.raw", "/raws/exit_2704.raw"},
    
    //backHallway
    {"/raws/ceiling.raw", "/raws/lab_floor_8034.raw", "/raws/IMG_6427.raw", "/raws/IMG_6643.raw", "/raws/grove_door_end.raw", "/raws/exit_2704.raw"},
    
    //leftHallway
    {"/raws/ceiling.raw", "/raws/left_hallways_floor.raw", "/raws/plain_wall.raw", "/raws/plain_wall.raw", "/raws/exit_2704.raw", "/raws/exit_2704.raw"},
    
    //rightHallway
    {"/raws/ceiling.raw", "/raws/rug.raw", "/raws/IMG_0512.raw", "/raws/IMG_5992.raw", "/raws/IMG_2363.raw", "/raws/exit_2704.raw"}*/
    
    
    //middleHallway
    {"/raws/main_front_5282.raw", "/raws/main_wall_brick.raw", "/raws/main_floor.raw", "/raws/james-madison-u.raw", "/raws/main_wall_brick.raw", "/raws/main_ceiling.raw"},
    
    //frontHallway
    {"/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/left_hallways_floor.raw", "/raws/plain_wall.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //backHallway
    {"/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/left_hallways_floor.raw", "/raws/grove_door_end.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //leftHallway
    {"/raws/exit_2704.raw","/raws/plain_wall.raw", "/raws/left_hallways_floor.raw","/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"},
    
    //rightHallway
    {"/raws/exit_2704.raw", "/raws/plain_wall.raw",  "/raws/rug.raw","/raws/exit_2704.raw", "/raws/plain_wall.raw", "/raws/ceiling.raw"}
};


PropertyFactory::PropertyFactory()
{
    
}

CubeProperties PropertyFactory::getLeftCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesLeftHallway, facesLeftHallwayExcept, vertices, leftVerticesOnExcept, images[3]);
    
    return properties;
}
CubeProperties PropertyFactory::getRightCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesRightHallway, facesRightHallwayExcept, vertices, rightVerticesOnExcept, images[4]);
    
    return properties;
}
CubeProperties PropertyFactory::getFrontCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesLeftHallway, facesLeftHallwayExcept, vertices, leftVerticesOnExcept, images[1]);
    
    return properties;
}
CubeProperties PropertyFactory::getBackCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesLeftHallway, facesLeftHallwayExcept, vertices, leftVerticesOnExcept, images[2]);
    
    return properties;
}
CubeProperties PropertyFactory::getMiddleCubeProperties()
{
    CubeProperties properties;
    properties = CubeProperties(facesMiddleHallway, facesMiddleHallwayExcept, wideVertices, middleVerticesOnExcept, images[0]);
    return properties;
}

void PropertyFactory::getDisplayListLeftHallway(GLuint &holder)
{
    glNewList(holder, GL_COMPILE);
    glEndList();

}
void PropertyFactory::getDisplayListRightHallway(GLuint &holder)
{
    
}
void PropertyFactory::getDisplayListMiddleHallway(GLuint &holder)
{
    
}
void PropertyFactory::getDisplayListFrontHallway(GLuint &holder)
{
    
}
void PropertyFactory::getDisplayListBackHallway(GLuint &holder)
{
    
}





