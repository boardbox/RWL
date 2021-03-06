#include <cmath>
#include <cstdlib>
#include <GL/glfw.h>
#include "Vector.h"
#include "ILinkedList.h"
#include "Terrain.h"

const int mountain = 1;
const int swamp 	 = 2;
const int ground	 = 3;
const double PI = 4.0*atan(1.0);

Terrain::Terrain(double xMax,double yMax):
ILinkedList(),rad(0),type(-1),walkable(false){
	if(rand()%10 > 4) type = mountain;
	else type = swamp;
	Vector place(rand()%(int)xMax,rand()%(int)yMax,0);
	loc = place;
	rad = rand() % 20 + 1;
	if(type == swamp) walkable = true;
}

Terrain::Terrain(int t):ILinkedList(),type(t){}

void Terrain::draw() const{
	if(type == mountain){
		double h = rad*tan(60.0 * PI/180.0);
		for(int i=0;i<361;i++){
			double x1 = loc.x + rad*(cos(i*PI/180.0));
			double x2 = loc.x + rad*(cos((i+1) * PI/180.0));
			double y1 = loc.y + rad*(sin(i*PI/180.0));
			double y2 = loc.y + rad*(sin((i+1) * PI/180.0));
			glBegin(GL_TRIANGLES);
				glColor3f(192.0/255.0,192.0/255.0,192.0/255.0);
				glVertex3f(x1,y1,0);
				glVertex3f(x2,y2,0);
				glVertex3f(loc.x,loc.y,h);
			glEnd();
		}
	}	
	else if(type == swamp){
		for(int i=0;i<361;i++){
			double x1 = loc.x + rad*(cos(i*PI/180.0));
			double x2 = loc.x + rad*(cos((i+1) * PI/180.0));
			double y1 = loc.y + rad*(sin(i*PI/180.0));
			double y2 = loc.y + rad*(sin((i+1) * PI/180.0));
			glBegin(GL_TRIANGLES);
				glColor3f(139.0/255.0,35.0/255.0,35.0/255.0);
				glVertex3f(x1,y1,0);
				glVertex3f(x2,y2,0);
				glVertex3f(loc.x,loc.y,0);
			glEnd();
		}
	}
	else if(type == ground){
		double xMin = 0;
		double yMin = 0;
		double xMax = 200;
		double yMax = 100;
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
}

void Terrain::move(){} 

bool Terrain::collide(const Vector& pos) const{
	Vector ruler(loc);
	ruler.subtract(pos);
	if(ruler.length() < rad) return true;
	return false;
}

bool Terrain::collide(const ILinkedList& thing) const{
	/*Vector ruler(loc);
	ruler.subtract(thing.loc);
	if(ruler.length() < rad) return true;
	return false;*/
	return false;
}
