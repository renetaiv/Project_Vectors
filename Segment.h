#pragma once
#include "Line.h"
class Segment :
	public Line
{
public:
	Segment();
	Segment(const Point&, const Vector&, const Point&, const Point&);
	double getLengthOfSegm()const;
	Point getMiddleOfSegm()const;
	~Segment();
private:
	Point startP;
	Point endP;
};

