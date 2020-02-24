#include "Tetrahedron.h"
#include<iostream>
#include "EqualPointException.h"
#include<exception>

Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron(const Point & a, const Point & b, const Point & c, const Point & d)
{
	try {
		if (a == b) {
			std::cout << "First: " << a << " and " << "second point: " << b << std::endl;
			throw EqualPointException();
		}
		else if (a == c) {
			std::cout << "First: " << a << " and " << "third point: " << c << std::endl;
			throw EqualPointException();
		}
		else if (b == c) {
			std::cout << "Second: " << b << " and " << "third point: " << c << std::endl;
			throw EqualPointException();
		}
		else if (a == d) {
			std::cout << "First: " << a << " and " << "forth point: " << d << std::endl;
			throw EqualPointException();
		}
		else if (b == d) {
			std::cout << "Second: " << b << " and " << "forth point: " << d << std::endl;
			throw EqualPointException();
		}
		else if (c == d) {
			std::cout << "Third: " << c << " and " << "forth point: " << d << std::endl;
			throw EqualPointException();
		}
		else {
			this->A = a;
			this->B = b;
			this->C = c;
			this->D = d;
		}

	}
	catch (EqualPointException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Tetrahedron::Tetrahedron(const Tetrahedron & rhs)
{
	A = rhs.A;
	B = rhs.B;
	C = rhs.C;
	D = rhs.D;
}

Tetrahedron::~Tetrahedron()
{
}

bool Tetrahedron::pravilen() const
{
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);
	Vector v4(A, D);
	Vector v5(B, D);
	Vector v6(C, D);

	double a = v1.lengthOfVec();
	double b = v2.lengthOfVec();
	double c = v3.lengthOfVec();
	double d = v4.lengthOfVec();
	double e = v4.lengthOfVec();
	double f = v4.lengthOfVec();

	if (a == b == c == d == e == f) return true;
	return false;
}

bool Tetrahedron::ortogonalen()const {
	if (((this->A.x * C.x) + (this->A.y * C.y) + (this->A.z * C.z)) == 0) {   
		return true;
	}
	else if (((this->B.x * D.x) + (this->B.y * D.y) + (this->B.z * D.z)) == 0) { 
		return true;
	}
	else
		return false;
}

double Tetrahedron::surroundingArea() const
{
	//правилен тетраедър
	Vector v1(A, B);
	double a = v1.lengthOfVec();
	return sqrt(3 * (pow(a, 2)));;
}

double Tetrahedron::capacity()const {
	//правилен тетраедър
	Vector v1(A, B);
	double a = v1.lengthOfVec();
	double res = (1 / 12) * sqrt(2 * (a * a * a));
	return res;
}

std::ostream & operator<<(std::ostream & out, const Tetrahedron & rhs)
{
	return out << "Point A: " << rhs.A << "Point B: " << rhs.B << "Point C: " << rhs.C << "Point D: " << rhs.D;
}

std::istream & operator>>(std::istream & in, Tetrahedron & rhs)
{
	std::cout << "Please enter first point \n";
	in >> rhs.A;  
	std::cout << "Please enter second point \n";
	in >> rhs.B;
	std::cout << "Please enter third point \n";
	in >> rhs.C;
	std::cout << "Please enter forth point \n";
	in >> rhs.D;
	return in;
}