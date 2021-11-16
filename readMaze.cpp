#include "readMaze.h"

readMaze::readMaze(){
    int rows = 0;  
    int cols = 0;
    int startrow = 0;
    int startcol = 0;
}


int readMaze::readFile(char * filename){
        ifstream fin(filename);
        if(fin.fail()){//file not found check
            return -1;
        }
        //reading number of rows and columns of maze and start row and column
        fin>>rows;
        fin.ignore();
        fin>>cols;
        fin>>startrow;
        fin.ignore();
        fin>>startcol;
        //doing file format checks
        if(startrow < 0 || startrow > rows || startcol < 0 || startcol > cols){
            return -2;
        }
        if(rows < 1 || cols < 1){
            return -3;
        }
        //reading the maze from the file
        string buff;
        getline(fin,buff);
        maze = new char * [rows];
        for(int i=0; i<rows; i++){
            maze[i] = new char[cols];
        }
        int i = 0, j = 0;
        while(!fin.eof()){
            getline(fin,buff);
            j = 0;
            while(buff[j] != '\0'){
                maze[i][j] = buff[j];
                j++;
            }
            i++;
        }
        if(maze[startrow][startcol] != 'P'){ // start point validation check
            return -4;
        }
        return 1;
    }