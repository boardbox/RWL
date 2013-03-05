#ifndef AGENT_H
#define AGENT_H

#include "Object.h"
#include "Vector.h"

class Agent : public Object{
	const double bsize;

	public:
	Vector dest;
	void move();

	Agent();
	virtual void draw() const;
	virtual bool collide(const Vector&) const;
	virtual bool collide(const Object&) const;
};

#endif
