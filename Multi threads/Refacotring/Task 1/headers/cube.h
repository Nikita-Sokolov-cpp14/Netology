#pragma once
#include "shape.h"

class Cube : public Shape {
public:
	std::vector<std::map<char, int>> vertex_koordinats;
	int a = 0, b = 0, c = 0;

	Cube() = default;
	Cube(const std::vector<std::map<char, int>>& _vertex_koordinats);
	void calc_square() override;
	void calc_volume() override;

	void shift(int m, int n, int k) override;
	void scaleX(int scale) override;
	void scaleY(int scale) override;
	void scaleZ(int scale) override;
	void scale(int scale) override;
};