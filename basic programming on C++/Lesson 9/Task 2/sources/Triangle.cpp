#include "../headers/Triangle.h"
#include "../headers/Errors.h"

int Triangle::get_a() { return a; }
int Triangle::get_b() { return b; }
int Triangle::get_c() { return c; }
int Triangle::get_A() { return A; }
int Triangle::get_B() { return B; }
int Triangle::get_C() { return C; }

Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
    if (A + B + C != 180) {
        throw creation_error("ошибка создания фигуры. Сумма углов не равна 180.");
    }
    this->A = A; this->B = B; this->C = C;
    this->a = a; this->b = b; this->c = c;
    type = "треуголник";
}
void Triangle::print_figure() {
    std::cout << "Создан " << type << ":" << std::endl;
    std::cout << "Стороны:\ta = " << a << "; b = " << b << "; c = " << c << std::endl;
    std::cout << "Углы:\tA = " << A << "; B = " << B << "; C = " << C << std::endl;
}
