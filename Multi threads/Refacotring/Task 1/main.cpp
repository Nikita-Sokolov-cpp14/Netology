#include <iostream>
#include <vector>
#include <map>

#include "shape.h"
#include "line.h"
#include "square.h"
#include "cube.h"
#include "circle.h"
#include "cylinder.h"

int main()
{
	std::map<char, int> point;
	point['x'] = 0;
	point['y'] = 0;
	point['z'] = 0;

	std::vector<std::map<char, int>> line_koord;
	point['x'] = 1; point['y'] = 2; point['z'] = 3;
	line_koord.push_back(point);
	point['x'] = 1; point['y'] = 2; point['z'] = 6;
	line_koord.push_back(point);
	Line line(line_koord);

	line.shift(10, 20, 30);
	line.scale(2);

	std::vector<std::map<char, int>> cube_koord{8};
	cube_koord[0]['x'] = 1; cube_koord[0]['y'] = 0; cube_koord[0]['z'] = 0;
	cube_koord[1]['x'] += 0; cube_koord[1]['y'] = 1; cube_koord[1]['z'] = 0;
	cube_koord[2]['x'] = 0; cube_koord[2]['y'] = 0; cube_koord[2]['z'] = 1;
	cube_koord[3]['x'] = 1; cube_koord[3]['y'] = 1; cube_koord[3]['z'] = 0;
	cube_koord[4]['x'] = 0; cube_koord[4]['y'] = 1; cube_koord[4]['z'] = 1;
	cube_koord[5]['x'] = 1; cube_koord[5]['y'] = 0; cube_koord[5]['z'] = 1;
	cube_koord[6]['x'] = 1; cube_koord[6]['y'] = 1; cube_koord[6]['z'] = 1;
	cube_koord[7]['x'] = 0; cube_koord[7]['y'] = 0; cube_koord[7]['z'] = 0;
	Cube cube(cube_koord);

	cube.shift(10, 10, 10);
	cube.scale(2);
	cube.scaleX(3);
	cube.scaleX(4);
	cube.scaleX(5);
}