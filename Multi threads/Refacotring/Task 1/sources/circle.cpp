#include "circle.h"

Circle::Circle(int _x1, int _y1, double _R) :
	x1(_x1), y1(_y1), radius(_R)
{
	calc_square();
	calc_volume();
}

void Circle::calc_volume() { volume = 0; }

void Circle::calc_square()
{
	square = M_PI * radius * radius;
}