#pragma once
#include"shape.h"
class Transform
{
public:
	Transform(const Angular& _angular);

	Angular shift(int m, int n, int k);
	Angular scaleX(int scale);
	Angular scaleY(int scale);
	Angular scaleZ(int scale);
	Angular scale(int scale);

private:
	int number_of_vertex = 0;
	Angular angular;

	void scale_line(int scale);
	void scale_sqr(int scale);
	void scale_cube(int scale);

	void shift_line(int m, int n);
	void shift_sqr(int m, int n);
	void shift_cube(int m, int n, int k);
};

