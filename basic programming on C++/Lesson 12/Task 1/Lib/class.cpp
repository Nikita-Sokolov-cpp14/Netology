#include "class.h"
#include <string>

std::string Greeter::greet(std::string Name) {
	setlocale(LC_ALL, "Russian");
	return "Здравствуйте, " + Name + "!";
}