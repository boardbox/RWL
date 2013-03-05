#ifndef FLOOR_H
#define FLOOR_H

#include "Object.h"

class Floor : public Object{
	double xMax;
	double yMax;

	virtual bool collide(const Vector&) const;
	virtual bool collide(const Object&) const;

	public:
	Floor();
	Floor(double x,double y);
	virtual void draw() const;
};

#endif
