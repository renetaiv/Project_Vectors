#include "Line.h"
#include<iostream>
#include<cmath>

Line::Line():startPoint(0,0,0) , direction(0,0,0), p1(0,0,0), p2(0,0,0)
{}

Line::Line(const Point& pt, const Vector& v) {
	this->startPoint.x = pt.x + v.x;
	this->startPoint.y = pt.y + v.y;
	this->startPoint.z = pt.z + v.z;
	//std::cout << startPoint << std::endl;
	this->direction = v;
	//std::cout << direction << std::endl;
}

Line::Line(const Point& point1, const Point& point2)
{
	Vector v(point1, point2);
	Line(point1, v);
}

Vector Line::getDirection()const {
	//v(x,y,z)		
	//std::cout << direction << std::endl;
	return this->direction;
}

Vector Line::normalVector()const {

	Vector newV(this->startPoint.x, this->startPoint.y, this->startPoint.z);
	return Vector(this->direction ^ newV);
	 
}

double Line::getAngle(Line & newL)const{
	//(x1x2 + y1y2 + z1z2) / V(x1^2 + y1^2 + z1^2) * V(x2^2 + y2^2 + z2^2)
	double angle = (this->direction.x*newL.direction.x + this->direction.y*newL.direction.y + this->direction.z*newL.direction.z)
		/ (this->direction.lengthOfVec() * newL.direction.lengthOfVec());
	return acos(angle);
}

Line::~Line()
{
}

bool Line::operator+(const Point& p)const {
	//(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1) = (z - z1) / (z2 - z1)
	return (((p.x - p1.x) / (p2.x - p1.x)) == ((p.y - p1.y) / (p2.y - p1.y)) == ((p.z - p1.z) / (p2.z - p1.z)));	
}

bool Line::operator|(const Line& line)const {
	return (((this->direction.x * line.direction.x) + (this->direction.y * line.direction.y) + (this->direction.z * line.direction.z)) == 0);
}

/*
bool Line::operator!=(const Line& line)const
{
	// if 2 lines are same direction, the magnitude of cross product is 0
	Vector v = this->direction.cross(line.direction);
	if (v.x == 0 && v.y == 0 && v.z == 0)
		return false;
	else
		return true;
} */

bool Line::operator||(const Line& line)const {
	if ((this->direction.x * line.direction.x) == (this->direction.y * line.direction.y) == (this->direction.z * line.direction.z)) {
		return true;
	}
	else
		return false;
}
