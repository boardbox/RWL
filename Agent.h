#ifndef AGENT_H
#define AGENT_H

#include "Object.h"
#include "Vector.h"

class Agent : public Object{
	//double speed;

	public:
	Vector dest;
	virtual void move();
	//virtual void draw() const;
};

#endif
