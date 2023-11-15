#include "../headers/Errors.h"

const char* creation_error::what() const {
	return why; 
}
creation_error::creation_error(const char* why) : std::domain_error(why) {
	this->why = why;
}