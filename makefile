CC = g++
LIBS = -lGL -lGLU -lglfw
FLAGS = -c -Wall -g -Iinclude
OBJECTS = main.o Vector.o Object.o WinMgr.o Floor.o Camera.o Agent.o Terrain.o God.o

app: Robots

Robots : $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o Robots
	rm *.o

main.o : src/main.cpp
	$(CC) $(FLAGS) src/main.cpp

Vector.o : src/Vector.cpp 
	$(CC) $(FLAGS) src/Vector.cpp

Object.o : src/Object.cpp 
	$(CC) $(FLAGS) src/Object.cpp

WinMgr.o : src/WinMgr.cpp
	$(CC) $(FLAGS) src/WinMgr.cpp

Floor.o : src/Floor.cpp
	$(CC) $(FLAGS) src/Floor.cpp

Camera.o : src/Camera.cpp
	$(CC) $(FLAGS) src/Camera.cpp

Agent.o : src/Agent.cpp
	$(CC) $(FLAGS) src/Agent.cpp

God.o : src/God.cpp 
	$(CC) $(FLAGS) src/God.cpp

Terrain.o : src/Terrain.cpp
	$(CC) $(FLAGS) src/Terrain.cpp

clean :
	rm -rf *.o Robots
