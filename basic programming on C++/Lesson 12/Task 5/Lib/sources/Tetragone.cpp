#include "headers/Tetragone.h"

int Tetragone::get_a() { return a; }
int Tetragone::get_b() { return b; }
int Tetragone::get_c() { return c; }
int Tetragone::get_d() { return d; }
int Tetragone::get_A() { return A; }
int Tetragone::get_B() { return B; }
int Tetragone::get_C() { return C; }
int Tetragone::get_D() { return D; }
Tetragone::Tetragone(int A, int B, int C, int D, int a, int b, int c, int d) {
    this->A = A; this->B = B; this->C = C; this->D = D;
    this->a = a; this->b = b; this->c = c; this->d = d;
    type = "Четырёхугольник";
}
void Tetragone::print_figure() {
    std::cout << type << ":" << std::endl;
    std::cout << "Стороны:\ta = " << a << "; b = " << b << "; c = " << c << "; d = " << d << std::endl;
    std::cout << "Углы:\tA = " << A << "; B = " << B << "; C = " << C << "; D = " << D << std::endl;
    std::cout << std::endl;
}
