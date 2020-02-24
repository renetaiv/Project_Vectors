#include "VectorLengthException.h"

const char  * VectorLengthException::what() const throw () {
	return "ERROR! Vector length is zero!";
}
