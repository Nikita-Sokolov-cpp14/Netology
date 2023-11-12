#include "calc.h"

Calculator::Calculator(int x, int y) {
	this->x = x;
	this->y = y;
}
int Calculator::sum() { return x + y; }
int Calculator::diff() { return x - y; }
int Calculator::mult() { return x * y; }
double Calculator::div() { return static_cast<double>(x) / y; }
double Calculator::pow() {
	if (y == 0) {
		return 1;
	}
	if (y > 0) {
		if (y == 1) {
			return x;
		}
		else { y--; }
		return x * pow();
	}
	else {
		if (y == -1) {
			return 1.0 / x;
		}
		else { y++; }
		return pow() / x;
	}
}
void Calculator::print_sum() {
	std::cout << x << " + " << y << " = " << sum() << std::endl;
}
void Calculator::print_diff() {
	std::cout << x << " - " << y << " = " << diff() << std::endl;
}
void Calculator::print_mult() {
	std::cout << x << " * " << y << " = " << mult() << std::endl;
}
void Calculator::print_div() {
	std::cout << x << " / " << y << " = " << div() << std::endl;
}
void Calculator::print_pow() {
	std::cout << x << " в степени " << y << " = ";
	std::cout << pow() << std::endl;
}
