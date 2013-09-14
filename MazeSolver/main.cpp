//
//  main.cpp
//  MazeSolver
//
//  Created by Adam Egyed on 9/13/13.
//  Copyright (c) 2013 Adam Egyed. All rights reserved.
//

#include <iostream>

#define MAX_SIZE_X 30
#define MAX_SIZE_Y 30

using namespace std;

int main(int argc, const char * argv[])
{
  int xinput;
  int yinput;
  
  do{
  cout<<"How tall would you like your maze to be?";
  cin>>xinput;
  }while(xinput>MAX_SIZE_X);
  
  do{
    cout<<"How wide would you like your maze to be?";
    cin>>yinput;
  }while(yinput>MAX_SIZE_X);
  

  
  
}

