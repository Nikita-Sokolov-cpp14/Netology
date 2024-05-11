#include "transform.h"

Transform::Transform(const Angular& _angular)
{
	angular = _angular;

	switch (angular.type)
	{
	case Figure::line:
		number_of_vertex = 2;
		break;
	case Figure::sqr:
		number_of_vertex = 4;
		break;
	case Figure::cube:
		number_of_vertex = 8;
		break;
	default:
		number_of_vertex = 0;
	}
}

void Transform::shift_line(int m, int n)
{
	angular.vertex_koordinats[0]['x'] += m;
	angular.vertex_koordinats[1]['x'] += m;
	angular.vertex_koordinats[0]['y'] += n;
	angular.vertex_koordinats[1]['y'] += n;
}

void Transform::shift_sqr(int m, int n)
{
	for (int i = 0; i < 4; ++i)
	{
		angular.vertex_koordinats[i]['x'] += m;
		angular.vertex_koordinats[i]['y'] += n;
	}
}

void Transform::shift_cube(int m, int n, int k)
{
	for (int i = 0; i < 8; ++i) 
	{
		angular.vertex_koordinats[i]['x'] += m;
		angular.vertex_koordinats[i]['y'] += n;
		angular.vertex_koordinats[i]['z'] += k;
	}
}

Angular Transform::shift(int m, int n, int k)
{
	switch (angular.type)
	{
	case Figure::line:
		shift_line(m, n);
		break;
	case Figure::sqr:
		shift_sqr(m, n);
		break;
	case Figure::cube:
		shift_cube(m, n, k);
		break;
	}
	return angular;
}

Angular Transform::scaleX(int scale)
{
	for (int i = 0; i < number_of_vertex; ++i)
	{
		angular.vertex_koordinats[i]['x'] *= scale;
	}

	return angular;
}

Angular Transform::scaleY(int scale)
{
	for (int i = 0; i < number_of_vertex; ++i) 
	{
		angular.vertex_koordinats[i]['y'] *= scale;
	}

	return angular;
}

Angular Transform::scaleZ(int scale)
{
	for (int i = 0; i < number_of_vertex; ++i) 
	{
		angular.vertex_koordinats[i]['z'] *= scale;
	}

	return angular;
}

void Transform::scale_line(int scale)
{
	angular.vertex_koordinats[0]['x'] /= scale;
	angular.vertex_koordinats[0]['y'] /= scale;
	angular.vertex_koordinats[1]['x'] /= scale;
	angular.vertex_koordinats[1]['y'] /= scale;
}

void Transform::scale_sqr(int scale)
{
	for (int i = 0; i < 4; ++i)
	{
		angular.vertex_koordinats[i]['x'] /= scale;
		angular.vertex_koordinats[i]['y'] /= scale;
	}
}

void Transform::scale_cube(int scale)
{
	for (int i = 0; i < 8; ++i) 
	{
		angular.vertex_koordinats[i]['x'] /= scale;
		angular.vertex_koordinats[i]['y'] /= scale;
	}
}

Angular Transform::scale(int s)
{
	switch (angular.type)
	{
	case Figure::line:
		scale_line(s);
		break;
	case Figure::sqr:
		scale_sqr(s);
		break;
	case Figure::cube:
		scale_cube(s);
		break;
	}
	return angular;
}
