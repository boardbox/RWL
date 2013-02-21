#include <cmath>
#include <GL/glfw.h>
#include "Vector.h"
#include "Object.h"
#include "Camera.h"

const double PI = 4.0*atan(1.0);

Camera::Camera():Object(),tar(Vector(0,0,0)),up(Vector(0,0,1)){}

Camera::Camera(const Vector& _loc, const Vector& _tar, const Vector& _up)
:Object(_loc),
tar(Vector(_tar)),
up(Vector(_up))
{
	up.cross(loc);
	up.cross(loc);
	up.normalize();
	up.sMult(-1);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0,640.0/480.0,5,500);
	glMatrixMode(GL_MODELVIEW);
	
	gluLookAt(loc.x,loc.y,loc.z,tar.x,tar.y,tar.z,up.x,up.y,up.z);
}

void Camera::getViewRay(Vector& vr,int _x, int _y) const{
	double x = _x;
	double y = _y;
	Vector view(tar); //copy
	view.subtract(loc);
	view.normalize();

	Vector h(view);
	h.cross(up);
	h.normalize();

	Vector v(up);

	double rad = 45.0 * PI / 180.0;
	double vLength = tan(rad / 2.0) * 5.0;
	double hLength = vLength * (640.0/480.0);
	h.sMult(hLength);
	v.sMult(vLength);

	x -= 640/2;
	y -= 480/2;
	x /= 640/2;
	y /= 480/2;

	Vector pos(loc);
	view.sMult(5);
	h.sMult(x);
	v.sMult(y);
	pos.add(view);
	pos.add(h);
	pos.add(v);
	pos.subtract(loc);
	vr = pos;
}

void Camera::mvTar(){}

void Camera::move(){};
