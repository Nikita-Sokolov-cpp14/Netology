#pragma once
#include <iostream>
class Calculator {
private:
	int x, y;
public:
	Calculator(int x, int y);
	int sum();
	int diff();
	int mult();
	double div();
	double pow();
	void print_sum();
	void print_diff();
	void print_mult();
	void print_div();
	void print_pow();
};