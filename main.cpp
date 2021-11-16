#include <iostream>
#include <fstream>
#include "readMaze.h"
#include "transverseMaze.h"
using namespace std;

int main(int argv, char * argc[])
{
    readMaze readm;
    int filesuccess = readm.readFile(argc[1]);
    if(filesuccess == 1){
        transverseMaze transM;
    
        transM.setrows(readm.getrows());
        transM.setcols(readm.getcols());
        transM.setstartrow(readm.getstartrow());
        transM.setstartcol(readm.getstartcol());
        transM.setMaze(readm.getMaze());
    
        transM.transMaze();
    }
    else if(filesuccess == -1){
        cout<<"File Not Found!"<<endl;
    }
    else if(filesuccess == -3){
        cout<<"Invalid number of rows or columns!"<<endl;
    }
    else if(filesuccess == -2){
        cout<<"Invalid starting position!"<<endl;
    }
    else if(filesuccess == -4){
        cout<<"Start position is not in a passage!"<<endl;
    }
    return 0;
}
