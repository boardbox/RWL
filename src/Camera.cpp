#include <cmath>
#include <GL/glfw.h>
#include "Vector.h"
#include "Object.h"
#include "Camera.h"

const double PI = 4.0*atan(1.0);
const double fovy = 45.0;

Camera::Camera():Object(),tar(Vector(0,0,0)),up(Vector(0,0,1)){}

Camera::Camera(const Vector& _loc, const Vector& _tar, const Vector& _up)
:Object(_loc),
xWinSize(640),
yWinSize(480),
nclip(5),
fclip(500),
tar(Vector(_tar)),
up(Vector(_up))
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(fovy,xWinSize/yWinSize,nclip,fclip);
	glMatrixMode(GL_MODELVIEW);
	
	gluLookAt(loc.x,loc.y,loc.z,tar.x,tar.y,tar.z,up.x,up.y,up.z);
}

void Camera::reLook(){
	glLoadIdentity();
	gluLookAt(loc.x,loc.y,loc.z,tar.x,tar.y,tar.z,up.x,up.y,up.z);
}

void Camera::set(const Vector& l,const Vector& t, const Vector& u){
	loc = t;
	tar = t;
	up = u;
	reLook();
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

	Vector v(view);
	v.cross(h);
	v.normalize();

	double rad = fovy * PI / 180.0;
	double vLength = tan(rad / 2.0) * nclip;
	double hLength = vLength * (xWinSize/yWinSize);
	h.sMult(hLength);
	v.sMult(vLength);

	x -= xWinSize/2;
	y -= yWinSize/2;
	x /= xWinSize/2;
	y /= yWinSize/2;

	Vector pos(loc);
	view.sMult(nclip);
	h.sMult(x);
	v.sMult(y);
	pos.add(view);
	pos.add(h);
	pos.add(v);
	pos.subtract(loc);
	vr = pos;
}

void Camera::updateTar(double x, double y){
	tar.x = x;
	tar.y = y;
}

void Camera::move(double fb, double ss,double ud){
	Vector f(tar);
	f.subtract(loc);
	f.z = 0;
	if(fb != 0){
		f.normalize();
		f.sMult(fb);
		loc.add(f);
		tar.add(f);
	}
	if(ss != 0 ){
		f.cross(up);
		f.normalize();
		f.sMult(ss);
		loc.add(f);
		tar.add(f);
	}
	if(ud != 0){
		loc.z += ud;
	}
}

void Camera::rotate(double lr){
	Vector d(tar);
	d.subtract(loc);
	d.z = 0;
	d.cross(up);
	d.normalize();
	d.sMult(lr);
	loc.add(d);
}

void Camera::zoom(double zoom){
	loc.subtract(tar);
	double mag = loc.length();
	mag += zoom;
	loc.normalize();
	loc.sMult(mag);
	loc.add(tar);
}

void Camera::draw() const{}
