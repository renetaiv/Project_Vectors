#pragma once
#include "Vector.h"
#include "Point.h"
class Line :
	public Vector
{
public:
	Line();
	Line(const Point&, const Vector&);
	Line(const Point&, const Point &);

	Vector getDirection()const;
	Vector normalVector()const;
	double getAngle(Line&)const;
	bool operator+(const Point&)const;
	bool operator!=(const Line& line)const;
	bool operator|(const Line&)const;
	bool operator||(const Line&)const;
	~Line();

protected:
	Point startPoint;
	Vector direction;
	Point p1;
	Point p2;
};

