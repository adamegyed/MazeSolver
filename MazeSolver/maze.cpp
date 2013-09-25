//
//  maze.cpp
//  MazeSolver
//
//  Created by Adam Egyed on 9/21/13.
//  Copyright (c) 2013 Adam Egyed. All rights reserved.
//


#include "maze.h"


Maze::Maze(unsigned int xSize,unsigned int ySize) {
  hWall_ = (int*)malloc(sizeof(int)*(xSize * (ySize + 1)));
  vWall_ = (int*)malloc(sizeof(int)*(ySize * (xSize + 1)));
  if ((hWall_ == NULL) || (vWall_ == NULL)) {
    std::cerr<<"Failed to malloc space for walls"<<std::endl;
    exit(1);
  }
  xSize_ = xSize;
  ySize_ = ySize;
}
Maze::~Maze() {
  free(hWall_);
  free(vWall_);
}

void Maze::setWall(int xCoord, int yCoord, int side) {
  specWall_(xCoord, yCoord, side, true);
}
void Maze::delWall(int xCoord, int yCoord, int side) {
  specWall_(xCoord, yCoord, side, false);
}


void Maze::specWall_(int xCoord, int yCoord, int side, bool make) {
  int setValue = 0;
  if (make) setValue = 1;
  if (xCoord<0||xCoord>=xSize_||yCoord<0||yCoord>=ySize_) {
    std::cerr<<"Really?"<<std::endl;
    return;
  }
  if (side & SIDE_UP) {
    hWall_[indexOfDoubleArr(xCoord, yCoord+1, xSize_, ySize_)] = setValue;
  }
  if (side & SIDE_DOWN) {
    hWall_[indexOfDoubleArr(xCoord, yCoord, xSize_, ySize_)] = setValue;
  }
  if (side & SIDE_RIGHT) {
    vWall_[indexOfDoubleArr(xCoord+1, yCoord, xSize_, ySize_)] = setValue;
  }
  if (side & SIDE_LEFT) {
    vWall_[indexOfDoubleArr(xCoord, yCoord, xSize_, ySize_)] = setValue;
  }
}



           

int Maze::indexOfDoubleArr(int x, int y, int xSize, int ySize) {
  return x+(y*xSize);
}



