
#include "Segment.h"
#include<ctime>
#include<cmath>

Segment::Segment()
{
}

Segment::Segment(const Point& point, const Vector& v, const Point& s, const Point& end): Line(point, v), startP(s), endP(end) {
	srand(time(NULL));
	double res = rand() % 2 ;
	x = point.x + v.x*res;
	y = point.y + v.y*res;
	z = point.z + v.z*res;
}


Segment::~Segment()
{
}

double Segment::getLengthOfSegm()const {
	double res = sqrt(pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2));
	return res;
}

Point Segment::getMiddleOfSegm()const {
	return Point((startP.x + endP.x) / 2, (startP.y + endP.y) / 2, (startP.z + endP.z) / 2);
}

