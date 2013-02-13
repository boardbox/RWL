#ifndef OBJECT_H
#define OBJECT_H

#include "Vector.h"

class Object{
	Object *prev;
	Object *next;

	Object(const Object&);
	Object& operator=(const Object&);
	
	protected:
	Object(const Vector& _loc);
	Object* getNext() const;
	Object* getPrev() const;
	void setNext(Object *t);
	void setPrev(Object *t);
	
	public:
	Vector loc;
	
	Object();
	virtual void move() = 0;
	virtual void draw() const;
	virtual ~Object();
};

#endif
