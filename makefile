CC = g++
LIBS = -lGL -lGLU -lglfw
FLAGS = -c -Wall -g
OBJECTS = main.o Vector.o Object.o WinMgr.o Floor.o Camera.o Agent.o Terrain.o God.o

app: Robots

Robots : $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o Robots

main.o : main.cpp
	$(CC) $(FLAGS) main.cpp

Vector.o : Vector.h Vector.cpp 
	$(CC) $(FLAGS) Vector.cpp

Object.o : Object.h Object.cpp Vector.h
	$(CC) $(FLAGS) Object.cpp

WinMgr.o : WinMgr.h WinMgr.cpp
	$(CC) $(FLAGS) WinMgr.cpp

Floor.o : Object.h Floor.h Floor.cpp
	$(CC) $(FLAGS) Floor.cpp

Camera.o : Vector.h Object.h Camera.h Camera.cpp
	$(CC) $(FLAGS) Camera.cpp

Agent.o : Agent.h Agent.cpp Object.h Vector.h
	$(CC) $(FLAGS) Agent.cpp

God.o : God.h God.cpp Vector.h Object.h Agent.h Camera.h Floor.h Terrain.h
	$(CC) $(FLAGS) God.cpp
clean :
	rm -rf *.o Robots
