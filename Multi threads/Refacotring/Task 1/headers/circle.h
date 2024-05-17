#pragma once
#include "shape.h"

class Circle : public Shape {
public:
	double radius = 0;
	int x1 = 0, y1 = 0;

	Circle() = default;
	Circle(int _x1, int _y1, double _R);
	void calc_square() override;
	void calc_volume() override;
};