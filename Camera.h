#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include "Object.h"

class Camera : public Object{
	Vector tar;
	Vector up;

	public:
	Camera();
	Camera(const Vector& loc,const Vector& tar, const Vector& up);
	void mvTar();
	void getViewRay(Vector& vr,int x, int y) const;
	virtual void move();
};

#endif
