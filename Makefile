Lab7.out: main.o transverseMaze.o readMaze.o
	g++ -o Maze.out main.o transverseMaze.o readMaze.o

main.o: main.cpp transverseMaze.cpp readMaze.cpp
	g++ -c main.cpp transverseMaze.cpp readMaze.cpp

transverseMaze.o: transverseMaze.cpp
	g++ -c transverseMaze.cpp

readMaze.o: readMaze.cpp
	g++ -c readMaze.cpp

clean:
	rm *.o Maze.out