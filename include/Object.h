#ifndef OBJECT_H
#define OBJECT_H

#include "Vector.h"

class Object{
	Object *prev;
	Object *next;

	Object(const Object&);
	Object& operator=(const Object&);
	
	public:
	Object(const Vector& _loc);
	Object* getNext() const;
	Object* getPrev() const;
	void setNext(Object *t);
	void setPrev(Object *t);
	
	Vector loc;
	
	Object();
	virtual void draw() const=0;
	virtual ~Object();
};

#endif
