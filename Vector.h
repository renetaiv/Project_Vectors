#pragma once
#include "Point.h"
#include <iostream>

class Vector :
	public Point
{
	
public:
	Vector();
	Vector(double, double, double);
	Vector(const Point&, const Point&);
	Vector(const Vector&);
	virtual ~Vector();

	double lengthOfVec()const;
	Vector dirOfVec()const;
	Vector proj(const Vector&)const;
	bool checkIfNull()const;
	bool checkifParallel(const Vector&)const;
	bool checkIfPerpend(const Vector&)const;
	Vector operator+(const Vector&)const;
	Vector operator-(const Vector&)const;
	Vector operator*(double)const;
	double operator*(const Vector&)const;
	Vector operator^(const Vector&)const;
	double operator()(const Vector&, const Vector&);
	
};

std::istream& operator>>(std::istream &, Vector&);
std::ostream& operator<<(std::ostream &, const Vector &);

