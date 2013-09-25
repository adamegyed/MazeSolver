//
//  maze.h
//  MazeSolver
//
//  Created by Adam Egyed on 9/21/13.
//  Copyright (c) 2013 Adam Egyed. All rights reserved.
//

#ifndef __MazeSolver__maze__
#define __MazeSolver__maze__

#include <iostream>
#include <stdio.h>

//Origin is in bottom-left, 0-based indices
class Maze {
public:
  Maze(unsigned int xSize,unsigned int ySize);
  ~Maze();
  void setWall(int xCoord, int yCoord, int side);
  void delWall(int xCoord, int yCoord, int side);
  const int SIDE_UP = 1;
  const int SIDE_RIGHT = 2;
  const int SIDE_DOWN = 4;
  const int SIDE_LEFT = 8;
private:
  int indexOfDoubleArr(int x, int y, int xSize, int ySize);
  int* hWall_;
  int* vWall_;
  int xSize_;
  int ySize_;
  void specWall_(int xCoord, int yCoord, int side,bool make);
};


#endif /* defined(__MazeSolver__maze__) */
