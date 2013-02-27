#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <GL/glfw.h>
#include "Vector.h"
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
	srand(time(NULL));
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	terrain = tHead;
	while(terrain != NULL){
		terrain->draw();
		terrain = terrain->getNext();
	}
}

void God::input(){
	if(glfwGetKey('W')) eye->move(1,0,0);
	if(glfwGetKey('S')) eye->move(-1,0,0);
	if(glfwGetKey('A')) eye->move(0,-1,0);
	if(glfwGetKey('D')) eye->move(0,1,0);
	if(glfwGetKey('R')) eye->move(0,0,1);
	if(glfwGetKey('F')) eye->move(0,0,-1);
	if(glfwGetKey('Q')) eye->rotate(-1);
	if(glfwGetKey('E')) eye->rotate(1);
	if(glfwGetKey('T')) eye->zoom(-1);
	if(glfwGetKey('G')) eye->zoom(1);
	eye->reLook();
}
