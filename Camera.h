#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include "Object.h"

class Camera : public Object{
	Vector tar;
	const Vector up;

	public:
	Camera();
	Camera(const Vector& loc,const Vector& tar, const Vector& up);
	void mvTar();
	virtual void move();
};

#endif
