#include <GL/glfw.h>
#include "Object.h"

Object::Object(){};

Object::Object(const Vector& _loc):loc(Vector(_loc)){}

Object* Object::getNext() const{
	return next;
}

Object* Object::getPrev() const{
	return prev;
}

void Object::setNext(Object *t){
	next = t;
}

void Object::setPrev(Object *t){
	prev = t;
}

//draw 5x5x5 cube with back corner on loc
void Object::draw() const{
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
Object::~Object(){}
