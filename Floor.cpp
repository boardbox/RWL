#include <cmath>
#include <cstdio>
#include <GL/glfw.h>
#include "Object.h"
#include "Floor.h"

Floor::Floor(){}

void Floor::draw() const{
	double xMin = -1000;
	double xMax = 1000;
	double yMin = -1000;
	double yMax = 1000;
	double x = xMin;
	double y = yMin;
	glBegin(GL_QUADS);
	while(x < xMax){
		while(y < yMax){
			//glBegin(GL_QUADS);
				//fprintf(stderr,"starting x: %f, y: %f",x,y);
				glColor3f(0.0,0.0,0.0);
				glVertex3f(x,y,0);
				glVertex3f(x+10,y,0);
				glVertex3f(x+10,y+10,0);
				glVertex3f(x,y+10,0);

				y += 10;
				glColor3f(1.0,1.0,1.0);
				glVertex3f(x,y,0);
				glVertex3f(x+10,y,0);
				glVertex3f(x+10,y+10,0);
				glVertex3f(x,y+10,0);
			//glEnd();
			y -= 10;
			x += 10;
				glColor3f(1.0,1.0,1.0);
				glVertex3f(x,y,0);
				glVertex3f(x+10,y,0);
				glVertex3f(x+10,y+10,0);
				glVertex3f(x,y+10,0);

				y += 10;
				glColor3f(0,0,0);
				glVertex3f(x,y,0);
				glVertex3f(x+10,y,0);
				glVertex3f(x+10,y+10,0);
				glVertex3f(x,y+10,0);
			y += 10;
			x -= 10;
		}
		y = yMin;
		x += 20;
	}
	glEnd();
}


void Floor::move(){} //currently doesn't move
