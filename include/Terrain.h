#ifndef TERRAIN_H
#define TERRAIN_H

#include "ILinkedList.h"

class Terrain : public ILinkedList{
	bool collides;
	double rad;
	int type;

	Terrain& operator=(const Terrain&);
	Terrain(const Terrain&);
	Terrain();
	virtual void move();

	public:
	bool walkable;
	
	Terrain(double xMax,double yMax);
	void draw() const;
	bool collide(const Vector&) const;
	bool collide(const Object&) const;
};

#endif
