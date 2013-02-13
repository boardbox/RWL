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
const bool gameOver = false;
const char *title = "Robots with Lasers";

int
main(void){
	//start up window crap
	WinMgr window(title, xWinSize, yWinSize);
	Floor f;
	if(window.openWindow() != 1){
		fprintf(stderr,"Failure at window initialization\n");
	}
	//do some menu stuff here
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Vector eye(30,30,30);
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
			glfwSwapBuffers();
		}
	}
	//do the clean up crap and exit
	return 1;
}
