#include <iostream>
#include <fstream>

using namespace std;

class transverseMaze {
    int rows;  
    int cols;
    int startrow;
    int startcol;
    int ** path; //2D array to store the path used to exit the maze
    int count;
    char ** maze; //2D array to store the maze from file
public:
    transverseMaze();
    void setrows(int value){
        rows = value;
    }
    void setcols(int value){
        cols = value;
    }
    void setstartrow(int value){
        startrow = value;
    }
    void setstartcol(int value){
        startcol = value;
    }
    void setMaze(char ** value){
        maze = value;
    }
    void initPath();
    
    bool scanmaze(char ** maze, int row, int col);
    
    void printPath();
    
    void transMaze();
};