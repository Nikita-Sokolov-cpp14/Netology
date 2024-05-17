#include "square.h"

Square::Square(const std::vector<std::map<char, int>>& _vertex_koordinats) :
	vertex_koordinats(_vertex_koordinats)
{
	a = abs(vertex_koordinats[1]['x'] - vertex_koordinats[0]['x']);
	b = abs(vertex_koordinats[1]['y'] - vertex_koordinats[0]['y']);

	calc_square();
	calc_volume();
}

void Square::calc_square()
{
	square = a * b;
}

void Square::calc_volume() { volume = 0; }

void Square::shift(int m, int n, int k)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex_koordinats[i]['x'] += m;
		vertex_koordinats[i]['y'] += n;
	}
}

void Square::scaleX(int scale)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex_koordinats[i]['x'] *= scale;
	}
}

void Square::scaleY(int scale)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex_koordinats[i]['y'] *= scale;
	}
}

void Square::scaleZ(int scale)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex_koordinats[i]['z'] *= scale;
	}
}

void Square::scale(int scale)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex_koordinats[i]['x'] /= scale;
		vertex_koordinats[i]['y'] /= scale;
	}
}
