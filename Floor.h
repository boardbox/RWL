#ifndef FLOOR_H
#define FLOOR_H

#include "Object.h"

class Floor : public Object{
	public:
	Floor();
	virtual void draw() const;
	virtual void move();
};

#endif
