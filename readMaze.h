#include <iostream>
#include <fstream>

using namespace std;

class readMaze{
  int rows;  
  int cols;
  int startrow;
  int startcol;
  char ** maze; //2D array use to store the maze from the file
 public: 
    readMaze();
    //method to read the file
    int readFile(char * filename);
    
    int getrows(){
        return rows;
    }
    
    int getcols(){
        return cols;
    }
    
    int getstartrow(){
        return startrow;
    }
    
    int getstartcol(){
        return startcol;
    }
    char ** getMaze(){
        return maze;
    }
};