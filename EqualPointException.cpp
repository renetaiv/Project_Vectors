#include "EqualPointException.h"

const char  * EqualPointException::what() const throw () {
	return "Equal points were found";
}
