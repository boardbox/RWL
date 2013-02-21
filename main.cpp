#include <cstdio>
#include <cstdlib>
#include <GL/glfw.h>
#include "Vector.h"
#include "WinMgr.h"
#include "Floor.h"
#include "Camera.h"
#include "Agent.h" 

const int xWinSize = 640;
const int yWinSize = 480;
const char *title = "Robots with Lasers";
const Vector up(0,0,1);
bool gameOver = false;

//helper functions
int GLFWCALL closeWindow(){
	gameOver = true;
	return GL_TRUE;
}

void mvPlayer(const Agent& p,const Camera& pcam){ //move player using mouse
	int x,y;
	glfwGetMousePos(&x,&y);
	fprintf(stderr,"mouse x: %d mouse y: %d\n",x,y);
	Vector vr;
	pcam.getViewRay(vr,x,y);
	double zrat = -pcam.loc.z / vr.z;
	double yg = zrat*vr.y + pcam.loc.y;
	double xg = zrat*vr.x + pcam.loc.x;
	fprintf(stderr,"ground x: %f ground y: %f\n",xg,yg);
}

int
main(void){
	//start up window crap
	WinMgr window(title, xWinSize, yWinSize);
	Floor f;
	if(window.openWindow() != 1){
		fprintf(stderr,"Failure at window initialization\n");
	}
	glfwSetWindowCloseCallback(closeWindow);
	//do some menu stuff here
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Vector eye(15,0,15);
	Vector tar(0,0,0);
	Vector up(0,0,1);
	Camera cam(eye,tar,up);
	Agent jim;
	glfwSwapBuffers();
	//do some game stuff after the menu stuff
	glfwSetTime(0);
	double ftime = 0.01666667;
	double ptime = glfwGetTime();
	while(!gameOver){
		if(glfwGetTime() > ptime + ftime){
			f.draw();
			jim.draw();
			ptime = glfwGetTime();
			if(glfwGetKey('Q')) break;
			if(glfwGetKey('W')) jim.loc.y += 1;
			if(glfwGetKey('S')) jim.loc.y -= 1;
			if(glfwGetKey('A')) jim.loc.x -= 1;
			if(glfwGetKey('D')) jim.loc.x += 1;
			if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) mvPlayer(jim,cam);
			glfwSwapBuffers();
		}
	}
	//do the clean up crap and exit
	glfwTerminate();
	return 1;
}
