#include "headers/Triangle.h"

int Triangle::get_a() { return a; }
int Triangle::get_b() { return b; }
int Triangle::get_c() { return c; }
int Triangle::get_A() { return A; }
int Triangle::get_B() { return B; }
int Triangle::get_C() { return C; }

Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
    this->A = A; this->B = B; this->C = C;
    this->a = a; this->b = b; this->c = c;
    type = "Треуголник";
}
void Triangle::print_figure() {
    std::cout << type << ":" << std::endl;
    std::cout << "Стороны:\ta = " << a << "; b = " << b << "; c = " << c << std::endl;
    std::cout << "Углы:\tA = " << A << "; B = " << B << "; C = " << C << std::endl;
    std::cout << std::endl;
}
