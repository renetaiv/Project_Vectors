#include "Triangle.h"
#include<iostream>
#include "EqualPointException.h"


Triangle::Triangle() : A(0,0,0), B(0,0,0), C(0,0,0), v1(0, 0, 0), v2(0, 0, 0), v3(0, 0, 0)
{
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) {
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
		else {
			this->A = a;
			this->B = b;
			this->C = c;
		}

	}
	catch (EqualPointException& e) {
		std::cout << e.what() << std::endl;
	}
}

Triangle::Triangle(const Triangle& obj): Triangle(obj){
	A = obj.A;
	B = obj.B;
	C = obj.C;
}

Triangle::~Triangle()
{
}

void Triangle::kindOfTriangle()const {
	setlocale(LC_ALL, "Bulgarian");

	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);

	double A = v1.lengthOfVec();
	double B = v2.lengthOfVec();
	double C = v3.lengthOfVec();

	std::cout << "Kind of triangle is -> ";
	if (A == B == C)
	{
		std::cout << "equilateral\n";
	}
	if ((A == B && A != C && B != C) || (A == C && A != B && B != C) || (B == C && A != B && A != C))
	{
		std::cout << "isosceles\n";
	}

	double cosA, cosB, cosC;

	cosA = (pow(B, 2) + pow(C, 2) - pow(A, 2)) / 2 * B * C;
	cosB = (pow(A, 2) + pow(C, 2) - pow(B, 2)) / 2 * A * C;
	cosC = (pow(A, 2) + pow(B, 2) - pow(C, 2)) / 2 * A * B;

	if (A>B && A>C){
		if(cosA > 0) std::cout << "acute-angled\n";
		if(cosA == 0) std::cout << "right-angled\n";
		if(cosA <  0) std::cout << "obtuse\n";
	} 
	if (B>A && B>C){
		if(cosB > 0) std::cout << "acute-angled\n";
		if(cosB == 0) std::cout << "right-angled\n";
		if(cosB <  0) std::cout << "obtuse\n";
	} 
	if (C>A && C>B) {
		if (cosC > 0) std::cout << "acute-angled\n";
		if (cosC == 0) std::cout << "right-angled\n";
		if (cosC <  0) std::cout << "obtuse\n";
	}
} 

double Triangle::area()const {
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);

	double A = v1.lengthOfVec();
	double B = v2.lengthOfVec();
	double C = v3.lengthOfVec();
	double p1 = perimeter() / 2;
	double res = sqrt(p1*(p1 - A)*(p1 - B)*(p1 - C)); //Хероновата теорема
	return res;
} 

double Triangle::perimeter()const {
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);
	double A = v1.lengthOfVec();
	double B = v2.lengthOfVec();
	double C = v3.lengthOfVec();
	return (A + B + C);
}

Point Triangle::medicenter()const {
	return Point((this->A.getX() + B.getX() + C.getX()) / 3, 
		(this->A.getY() + B.getY() + C.getY()) / 3,
		(this->A.getZ() + B.getZ() + C.getZ()) / 3);
}

std::istream & operator>>(std::istream & in, Triangle & rhs)
{
	std::cout << "Please enter first point \n";
	in >> rhs.A;
	std::cout << "Please enter second point \n";
	in >> rhs.B;
	std::cout << "Please enter third point \n";
	in >> rhs.C;
	return in;
}