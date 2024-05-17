#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cmath>


class Shape
{
public:
	double volume = 0;
	double square = 0;	

	virtual void calc_square() = 0;
	virtual void calc_volume() = 0;
	virtual void shift(int m, int n, int k);
	virtual void scaleX(int scale);
	virtual void scaleY(int scale);
	virtual void scaleZ(int scale);
	virtual void scale(int scale);

	virtual ~Shape();
};
