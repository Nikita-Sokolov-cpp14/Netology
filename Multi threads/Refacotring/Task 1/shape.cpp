#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>

void Angular::calc_square() 
{
	if (type == Figure::sqr)
	{
		square = a * b;
	}
	else if (type == Figure::cube)
	{
		square = 2 * a * b + 2 * a * c + 2 * b * c;
	}
}

void Circular::calc_square() 
{
	if (type == Figure::circle) 
	{
		square = M_PI * radius * radius;
	}
	else if (type == Figure::cylinder)
	{
		square = M_PI * radius * radius + 2 * radius * height;
	}
}

void Angular::calc_volume() 
{
	if (type == Figure::cube) {
		volume = a * b * c;
	}
}

void Circular::calc_volume()
{
	if (type == cylinder)
	{
		volume = M_PI * radius * radius * height;
	}
}

Angular::Angular(const Figure& _type,const std::vector<std::map<char, int>>& _vertex_koordinats)
{
	type = _type;
	// заполн¤ем координаты фигуры
	vertex_koordinats = _vertex_koordinats;
	
	// стороны фигуры
	int a = abs(vertex_koordinats[0]['x'] - vertex_koordinats[1]['x']);
	int b = abs(vertex_koordinats[0]['y'] - vertex_koordinats[1]['y']);
	int c = abs(vertex_koordinats[0]['z'] - vertex_koordinats[1]['z']);

	// считаем площадь фигуры
	calc_square();

	// считаем объем фигуры
	calc_volume();
}

Circular::Circular(const Figure& _type, int _x1, int _y1, double _R, double _H)
{
	type = _type;

	// заполн¤ем координаты фигуры
	if (type == Figure::circle)
	{
		x1 = _x1; y1 = _y1;
		radius = _R;

	}
	else if (type == Figure::cylinder)
	{
		x1 = _x1; y1 = _y1;
		radius = _R;
		height = _H;
	}

	// считаем площадь фигуры
	calc_square();

	// считаем объем фигуры
	calc_volume();
}
