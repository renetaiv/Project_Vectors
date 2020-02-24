#include "Point.h"
#include <iostream>

Point::Point():x(0.), y(0.), z(0.){}

Point::Point(double x = 0., double y = 0., double z = 0.):x(x), y(y), z(z){}

Point::Point(const Point& obj) : Point(obj) {}

Point::~Point() {}

void Point::setX(double x) {
	this->x = x;
}
void Point::setY(double y){
	this->y = y;
}
void Point::setZ(double z) {
	this->z = z;
}

double Point::getX()const {
	return x;
}
double Point::getY()const {
	return y;
}
double Point::getZ()const {
	return z;
}

bool Point::operator==(const Point&b)const {
	bool equal = (this->x == b.getX() && this->y == b.getY() && this->z == b.getZ());
	return equal;
}

void Point::print()const {
	std::cout << "The point is (" << x << "," << y << "," << z << ").\n";
}

std::ostream& operator<<(std::ostream & out,
	const Point & rhs) {
	out << rhs.getX() << ", " << rhs.getY() << ", " << rhs.getZ();
	return out;
}

std::istream& operator>>(std::istream & in,
	Point & rhs) {
	setlocale(LC_ALL, "Bulgarian");
	double x, y, z;
	std::cout << "Please enter õ: ";
	in >> x;
	std::cout << "Please enter y: ";
	in >> y;
	std::cout << "Please enter z: ";
	in >> z;

	rhs.setX(x);
	rhs.setY(y);
	rhs.setZ(z);
	
	return in;
}
