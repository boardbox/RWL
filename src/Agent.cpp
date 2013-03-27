#include <cmath>
#include <GL/glfw.h>
#include "Vector.h"
#include "ILinkedList.h"
#include "Agent.h"

const double speed = 1;
const double ftime = 0.01666667;

Agent::Agent():ILinkedList(),bsize(5){}
	
void Agent::move(){
	if(dest == loc) return; //nothing to do

	Vector dir(dest); //copy because subtract acts on callee
	dir.subtract(loc);

	double maxd = speed * ftime;
	if(dir.length() <= maxd){ //can move past target
		loc = dest;
		return;
	}

	dir.normalize();
	dir.x = dir.x * maxd;
	dir.y = dir.y * maxd;
	dir.z = dir.z * maxd;
	loc.add(dir);
	return;
}

//draw 5x5x5 cube with back corner on loc
void Agent::draw() const{
	double l = 5;
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		//bottom
		glVertex3f(loc.x,loc.y,loc.z);
		glVertex3f(loc.x+l,loc.y,loc.z);
		glVertex3f(loc.x+l,loc.y+l,loc.z);
		glVertex3f(loc.x,loc.y+l,loc.z);

		//top
		glVertex3f(loc.x,loc.y,loc.z+l);
		glVertex3f(loc.x+l,loc.y,loc.z+l);
		glVertex3f(loc.x+l,loc.y+l,loc.z+l);
		glVertex3f(loc.x,loc.y+l,loc.z+l);

		//front
		glVertex3f(loc.x,loc.y+l,loc.z);
		glVertex3f(loc.x,loc.y+l,loc.z+l);
		glVertex3f(loc.x+l,loc.y+l,loc.z+l);
		glVertex3f(loc.x+l,loc.y+l,loc.z);
		
		//back
		glVertex3f(loc.x,loc.y,loc.z);
		glVertex3f(loc.x,loc.y,loc.z+l);
		glVertex3f(loc.x+l,loc.y,loc.z+l);
		glVertex3f(loc.x+l,loc.y,loc.z);
		
		//left
		glVertex3f(loc.x,loc.y,loc.z);
		glVertex3f(loc.x,loc.y+l,loc.z);
		glVertex3f(loc.x,loc.y+l,loc.z+l);
		glVertex3f(loc.x,loc.y,loc.z+l);

		//right
		glVertex3f(loc.x+l,loc.y,loc.z);
		glVertex3f(loc.x+l,loc.y,loc.z+l);
		glVertex3f(loc.x+l,loc.y+l,loc.z+l);
		glVertex3f(loc.x+l,loc.y+l,loc.z);
	glEnd();
}

bool Agent::collide(const Vector& vec) const{
	Vector ruler(loc);
	ruler.subtract(vec);
	if(ruler.length() < bsize) return true;
	else return false;
}

bool Agent::collide(const ILinkedList& thing) const{
	Vector ruler(thing.loc);
	ruler.subtract(loc);
	if(ruler.length() < bsize) return true;
	else return false;
}
