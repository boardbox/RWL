#ifndef TERRAIN_H
#define TERRAIN_H

#include "Object.h"

class Terrain : public Object{
	double rad;
	int type;

	Terrain& operator=(const Terrain&);
	Terrain(const Terrain&);
	Terrain();
	virtual void move();

	public:
	bool walkable;
	
	Terrain(double xMax,double yMax);
	virtual void draw() const;
};

#endif
