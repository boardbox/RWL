#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include "Object.h"

class Camera : public Object{
	double xWinSize;
	double yWinSize;
	double nclip;
	double fclip;
	Vector tar;
	Vector up;

	public:
	Camera();
	Camera(const Vector& loc,const Vector& tar, const Vector& up);
	void move(double x, double y,double z);
	void rotate(double lr);
	void zoom(double zoom);
	void updateTar(double x, double y);
	void getViewRay(Vector& vr,int x, int y) const;
	void reLook();
	void set(const Vector& l,const Vector& t,const Vector& u);
	virtual void draw() const;
};

#endif
