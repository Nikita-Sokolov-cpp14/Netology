#include "cube.h"

Cube::Cube(const std::vector<std::map<char, int>>& _vertex_koordinats) :
	vertex_koordinats(_vertex_koordinats)
{
	a = abs(vertex_koordinats[1]['x'] - vertex_koordinats[0]['x']);
	b = abs(vertex_koordinats[1]['y'] - vertex_koordinats[0]['y']);
	c = abs(vertex_koordinats[1]['z'] - vertex_koordinats[0]['z']);

	calc_square();
	calc_volume();
}

void Cube::calc_square()
{
	square = 2 * a * b + 2 * a * c + 2 * b * c;
}

void Cube::calc_volume()
{
	volume = a * b * c;
}

void Cube::shift(int m, int n, int k)
{
	for (int i = 0; i < 8; ++i)
	{
		vertex_koordinats[i]['x'] += m;
		vertex_koordinats[i]['y'] += n;
		vertex_koordinats[i]['z'] += k;
	}
}

void Cube::scaleX(int scale)
{
	for (int i = 0; i < 8; ++i)
	{
		vertex_koordinats[i]['x'] *= scale;
	}
}

void Cube::scaleY(int scale)
{
	for (int i = 0; i < 8; ++i)
	{
		vertex_koordinats[i]['y'] *= scale;
	}
}

void Cube::scaleZ(int scale)
{
	for (int i = 0; i < 8; ++i)
	{
		vertex_koordinats[i]['z'] *= scale;
	}
}

void Cube::scale(int scale)
{
	for (int i = 0; i < 8; ++i)
	{
		vertex_koordinats[i]['x'] /= scale;
		vertex_koordinats[i]['y'] /= scale;
		vertex_koordinats[i]['z'] /= scale;
	}
}