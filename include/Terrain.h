#ifndef TERRAIN_H
#define TERRAIN_H

#include "ILinkedList.h"

class Vector;

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
	Vector loc;

	Terrain(double xMax,double yMax);
	Terrain(int type);
	void draw() const;
	bool collide(const Vector&) const;
	bool collide(const ILinkedList&) const;
};

#endif
