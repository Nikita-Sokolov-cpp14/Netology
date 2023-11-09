#include <iostream>
#include <string>


class Figure {
protected:
    int sides;
    std::string type;
    bool right;
public:
    Figure() {
        sides = 0;
        type = "Фигура";
    }
    virtual void print_figure() {
        std::cout << type << ":" << std::endl;
        std::cout << "Правильная" << std::endl;
        std::cout << "Число сторон: " << sides << "\n" << std::endl;
    }
    virtual bool check() { return right = 1; }
};

class Triangle : public Figure {
protected:
    int A, B, C;
    int a, b, c;
public:
    bool check() override {
        return (A + B + C == 180);
    }
    Triangle(int A, int B, int C, int a, int b, int c) {
        this->A = A; this->B = B; this->C = C;
        this->a = a; this->b = b; this->c = c;
        type = "Треуголник";
        sides = 3;
    }
    void print_figure() override {
        std::cout << type << ":" << std::endl;
        check() ? std::cout << "Правильная" << std::endl : std::cout << "Неправильная" << std::endl;
        std::cout << "Колличество сторон " << sides << std::endl;
        std::cout << "Стороны:\ta = " << a << "; b = " << b << "; c = " << c << std::endl;
        std::cout << "Углы:\tA = " << A << "; B = " << B << "; C = " << C << std::endl;
        std::cout << std::endl;
    }
};
class Tetragone : public Figure {
protected:
    int A, B, C, D;
    int a, b, c, d;
    int sides = 4;
    std::string type;
    bool right;
public:
    bool check() override {
        return (A + B + C + D == 360);
    }
    Tetragone(int A, int B, int C, int D, int a, int b, int c, int d) {
        this->A = A; this->B = B; this->C = C, this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        sides = 4;
        type = "Четырехуголник";
    }
    void print_figure() override {
        std::cout << type << ":" << std::endl;
        check() ? std::cout << "Правильная" << std::endl : std::cout << "Неправильная" << std::endl;
        std::cout << "Колличество сторон " << sides << std::endl;
        std::cout << "Стороны:\ta = " << a << "; b = " << b << "; c = " << c << "; d = " << d << std::endl;
        std::cout << "Углы:\tA = " << A << "; B = " << B << "; C = " << C << "; D = " << D << std::endl;
        std::cout << std::endl;
    }
};

class Right_trng : public Triangle {
public:
    Right_trng(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
        type = "Прямоугольный треуголник";
    }
    bool check() override {
        return right = (C == 90 && Triangle::check());
    }

};
class Ravnobed_trng : public Triangle {
public:
    Ravnobed_trng(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
        type = "Равнобедренный треуголник";
    }
    bool check() override {
        return right = (A == C && a == c && Triangle::check());
    }
};
class Ravnostor_trng : public Triangle {
public:
    Ravnostor_trng(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
        type = "Равносторонний треуголник";
    }
    bool check() override {
        return right = (A == 60 && B == 60 && C == 60 && (a == b && b == c) && Triangle::check());
    }
};

class Parallelogram : public Tetragone {
public:
    Parallelogram(int A, int B, int C, int D, int a, int b, int c, int d) : Tetragone(A, B, C, D ,a, b, c, d) {
        type = "Параллелограм";
    }
    bool check() override {
        return right = (A == C && B == D && a == c && b == d && Tetragone::check());
    }

};
class Romb : public Parallelogram {
public:
    Romb(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
        type = "Ромб";
    }
    bool check() override {
        return right = (a == b && d == c && c == d && Parallelogram::check());
    }
};
class Rectangle : public Parallelogram {
public:
    Rectangle(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
        type = "Прямоугольник"; }
    bool check() override {
        return right = (A == B && B == C && C == 90 && Parallelogram::check());
    }
};
class Square : public Parallelogram {
public:
    Square(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
        type = "Квадрат"; }
    bool check() override {
        return right = (A == B && B == C && C == 90 && a == b && b == c && c == d && Parallelogram::check());
    }
};

void print_info(Figure* fig) {
    fig->print_figure();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    Figure figure;
    print_info(&figure);

    Triangle simple_trng_1(30, 85, 65, 10, 11, 12);
    print_info(&simple_trng_1);

    Triangle simple_trng_2(30, 120, 65, 10, 11, 12);
    print_info(&simple_trng_2);

    Right_trng r_trng_1(45, 45, 90, 3, 4, 5);
    print_info(&r_trng_1);

    Right_trng r_trng_2(40, 40, 100, 3, 4, 5);
    print_info(&r_trng_2);

    Ravnobed_trng ravobed_trng_1(40, 100, 40, 3, 4, 3);
    print_info(&ravobed_trng_1);

    Ravnobed_trng ravobed_trng_2(30, 40, 110, 3, 4, 1);
    print_info(&ravobed_trng_2);

    Ravnostor_trng ravnostor_trng_1(60, 60, 60, 2, 2, 2);
    print_info(&ravnostor_trng_1);

    Ravnostor_trng ravnostor_trng_2(30, 40, 110, 3, 4, 1);
    print_info(&ravnostor_trng_2);

    Tetragone simple_tetragone_1(20, 10, 60, 200, 1, 2, 3, 6);
    print_info(&simple_tetragone_1);

    Tetragone simple_tetragone_2(20, 40, 60, 240, 1, 2, 3, 6);
    print_info(&simple_tetragone_2);

    Parallelogram parallelogram_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info(&parallelogram_1);

    Parallelogram parallelogram_2(30, 150, 30, 150, 1, 2, 1, 2);
    print_info(&parallelogram_2);

    Romb romb_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info(&romb_1);

    Romb romb_2(30, 150, 30, 150, 2, 2, 2, 2);
    print_info(&romb_2);

    Rectangle rectangle_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info(&rectangle_1);

    Rectangle rectangle_2(90, 90, 90, 90, 1, 2, 1, 2);
    print_info(&rectangle_2);

    Square square_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info(&square_1);

    Square square_2(90, 90, 90, 90, 2, 2, 2, 2);
    print_info(&square_2);

    return 0;
}