#ifndef VECTOR_H
#define VECTOR_H

class Vector{
	public:
	double x;
	double y;
	double z;

	Vector();
	Vector(double x, double y, double z);
	Vector(const Vector &v);

	void add(const Vector &v);
	void subtract(const Vector &v);
	void sMult(double s);
	void sMult(int s);
	void sMult(float s);
	double dot(const Vector &v);
	void cross(const Vector &v);
	void normalize();
	double length() const;
	bool operator==(const Vector& v) const;
	Vector& operator=(const Vector &rhs);
	//replicate behavior of add,subtract,sMult
	Vector& operator+=(const Vector &rhs);
	Vector& operator-=(const Vector &rhs);
	Vector& operator*=(double anum);
	Vector& operator*=(int anum);
	Vector& operator*=(float anum);
	const Vector operator+(const Vector& other);
	const Vector operator-(const Vector& other);
	const Vector operator*(int anum);
	const Vector operator*(double anum);
	const Vector operator*(float anum);
};

#endif
