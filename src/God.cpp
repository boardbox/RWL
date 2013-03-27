#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <GL/glfw.h>
#include "Vector.h"
#include "ILinkedList.h"
#include "Agent.h"
#include "Camera.h"
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

bool selectStatus = false;

God::God():
	alive(true),redo(false),
	window(name,def_x,def_y),
	tHead(NULL),terrain(NULL),eye(NULL){
	srand(time(NULL));
	window.openWindow();
}

void God::newGame(){
	redo = false;
	forgetAll();
	generateTerrain();
}

void God::forgetAll(){
	delete terrain;
	terrain = NULL;
	if(eye == NULL) eye = new Camera(iLoc,iTar,iUp);
	else eye->set(iLoc,iTar,iUp);
}

void God::generateTerrain(){
	terrain = new Terrain(3);
	tHead = terrain;
	int num = rand() % maxTerrain + 1;
	for(int i=0;i<num;i++){
		terrain->setNext(new Terrain(xWorld,yWorld));
		terrain = (Terrain*) terrain->getNext();
		terrain->setNext(NULL);
	}
}

void God::draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	terrain = tHead;
	while(terrain != NULL){
		terrain->draw();
		terrain = (Terrain*) terrain->getNext();
	}
}

Vector God::getWorldCoord(int mx,int my){
	Vector vr; //view ray
	eye->getViewRay(vr,mx,my);
	double zrat = -eye->loc.z / vr.z;
	double yg = zrat*vr.y + eye->loc.y;
	double xg = zrat*vr.x + eye->loc.x;
	fprintf(stderr,"mouse: %d mouse: %d\n",mx,my);
	fprintf(stderr,"world: %f world: %f\n",xg,yg);
	vr.x = xg;
	vr.y = yg;
	vr.z = 0;
	return vr;
}

void God::input(){
	//camera controls go here
	if(glfwGetKey('W')) eye->move(1,0,0);
	if(glfwGetKey('S')) eye->move(-1,0,0);
	if(glfwGetKey('A')) eye->move(0,-1,0);
	if(glfwGetKey('D')) eye->move(0,1,0);
	if(glfwGetKey('R')) eye->move(0,0,1);
	if(glfwGetKey('F')) eye->move(0,0,-1);
	if(glfwGetKey('Q')) eye->rotate(1);
	if(glfwGetKey('E')) eye->rotate(-1);
	if(glfwGetKey('T')) eye->zoom(-1);
	if(glfwGetKey('G')) eye->zoom(1);
	eye->reLook();
}
