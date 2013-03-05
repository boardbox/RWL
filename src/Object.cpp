#include <GL/glfw.h>
#include "Object.h"

Object::Object():prev(NULL),next(NULL){};

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

Object::~Object(){}
