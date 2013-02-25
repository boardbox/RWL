#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "Vector.h"
#include "Camera.h"
#include "Floor.h"
#include "God.h"

const int def_x = 640;
const int def_y = 480;
const int maxTerrain = 5;
const char *name = "Robots with Lasers";

God::God():
	alive(true),redo(false),
	window(name,def_x,def_y),
	things(NULL),player(NULL),eye(NULL){
	srand(time(NULL));
}

void God::newGame(){
	forgetAll();
	generateTerrain();
	setStartAgents();
}

void God::forgetAll(){
	delete robots;
	robots = NULL;
	delete terrain;
	terrain = NULL;
	eye.reset();
}

void God::generateTerrain(){
	terrain = new Floor();
	int num = rand() % maxTerrain + 1;
	for(int i=0;i<num;i++){
		terrain.setNext(new Terrain(xWMax,yWMax));
		terrain = terrain.getNext();
	}
}

void God::setStartAgents(){}

void God::setPlayer(Agent *p){
	player = p;
}

void God::setWorld(){
	if(player == NULL){
		fprintf(stderr,"Player not initialized");
	}
	things = new Floor();
}
