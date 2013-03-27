#include <GL/glfw.h>
#include "WinMgr.h"

//constructor
WinMgr::WinMgr(const char *name, int x, int y):
	appName(name),xWinSize(x),yWinSize(y)	{}

int WinMgr::openWindow(void){
	if(!glfwInit()) return -1;
	if(!glfwOpenWindow(0,0,0,0,0,0,5000,0,GLFW_WINDOW)) return -1;
	glfwSetWindowTitle(appName);
	glEnable(GL_DEPTH_TEST);
	return 1;
}

WinMgr::~WinMgr(){
	glfwCloseWindow();
	glfwTerminate();
}
