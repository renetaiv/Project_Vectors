#pragma once
#include<exception>
class VectorLengthException : public std::exception
{
public:
	const char * what() const throw ();
};

