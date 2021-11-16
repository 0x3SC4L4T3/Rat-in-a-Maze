#include "transverseMaze.h"

transverseMaze :: transverseMaze(){
    int rows = 0;  
    int cols = 0;
    int startrow = 0;
    int startcol = 0;
    count = 1;
}

//method to initialize the path 2D array to 0
void transverseMaze :: initPath(){
        path = new int * [rows];
        for(int i = 0; i < rows; i++){
            path[i] = new int[cols];
            for(int j = 0; j < cols; j++){
                path[i][j] = 0;
            }
            
        }
    }
//method to transverse the maze and finding the path to exit the maze if such path exists
bool transverseMaze :: scanmaze(char ** maze, int row, int col){
        
        if(col >= 0 && col < cols && row >= 0 && row < rows){ //  making checks to keep transverse within maze
            //if the exit is encountered
            if(maze[row][col] == 'E'){
                path[row][col] = count;
                return true;
            }
            // if wall is encountered or visiting already visited place
            if(maze[row][col] == 'W' || maze[row][col] == '-'){
                return false;
            }
            //adding place to the path
            maze[row][col] = '-';
            path[row][col] = count;
            count++;
            //up direction
            if(scanmaze(maze,row - 1,col) == true){
                return true;
            }
            //right direction
            if(scanmaze(maze,row, col + 1) == true){
                return true;
            }
            //down direction
            if(scanmaze(maze,row + 1,col) == true){
                return true;
            }
            //left direction
            if(scanmaze(maze,row,col - 1) == true){
                return true;
            }
            //removing place from the path if not valid or not suitable in path 
            maze[row][col] = 'P';
            path[row][col] = 0;
            count--;
            return false;
        }
        else{
            return false;
        }
    }

//method to print the path used to exit the maze
void transverseMaze :: printPath(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout<<path[i][j]<<" ";
            }
            cout << endl;
        }
    }
//Rapper method to transverse the maze using scanmaze method
 void transverseMaze :: transMaze(){
        initPath();
        bool result = scanmaze(maze, startrow, startcol);
        cout<<"Size: "<<rows<<","<<cols<<endl;
        cout<<"Starting Position: "<<startrow<<","<<startcol<<endl;
        if(result == false){
            cout<<"No path found"<<endl;
        }
        else{
            printPath();
            cout<<"We Escaped!"<<endl;
        }
    }