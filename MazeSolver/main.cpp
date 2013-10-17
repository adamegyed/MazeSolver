//
//  main.cpp
//  MazeSolver
//
//  Created by Adam Egyed on 9/13/13.
//  Copyright (c) 2013 Adam Egyed. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "maze.h"

#define MAX_SIZE_X 30
#define MAX_SIZE_Y 30

using namespace std;

int main(int argc, const char * argv[])
{
  int xinput;
  int yinput;
  
  do{
  cout<<"How wide would you like your maze to be?"<<endl;
  cin>>xinput;
  }while(xinput>MAX_SIZE_X);
  
  do{
    cout<<"How tall would you like your maze to be?"<<endl;
    cin>>yinput;
  }while(yinput>MAX_SIZE_X);
  
  Maze maze1(xinput,yinput);
  maze1.setWall(9,9,Maze::SIDE_DOWN);
  maze1.surroundMaze();
  maze1.printM();
  return 0;

}



