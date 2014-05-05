//
//  OrientationFactory.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/1/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "OrientationFactory.h"
#include <stdio.h>
static GLfloat floorMapping[][2] =
{
    {1.0,1.0},
    {1.0, 0.0},
    {0.0, 0.0},
    {0.0, 1.0}
};

static GLfloat ceilingMapping[][2] =
{
    {1.0,0.0},
    {0.0, 0.0},
    {0.0, 1.0},
    {1.0, 1.0}
};

static GLfloat wallMapping[][2] =
{
    {0.0,0.0},
    {0.0, 1.0},
    {1.0, 1.0},
    {1.0, 0.0}
};

static GLfloat backMapping[][2] =
{
    {1.0,1.0},
    {1.0, 0.0},
    {0.0, 0.0},
    {0.0, 1.0}
};

static GLfloat frontMapping[][2] =
{
    {0.0,1.0},
    {1.0, 1.0},
    {1.0, 0.0},
    {0.0, 0.0}
};

static GLfloat leftWallMapping[][2] =
{
    {0.0,1.0},
    {1.0, 1.0},
    {1.0, 0.0},
    {0.0, 0.0}
};

static GLfloat rightWallMapping[][2] =
{
    {1.0,1.0},
    {1.0, 0.0},
    {0.0, 0.0},
    {0.0, 1.0}
};

OrientationFactory::OrientationFactory()
{
    //nothing
}

void OrientationFactory::getBackMapping(GLfloat**& wall)
{
    wall[0][0] = backMapping[0][0];
    wall[0][1] = backMapping[0][1];
    wall[1][0] = backMapping[1][0];
    wall[1][1] = backMapping[1][1];
    wall[2][0] = backMapping[2][0];
    wall[2][1] = backMapping[2][1];
    wall[3][0] = backMapping[3][0];
    wall[3][1] = backMapping[3][1];
}

void OrientationFactory::getCeilingMapping(GLfloat**& ceiling)
{
    ceiling[0][0] = ceilingMapping[0][0];
    ceiling[0][1] = ceilingMapping[0][1];
    ceiling[1][0] = ceilingMapping[1][0];
    ceiling[1][1] = ceilingMapping[1][1];
    ceiling[2][0] = ceilingMapping[2][0];
    ceiling[2][1] = ceilingMapping[2][1];
    ceiling[3][0] = ceilingMapping[3][0];
    ceiling[3][1] = ceilingMapping[3][1];
}

void OrientationFactory::getFloorMapping(GLfloat**& floor)
{
    floor[0][0] = floorMapping[0][0];
    floor[0][1] = floorMapping[0][1];
    floor[1][0] = floorMapping[1][0];
    floor[1][1] = floorMapping[1][1];
    floor[2][0] = floorMapping[2][0];
    floor[2][1] = floorMapping[2][1];
    floor[3][0] = floorMapping[3][0];
    floor[3][1] = floorMapping[3][1];
}


void OrientationFactory::getFrontMapping(GLfloat**& wall)
{
    wall[0][0] = frontMapping[0][0];
    wall[0][1] = frontMapping[0][1];
    wall[1][0] = frontMapping[1][0];
    wall[1][1] = frontMapping[1][1];
    wall[2][0] = frontMapping[2][0];
    wall[2][1] = frontMapping[2][1];
    wall[3][0] = frontMapping[3][0];
    wall[3][1] = frontMapping[3][1];
}

void OrientationFactory::getLeftWallMapping(GLfloat**& wall)
{
    wall[0][0] = leftWallMapping[0][0];
    wall[0][1] = leftWallMapping[0][1];
    wall[1][0] = leftWallMapping[1][0];
    wall[1][1] = leftWallMapping[1][1];
    wall[2][0] = leftWallMapping[2][0];
    wall[2][1] = leftWallMapping[2][1];
    wall[3][0] = leftWallMapping[3][0];
    wall[3][1] = leftWallMapping[3][1];
}

void OrientationFactory::getRightWallMapping(GLfloat**& wall)
{
    wall[0][0] = rightWallMapping[0][0];
    wall[0][1] = rightWallMapping[0][1];
    wall[1][0] = rightWallMapping[1][0];
    wall[1][1] = rightWallMapping[1][1];
    wall[2][0] = rightWallMapping[2][0];
    wall[2][1] = rightWallMapping[2][1];
    wall[3][0] = rightWallMapping[3][0];
    wall[3][1] = rightWallMapping[3][1];
}

void OrientationFactory::getWallMapping(GLfloat**& wall)
{
    wall[0][0] = wallMapping[0][0];
    wall[0][1] = wallMapping[0][1];
    wall[1][0] = wallMapping[1][0];
    wall[1][1] = wallMapping[1][1];
    wall[2][0] = wallMapping[2][0];
    wall[2][1] = wallMapping[2][1];
    wall[3][0] = wallMapping[3][0];
    wall[3][1] = wallMapping[3][1];
}






