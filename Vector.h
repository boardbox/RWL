#ifndef VECTOR_H
#define VECTOR_H

struct Vector{
	public:
	double x;
	double y;
	double z;

	Vector();
	Vector(double x, double y, double z);
	Vector(const Vector &v);

	void add(const Vector &v);
	void subtract(const Vector &v);
	double dot(const Vector &v);
	void cross(const Vector &v);
	void normalize();
	double length() const;
	bool operator==(const Vector& v) const;
	Vector& operator=(const Vector &rhs);
};

#endif
