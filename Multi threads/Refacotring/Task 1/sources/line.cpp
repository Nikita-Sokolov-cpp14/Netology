#include "line.h"

Line::Line(const std::vector<std::map<char, int>>& _vertex_koordinats) :
	vertex_koordinats(_vertex_koordinats)
{
	calc_square();
	calc_volume();
}

void Line::calc_square() { square = 0; }
void Line::calc_volume() { volume = 0; }

void Line::shift(int m, int n, int k)
{
	vertex_koordinats[0]['x'] += m;
	vertex_koordinats[1]['x'] += m;
	vertex_koordinats[0]['y'] += n;
	vertex_koordinats[1]['y'] += n;
}

void Line::scaleX(int scale)
{
	vertex_koordinats[0]['x'] *= scale;
	vertex_koordinats[1]['x'] *= scale;
}

void Line::scaleY(int scale)
{
	vertex_koordinats[0]['y'] *= scale;
	vertex_koordinats[1]['y'] *= scale;
}

void Line::scaleZ(int scale)
{
	vertex_koordinats[0]['z'] *= scale;
	vertex_koordinats[1]['z'] *= scale;
}

void Line::scale(int scale)
{
	vertex_koordinats[0]['x'] /= scale;
	vertex_koordinats[1]['x'] /= scale;

	vertex_koordinats[0]['y'] /= scale;
	vertex_koordinats[1]['y'] /= scale;
}