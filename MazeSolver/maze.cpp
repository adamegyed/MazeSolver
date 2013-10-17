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

bool Maze::isWall(int xCoord,int yCoord,int side) {
  if (xCoord<0||xCoord>=xSize_||yCoord<0||yCoord>=ySize_) {
    std::cerr<<"Really?"<<std::endl;
    return false;
  }
  if (side & SIDE_UP) {
    if(hWall_[indexOfDoubleArr(xCoord, yCoord+1, xSize_, ySize_)] == 1) {
      return true;
    }
    else return false;
  }
  if (side & SIDE_DOWN) {
    if(hWall_[indexOfDoubleArr(xCoord, yCoord, xSize_, ySize_)] == 1) {
      return true;
    }
    else return false;
  }
  if (side & SIDE_RIGHT) {
    if (vWall_[indexOfDoubleArr(xCoord+1, yCoord, xSize_, ySize_)] == 1) {
      return true;
    }
    else return false;
  }
  if (side & SIDE_LEFT) {
    if (vWall_[indexOfDoubleArr(xCoord, yCoord, xSize_, ySize_)] == 1) {
      return true;
    }
    else return false;
  }
  return false;
}


void Maze::printM() {

  for (int y=(ySize_-1);y>=0; y--) {
    
    for (int x=0;x<xSize_; x++) {
      
      std::cout<<"+";
      
      if (isWall(x,y,SIDE_UP)) {
        std::cout<<"--";
      }
      else std::cout<<"  ";
    }
    std::cout<<"+"<<std::endl;
    
    for (int x=0;x<xSize_; x++) {
      
      
      if (isWall(x,y,SIDE_LEFT)) {
        std::cout<<"|  ";
      }
      else std::cout<<"   ";
    }
    if (isWall(xSize_-1,y,SIDE_RIGHT)) {
      std::cout<<"|"<<std::endl;
    }
    else std::cout<<" "<<std::endl;

    
    
  }
  //draw last line of maze, if present
  for (int x=0;x<xSize_; x++) {
    
    std::cout<<"+";
    
    if (isWall(x,0,SIDE_DOWN)) {
      std::cout<<"--";
    }
    else std::cout<<"  ";
  }
  std::cout<<"+"<<std::endl;

  
  
  
  // for (y=(ymax-1); y>=0; y--) {
  //    for (x=0; x<xmax; x++) {
  //       // figure out for this square which walls are set
  //
  //+--+
  //|  |
  //+--+
}

           

int Maze::indexOfDoubleArr(int x, int y, int xSize, int ySize) {
  return x+(y*xSize);
}

void Maze::surroundMaze() {
  //bottom + top layer
  for (int x=0;x<xSize_;x++) {
    setWall(x,0,SIDE_DOWN);
    setWall(x,ySize_-1,SIDE_UP);
  }
  for (int y=0;y<ySize_;y++) {
    setWall(0,y,SIDE_LEFT);
    setWall(xSize_-1,y,SIDE_RIGHT);
  }
}



