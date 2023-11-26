#pragma once
#include "Figure.h"


class Tetragone : public Figure {
protected:
    int A, B, C, D;
    int a, b, c, d;
public:
    int get_a();
    int get_b();
    int get_c();
    int get_d();
    int get_A();
    int get_B();
    int get_C();
    int get_D();
    TRIG_LIB_API Tetragone(int A, int B, int C, int D, int a, int b, int c, int d);
    TRIG_LIB_API void print_figure() override;
};