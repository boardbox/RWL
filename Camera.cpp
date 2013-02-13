#include <GL/glfw.h>
#include "Vector.h"
#include "Object.h"
#include "Camera.h"

Camera::Camera():Object(),tar(Vector(0,0,0)),up(Vector(0,0,1)){}

Camera::Camera(const Vector& _loc, const Vector& _tar, const Vector& _up)
:Object(_loc),
tar(Vector(_tar)),
up(Vector(_up))
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0,1.0,0.1,500);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(loc.x,loc.y,loc.z,tar.x,tar.y,tar.z,up.x,up.y,up.z);
}

void Camera::mvTar(){}

void Camera::move(){};
