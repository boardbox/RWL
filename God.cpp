#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "Vector.h"
#include "Object.h"
#include "Agent.h"
#include "Camera.h"
#include "Floor.h"
#include "Terrain.h"
#include "God.h"

const int def_x = 640;
const int def_y = 480;
const int maxTerrain = 5;
const double xWorld = 200;
const double yWorld = 100;
const char *name = "Robots with Lasers";

const Vector iUp(0,0,1);
const Vector iLoc(100,200,50);
const Vector iTar(100,0,0);

God::God():
	alive(true),redo(false),
	window(name,def_x,def_y),
	tHead(NULL),terrain(NULL),rHead(NULL),robots(NULL),eye(NULL){
	window.openWindow();
}

void God::newGame(){
	redo = false;
	forgetAll();
	generateTerrain();
	setStartAgents();
}

void God::forgetAll(){
	delete robots;
	robots = NULL;
	delete terrain;
	terrain = NULL;
	if(eye == NULL) eye = new Camera(iLoc,iTar,iUp);
	else eye->set(iLoc,iTar,iUp);
}

void God::generateTerrain(){
	terrain = new Floor(xWorld,yWorld);
	tHead = terrain;
	int num = rand() % maxTerrain + 1;
	for(int i=0;i<num;i++){
		terrain->setNext(new Terrain(xWorld,yWorld));
		terrain = terrain->getNext();
		terrain->setNext(NULL);
	}
}

void God::setStartAgents(){}

void God::draw(){
	terrain = tHead;
	while(terrain != NULL){
		terrain->draw();
		terrain = terrain->getNext();
	}
}
