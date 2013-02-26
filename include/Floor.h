#ifndef FLOOR_H
#define FLOOR_H

#include "Object.h"

class Floor : public Object{
	double xMax;
	double yMax;

	public:
	Floor();
	Floor(double x,double y);
	virtual void draw() const;
	virtual void move();
};

#endif
