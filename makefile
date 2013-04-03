CC = g++
LIBS = -lGL -lGLU -lglfw
FLAGS = -c -Wall -g -Iinclude
OBJECTS = main.o Vector.o ILinkedList.o WinMgr.o Camera.o Terrain.o God.o Piece.o

app: Robots

Robots : $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o Robots

main.o : src/main.cpp
	$(CC) $(FLAGS) src/main.cpp

Vector.o : src/Vector.cpp 
	$(CC) $(FLAGS) src/Vector.cpp

ILinkedList.o: src/ILinkedList.cpp
	$(CC) $(FLAGS) src/ILinkedList.cpp

WinMgr.o : src/WinMgr.cpp
	$(CC) $(FLAGS) src/WinMgr.cpp

Camera.o : src/Camera.cpp
	$(CC) $(FLAGS) src/Camera.cpp

Agent.o : src/Agent.cpp
	$(CC) $(FLAGS) src/Agent.cpp

God.o : src/God.cpp 
	$(CC) $(FLAGS) src/God.cpp

Terrain.o : src/Terrain.cpp
	$(CC) $(FLAGS) src/Terrain.cpp

Piece.o : src/Piece.cpp
	$(CC) $(FLAGS) src/Piece.cpp

clean :
	rm -rf *.o Robots
