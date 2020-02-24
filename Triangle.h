#pragma once
#include "Point.h"
#include<iostream>
#include "Vector.h"

class Triangle :
	public Point
{
public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);	
	~Triangle();
	
	void kindOfTriangle()const;
	double area()const;
	double perimeter()const;
	Point medicenter()const;

public:
	Point A;
	Point B;
	Point C;
	Vector v1;
	Vector v2;
	Vector v3;
};

std::istream& operator>>(std::istream &, Triangle&);







