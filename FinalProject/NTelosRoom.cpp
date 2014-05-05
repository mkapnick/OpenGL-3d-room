//
//  NTelosRoom.cpp
//  FinalProject
//
//  Created by Michael Kapnick on 5/4/14.
//  Copyright (c) 2014 Michael Kapnick. All rights reserved.
//

#include "NTelosRoom.h"

NTelosRoom::NTelosRoom(vector<Cube> cubes)
{
    this->cubes = cubes;
    //setUpVisibleFaces();
}

NTelosRoom::NTelosRoom()
{
    //nothing
}

void NTelosRoom::setUpVisibleFaces()
{
    for(int i =0; i < this->cubes.size(); i++)
    {
        //if(i ==0)
    }
}

vector<Cube> NTelosRoom::getCubes()
{
    return this->cubes;
}