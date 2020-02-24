#pragma once
#include "Segment.h"
#include "EqualPointException.h"

class Tetrahedron :
	public Segment
{
public:
	Tetrahedron();
	Tetrahedron(const Point&, const Point&, const Point&, const Point&);
	Tetrahedron(const Tetrahedron&);
	~Tetrahedron();

	bool pravilen()const;
	bool ortogonalen()const;
	double surroundingArea()const;
	double capacity()const;
public:
	Point A;
	Point B;
	Point C;
	Point D;

};
std::ostream& operator<<(std::ostream &, const Tetrahedron&);
std::istream& operator>>(std::istream &, Tetrahedron&);