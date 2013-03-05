#include <cmath>
#include <cstdio>
#include <GL/glfw.h>
#include "Object.h"
#include "Floor.h"

Floor::Floor(){}

Floor::Floor(double x,double y):xMax(x),yMax(y){}

void Floor::draw() const{
	double xMin = 0;
	double yMin = 0;
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

bool Floor::collide(const Vector& pos) const{
	double xMin,yMin;
	xMin = yMin = 0;
	if(pos.x >= xMin && pos.x <= xMax){
		if(pos.y >= yMin && pos.y <= yMax){
			return true;
		}
	}
	return false;
}

bool Floor::collide(const Object& pos) const{
	double xMin,yMin;
	xMin = yMin = 0;
	if(pos.loc.x >= xMin && pos.loc.x <= xMax){
		if(pos.loc.y >= yMin && pos.loc.y <= yMax){
			return true;
		}
	}
	return false;
}
