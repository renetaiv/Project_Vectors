#include "Vector.h"
#include <iostream>
#include<cmath>
#include<exception>
#include "VectorLengthException.h"

Vector::Vector():Point(){}

Vector::Vector(double x, double y, double z):Point(x,y,z) {
}

Vector::Vector(const Vector& obj) : Vector(obj) {}

Vector::Vector(const Point& a, const Point& b) {
	this->x = b.getX() - a.getX();
	this->y = b.getY() - a.getY();
	this->z = b.getZ() - a.getZ();
}

Vector::~Vector()
{
}

std::istream& operator>>(std::istream & in,
	Vector & rhs) {
	double x, y, z;
	std::cout << "Please enter x: ";
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

double Vector::lengthOfVec()const {
	// sqrt(x^2 + y^2 + z^2)
	double res = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return res;
}

Vector Vector::dirOfVec()const {
	try {
		if (lengthOfVec() == 0) {
			throw VectorLengthException();
		} //throws VectorLengthException if length is equal to zero
		else {
			return Vector(x / lengthOfVec(), y / lengthOfVec(), z / lengthOfVec());
		}
	}
	catch (VectorLengthException& e) {
		std::cout << e.what() << std::endl;
	}
}

Vector Vector::proj(const Vector& obj)const {
	//projv u = (u * v / |v|^2) * v

	double upSide = (this->x * obj.x) + (this->y * obj.y) + (this->z * obj.z);
	double downSide = pow(obj.lengthOfVec(), 2);
	double all = upSide / downSide;
	return Vector(all * obj.x, all * obj.y, all * obj.z);
}

bool Vector::checkIfNull()const {
	if (x == y == z == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector::checkifParallel(const Vector& v)const {

	try {
		if (lengthOfVec() == 0 || v.lengthOfVec() == 0) {
			throw VectorLengthException();
		} //throws VectorLengthException if length is equal to zero

	}
	catch (VectorLengthException& e) {
		std::cout << e.what() << std::endl;
	}

	if ((this->x / v.x) == (this->y / v.y) == (this->z / v.z)) {   // x:v1 = y:v2 = z:v3
		return true;
	}
	else
		return false;

}

bool Vector::checkIfPerpend(const Vector& obj)const {
	try {
		if (lengthOfVec() == 0 || obj.lengthOfVec() == 0) {
			throw VectorLengthException();
		} 
		if (((this->x * obj.x) + (this->y * obj.y) + (this->z * obj.z)) == 0) {   // x.v1 + y.v2 + z.v3 = 0
			return true;
		}
		else
			return false;

	}
	catch (VectorLengthException& e) {
		std::cout << e.what() << std::endl;
	}
}

Vector Vector::operator+(const Vector&obj)const {
	return Vector(this->x + obj.x, this->y + obj.y, this->z + obj.z);
}

Vector Vector::operator-(const Vector& obj)const {
	return Vector(this->x - obj.x, this->y - obj.y, this->z - obj.z);
}

Vector Vector::operator*(double num)const {
	return Vector(this->x * num, this->y * num, this->z * num);
}

double Vector::operator*(const Vector& obj)const {
	//skalarno proizvedenie
	return((this->x*obj.x) + (this->y*obj.y) + (this->z*obj.z));
}

Vector Vector::operator^(const Vector& obj)const {
	//a ^ v = (y.v3 − z.v2, −x.v3 + z.v1, x.v2 − y.v1)
	double x = (this->y * obj.z) - (this->z * obj.y);
	double y = (-this->x * obj.z) + (this->z * obj.x);
	double z = (this->x * obj.y) - (this->y * obj.x);
	return Vector(x, y, z); 
}

double Vector::operator()(const Vector& v1, const Vector& v2) {
	double res = (this->x + v1.x + v2.x) + (this->y + v1.y + v2.y) + (this->z + v1.z + v2.z);
	return res;
}

std::ostream& operator<<(std::ostream & out,
	const Vector & rhs) {
	out << rhs.x << ", " << rhs.y << ", " << rhs.z;
	return out;
}