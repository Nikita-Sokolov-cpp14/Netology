#include "cylinder.h"

Cylinder::Cylinder(int _x1, int _y1, double _R, double _H) :
	x1(_x1), y1(_y1), radius(_R), height(_H)
{
	calc_volume();
	calc_square();
}

void Cylinder::calc_square()
{
	square = M_PI * radius * radius + 2 * radius * height;
}

void Cylinder::calc_volume()
{
	volume = M_PI * radius * radius * height;
}