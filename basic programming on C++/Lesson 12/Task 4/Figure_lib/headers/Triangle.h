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
    TRIG_LIB_API Triangle(int a, int b, int c, int A, int B, int C);
    TRIG_LIB_API void print_figure() override;
};