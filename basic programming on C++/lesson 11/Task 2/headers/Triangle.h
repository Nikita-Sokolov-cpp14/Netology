#pragma once
#include "../headers/Figure.h"

class Triangle : public Figure {
protected:
    int A, B, C;
    int a, b, c;
public:
    int get_a();
    int get_b();
    int get_c();
    int get_A();
    int get_B();
    int get_C();
    Triangle(int a, int b, int c, int A, int B, int C);
    void print_figure() override;
};