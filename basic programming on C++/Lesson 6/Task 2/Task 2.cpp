#include <iostream>
#include <string>


class Triangle {
protected:
    int A, B, C;
    int a, b, c;
    std::string type;
public:
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    std::string get_type() { return type; }
};
class Tetragone {
protected:
    int A, B, C, D;
    int a, b, c, d;
    std::string type;
public:
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    std::string get_type() { return type; }
};
class Right_trng : public Triangle {
public:
    Right_trng(int A, int a, int b, int c) {
        this->A = A; this->B = 90 - A; this->C = 90;
        this->a = a; this->b = b; this->c = c;
        type = "Прямоугольный треуголник";
    }
};
class Ravnobed_trng : public Triangle {
public:
    Ravnobed_trng(int A, int B, int a, int b) {
        this->A = A; this->B = B; this->C = A;
        this->a = a; this->b = b; this->c = a;
        type = "Равнобедренный треуголник";
    }
};
class Ravnostor_trng : public Triangle {
public:
    Ravnostor_trng(int a) {
        this->A = 60; this->B = 60; this->C = 60;
        this->a = a; this->b = a; this->c = a;
        type = "Равносторонний треуголник";
    }
};
class Simple_trng : public Triangle {
public:
    Simple_trng(int a, int b, int c, int A, int B, int C) {
        this->A = A; this->B = B; this->C = C;
        this->a = a; this->b = b; this->c = c;
        type = "Треуголник";
    }
};
class Parallelogram : public Tetragone {
public:
    Parallelogram(int A, int a, int b) {
        this->A = A; this->B = 180 - A; this->C = A, this->D = this->B;
        this->a = a; this->b = b; this->c = a; this->d = b;
        type = "Параллелограм";
    }
};
class Romb : public Parallelogram {
public:
    Romb(int A, int a) : Parallelogram(A, a, a) { type = "Ромб"; };
};
class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b) : Parallelogram(90, a, b) { type = "Прямоугольник"; }
};
class Square : public Romb {
public:
    Square(int a) : Romb(90, a) { type = "Квадрат"; }
};
class Simple_tetragone : public Tetragone {
public:
    Simple_tetragone(int A, int B, int C, int D, int a, int b, int c, int d) {
        this->A = A; this->B = B; this->C = C; this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        type = "Четырёхугольник";
    }
};


void print_info_trng(Triangle* p_trng) {
    std::cout << p_trng->get_type() << ":" << std::endl;
    std::cout << "Стороны:\ta = " << p_trng->get_a() << "; b = " << p_trng->get_b() << "; c = " << p_trng->get_c() << std::endl;
    std::cout << "Углы:\tA = " << p_trng->get_A() << "; B = " << p_trng->get_B() << "; C = " << p_trng->get_C() << std::endl;
    std::cout << std::endl;
}

void print_info_ttrg(Tetragone* p_ttrg) {
    std::cout << p_ttrg->get_type() << ":" << std::endl;
    std::cout << "Стороны:\ta = " << p_ttrg->get_a() << "; b = " << p_ttrg->get_b() << "; c = " << p_ttrg->get_c() << "; d = " << p_ttrg->get_d() << std::endl;
    std::cout << "Углы:\tA = " << p_ttrg->get_A() << "; B = " << p_ttrg->get_B() << "; C = " << p_ttrg->get_C() << "; D = " << p_ttrg->get_D() << std::endl;
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    Right_trng r_trng(45, 3, 4, 5);
    print_info_trng(&r_trng);

    Ravnobed_trng ravobed_trng(2, 3, 20, 40);
    print_info_trng(&ravobed_trng);

    Ravnostor_trng ravnostor_trng(10);
    print_info_trng(&ravnostor_trng);

    Simple_trng simple_trng(10, 11, 12, 30, 85, 65);
    print_info_trng(&simple_trng);

    Parallelogram parallelogram(30, 5, 8);
    print_info_ttrg(&parallelogram);

    Romb romb(30, 4);
    print_info_ttrg(&romb);

    Rectangle rectangle(5, 7);
    print_info_ttrg(&rectangle);

    Square square(10);
    print_info_ttrg(&square);

    Simple_tetragone simple_tetragone(20, 40, 60, 240, 1, 2, 3, 6);
    print_info_ttrg(&simple_tetragone);

    return 0;
}