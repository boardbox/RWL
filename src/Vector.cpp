#include <cmath>
#include "Vector.h"

Vector::Vector():x(0),y(0),z(0){}

Vector::Vector(double i,double j,double k):x(i),y(j),z(k){}

Vector::Vector(const Vector &v):x(v.x),y(v.y),z(v.z){}

void Vector::add(const Vector &v){
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector::subtract(const Vector &v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector::sMult(double s){
	x = x*s;
	y = y*s;
	z = z*s;
}

void Vector::sMult(int s){
	sMult((double) s);
}

void Vector::sMult(float s){
	sMult((double) s);
}

double Vector::dot(const Vector &v){
	return (x*v.x + y*v.y + z*v.z);
}

void Vector::cross(const Vector &v){
	double i = (y*v.z - z*v.y);
	double j = -(x*v.z - z*v.x);
	double k = (x*v.y - y*v.x);
	x = i;
	y = j;
	z = k;
}

double Vector::length() const{
	return sqrt(x*x + y*y + z*z);
}

void Vector::normalize(){
	double l = length();
	x = x / l;
	y = y / l;
	z = z / l;
}

bool Vector::operator==(const Vector& v) const{
	if(x == v.x && y == v.y && z == v.z) return true;
	return false;
}

Vector& Vector::operator=(const Vector &rhs){
	if(this == &rhs) return *this;

	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

Vector& Vector::operator+=(const Vector &rhs){
	if(this == &rhs){
		sMult(2.0);
		return *this;
	}
	else{
		add(rhs);
		return *this;
	}
}

Vector& Vector::operator-=(const Vector &rhs){
	if(this == &rhs){
		x = 0;
		y = 0;
		z = 0;
		return *this;
	}
	else{
		subtract(rhs);
		return *this;
	}
}

Vector& Vector::operator*=(double anum){
		sMult(anum);
		return *this;
}

Vector& Vector::operator*=(int anum){
	sMult(anum);
	return *this;
}
	
Vector& Vector::operator*=(float anum){
	sMult(anum);
	return *this;
}

const Vector Vector::operator+(const Vector& other){
	Vector res(*this);
	res += other;
	return res;
}

const Vector Vector::operator-(const Vector& other){
	Vector res(*this);
	res -= other;
	return res;
}

const Vector Vector::operator*(int anum){
	Vector res(*this);
	res *= anum;
	return res;
}

const Vector Vector::operator*(double anum){
	Vector res(*this);
	res *= anum;
	return res;
}

const Vector Vector::operator*(float anum){
	Vector res(*this);
	res *= anum;
	return res;
}
