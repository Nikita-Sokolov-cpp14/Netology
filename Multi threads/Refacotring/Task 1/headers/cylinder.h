#pragma once
#include "shape.h"

class Cylinder : public Shape {
public:
	double height = 0;
	double radius = 0;
	int x1 = 0, y1 = 0;

	Cylinder() = default;
	Cylinder(int _x1, int _y1, double _R, double _H);
	void calc_square() override;
	void calc_volume() override;
};
