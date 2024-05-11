#pragma once
#include <string>
#include <vector>
#include <map>

enum Figure {
	line,
	sqr,
	cube,
	circle,
	cylinder
};

class Shape
{
public:
	Figure type;
	double volume = 0;
	double square = 0;	

	virtual void calc_square() = 0;
	virtual void calc_volume() = 0;

	virtual ~Shape() {};
};

class Angular : public Shape {
public:
	std::vector<std::map<char, int>> vertex_koordinats;
	int a = 0, b = 0, c = 0;

	Angular() = default;
	Angular(const Figure& _type, const std::vector<std::map<char, int>>& _vertex_koordinats);
	void calc_square() override;
	void calc_volume() override;
};

class Circular : public Shape {
public:
	double height = 0;
	double radius = 0;
	int x1 = 0, y1 = 0;

	Circular() = default;
	Circular(const Figure& _type, int _x1, int _y1, double _R, double _H);
	void calc_square() override;
	void calc_volume() override;
};
