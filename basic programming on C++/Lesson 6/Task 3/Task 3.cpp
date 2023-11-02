#include <iostream>
#include <string>

//Базовые классы
class Triangle {
protected:
    int A, B, C;
    int a, b, c;
    int sides = 3;
    std::string type;
    bool right;
public:
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_sides() { return sides; }
    bool get_right() { return right; }
    std::string get_type() { return type; }
    virtual bool check() {
        return (A + B + C == 180);
    }
};
class Tetragone {
protected:
    int A, B, C, D;
    int a, b, c, d;
    int sides = 4;
    std::string type;
    bool right;
public:
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_sides() { return sides; }
    bool get_right() { return right; }
    std::string get_type() { return type; }
    virtual bool check() {
        return (A + B + C + D == 360);
    }
};

//классы потомки
class Right_trng : public Triangle {
public:
    Right_trng(int A, int B, int C, int a, int b, int c) {
        this->A = A; this->B = B; this->C = C;
        this->a = a; this->b = b; this->c = c;
        type = "Прямоугольный треуголник";
    }
    bool check() override {
        return right = (C == 90 && Triangle::check());
    }

};
class Ravnobed_trng : public Triangle {
public:
    Ravnobed_trng(int A, int B, int C, int a, int b, int c) {
        this->A = A; this->B = B; this->C = C;
        this->a = a; this->b = b; this->c = c;
        type = "Равнобедренный треуголник";
    }
    bool check() override {
        return right = (A == C && a == c && Triangle::check());
    }
};
class Ravnostor_trng : public Triangle {
public:
    Ravnostor_trng(int A, int B, int C, int a, int b, int c) {
        this->A = A; this->B = B; this->C = C;
        this->a = a; this->b = b; this->c = c;
        type = "Равносторонний треуголник";
    }
    bool check() override {
        return right = (A == 60 && B == 60 && C == 60 && (a == b && b == c) && Triangle::check());
    }
};
class Simple_trng : public Triangle {
public:
    Simple_trng(int a, int b, int c, int A, int B, int C) {
        this->A = A; this->B = B; this->C = C;
        this->a = a; this->b = b; this->c = c;
        type = "Треуголник";
    }
    bool check() override {
        return right = Triangle::check();
    }
};
class Parallelogram : public Tetragone {
public:
    Parallelogram(int A, int B, int C, int D, int a, int b, int c, int d) {
        this->A = A; this->B = B; this->C = C, this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        type = "Параллелограм";
    }
    bool check() override {
        return right = (A == C && B == D && a == c && b == d && Tetragone::check());
    }

};
class Romb : public Parallelogram {
public:
    Romb(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
        this->A = A; this->B = B; this->C = C; this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        type = "Ромб";
    }
    bool check() override {
        return right = (a == b && d == c && c == d && Parallelogram::check());
    }
};
class Rectangle : public Parallelogram {
public:
    Rectangle(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
        this->A = A; this->B = B; this->C = C; this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        type = "Прямоугольник"; }
    bool check() override {
        return right = (A == B && B == C && C == 90 && Parallelogram::check());
    }
};
class Square : public Parallelogram {
public:
    Square(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) {
        this->A = A; this->B = B; this->C = C; this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        type = "Квадрат"; }
    bool check() override {
        return right = (A == B && B == C && C == 90 && a == b && b == c && c == d && Parallelogram::check());
    }
};
class Simple_tetragone : public Tetragone {
public:
    Simple_tetragone(int A, int B, int C, int D, int a, int b, int c, int d) {
        this->A = A; this->B = B; this->C = C; this->D = D;
        this->a = a; this->b = b; this->c = c; this->d = d;
        type = "Четырёхугольник";
    }
    bool check() override {
        return Tetragone::check();
    }
};

//принимают указатель на базовый экземпляр
void print_info_trng(Triangle* p_trng) {
    std::cout << p_trng->get_type() << ":" << std::endl;
    p_trng->check() ? std::cout << "Правильная" << std::endl : std::cout << "Неправильная" << std::endl;
    std::cout << "Колличество сторон " << p_trng->get_sides() << std::endl;
    std::cout << "Стороны:\ta = " << p_trng->get_a() << "; b = " << p_trng->get_b() << "; c = " << p_trng->get_c() << std::endl;
    std::cout << "Углы:\tA = " << p_trng->get_A() << "; B = " << p_trng->get_B() << "; C = " << p_trng->get_C() << std::endl;
    std::cout << std::endl;
}

void print_info_ttrg(Tetragone* p_ttrg) {
    std::cout << p_ttrg->get_type() << ":" << std::endl;
    p_ttrg->check() ? std::cout << "Правильная" << std::endl : std::cout << "Неправильная" << std::endl;
    std::cout << "Колличество сторон " << p_ttrg->get_sides() << std::endl;
    std::cout << "Стороны:\ta = " << p_ttrg->get_a() << "; b = " << p_ttrg->get_b() << "; c = " << p_ttrg->get_c() << "; d = " << p_ttrg->get_d() << std::endl;
    std::cout << "Углы:\tA = " << p_ttrg->get_A() << "; B = " << p_ttrg->get_B() << "; C = " << p_ttrg->get_C() << "; D = " << p_ttrg->get_D() << std::endl;
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    
    Simple_trng simple_trng_1(10, 11, 12, 30, 85, 65);
    print_info_trng(&simple_trng_1); // передаётся адрес на производный экземпляр

    Simple_trng simple_trng_2(10, 11, 12, 30, 120, 65);
    print_info_trng(&simple_trng_2);

    Right_trng r_trng_1(45, 45, 90, 3, 4, 5);
    print_info_trng(&r_trng_1);

    Right_trng r_trng_2(40, 40, 100, 3, 4, 5);
    print_info_trng(&r_trng_2);

    Ravnobed_trng ravobed_trng_1(40, 100, 40, 3, 4, 3);
    print_info_trng(&ravobed_trng_1);

    Ravnobed_trng ravobed_trng_2(30, 40, 110, 3, 4, 1);
    print_info_trng(&ravobed_trng_2);

    Ravnostor_trng ravnostor_trng_1(60, 60, 60, 2, 2, 2);
    print_info_trng(&ravnostor_trng_1);

    Ravnostor_trng ravnostor_trng_2(30, 40, 110, 3, 4, 1);
    print_info_trng(&ravnostor_trng_2);

    Simple_tetragone simple_tetragone_1(20, 10, 60, 200, 1, 2, 3, 6);
    print_info_ttrg(&simple_tetragone_1);

    Simple_tetragone simple_tetragone_2(20, 40, 60, 240, 1, 2, 3, 6);
    print_info_ttrg(&simple_tetragone_2);

    Parallelogram parallelogram_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info_ttrg(&parallelogram_1);

    Parallelogram parallelogram_2(30, 150, 30, 150, 1, 2, 1, 2);
    print_info_ttrg(&parallelogram_2);

    Romb romb_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info_ttrg(&romb_1);

    Romb romb_2(30, 150, 30, 150, 2, 2, 2, 2);
    print_info_ttrg(&romb_2);

    Rectangle rectangle_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info_ttrg(&rectangle_1);

    Rectangle rectangle_2(90, 90, 90, 90, 1, 2, 1, 2);
    print_info_ttrg(&rectangle_2);

    Square square_1(30, 60, 23, 40, 1, 2, 5, 8);
    print_info_ttrg(&square_1);

    Square square_2(90, 90, 90, 90, 2, 2, 2, 2);
    print_info_ttrg(&square_2);

    return 0;
}