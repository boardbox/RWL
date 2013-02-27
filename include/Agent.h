#ifndef AGENT_H
#define AGENT_H

#include "Object.h"
#include "Vector.h"

class Agent : public Object{
	double bsize;

	public:
	Vector dest;
	void move();
	void draw() const;
};

#endif
