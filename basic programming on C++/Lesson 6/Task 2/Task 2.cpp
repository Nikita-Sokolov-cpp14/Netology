#include <iostream>
#include <string>


class Figure {
protected:
    std::string type;
public:
    virtual void print_figure() {}
};

class Triangle: public Figure {
protected:
    int A, B, C;
    int a, b, c;
public:
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    Triangle(int a, int b, int c, int A, int B, int C) {
        this->A = A; this->B = B; this->C = C;
        this->a = a; this->b = b; this->c = c;
        type = "Треуголник";
    }
    void print_figure() override {
        std::cout << type << ":" << std::endl;
        std::cout << "Стороны:\ta = " << a << "; b = " << b << "; c = " << c << std::endl;
        std::cout << "Углы:\tA = " << A << "; B = " << B << "; C = " << C << std::endl;
        std::cout << std::endl;
    }
};
class Right_trng : public Triangle {
public:
    Right_trng(int A, int a, int b, int c) : Triangle(a, b, c, A, 90 - A, 90) {
        type = "Прямоугольный треуголник";
    }
};
class Ravnobed_trng : public Triangle {
public:
    Ravnobed_trng(int A, int B, int a, int b) : Triangle(a, b, a, A, B, A) {
        type = "Равнобедренный треуголник";
    }
};
class Ravnostor_trng : public Triangle {
public:
    Ravnostor_trng(int a) : Triangle(a, a, a, 60, 60, 60) {
        type = "Равносторонний треуголник";
    }
};

class Tetragone : public Figure {
protected:
    int A, B, C, D;
    int a, b, c, d;
public:
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }
    Tetragone(int A, int B, int C, int D, int a, int b, int c, int d) {
        this->A = A; this->B = B; this->C = C; this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        type = "Четырёхугольник";
    }
    void print_figure() override {
        std::cout << type << ":" << std::endl;
        std::cout << "Стороны:\ta = " << a << "; b = " << b << "; c = " << c << "; d = " << d << std::endl;
        std::cout << "Углы:\tA = " << A << "; B = " << B << "; C = " << C << "; D = " << D << std::endl;
        std::cout << std::endl;
    }
};
class Parallelogram : public Tetragone {
public:
    Parallelogram(int A, int a, int b) : Tetragone(A, 180 - A, A, 180 - A, a, b, a, b) {
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

void print_info(Figure* figure) {
    figure->print_figure();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Right_trng r_trng(45, 3, 4, 5);
    print_info(&r_trng);

    Ravnobed_trng ravobed_trng(2, 3, 20, 40);
    print_info(&ravobed_trng);

    Ravnostor_trng ravnostor_trng(10);
    print_info(&ravnostor_trng);

    Triangle simple_trng(10, 11, 12, 30, 85, 65);
    print_info(&simple_trng);

    Parallelogram parallelogram(30, 5, 8);
    print_info(&parallelogram);

    Romb romb(30, 4);
    print_info(&romb);

    Rectangle rectangle(5, 7);
    print_info(&rectangle);

    Square square(10);
    print_info(&square);

    Tetragone simple_tetragone(20, 40, 60, 240, 1, 2, 3, 6);
    print_info(&simple_tetragone);

    return 0;
}