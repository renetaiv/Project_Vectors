#pragma once
#include "Element.h"
#include<iostream>
class Point :
	public Element
{
public:
	Point();
	Point(double, double, double);
	Point(const Point&);
	virtual ~Point();

	virtual void setX(double);
	virtual void setY(double);
	virtual void setZ(double);

	virtual double getX()const;
	virtual double getY()const;
	virtual double getZ()const;
	bool operator==(const Point&)const;
	void print()const;


	double x;
	double y;
	double z;
};

std::ostream& operator<<(std::ostream &, const Point &);
std::istream& operator>>(std::istream &, Point &);
