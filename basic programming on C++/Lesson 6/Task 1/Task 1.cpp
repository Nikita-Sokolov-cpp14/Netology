#include <iostream>
#include <string>

class Figure {
protected: 
    int num_sides;
    std::string name;
public:
    void print_num_sides() { std::cout << name << ": " << num_sides << std::endl; }
};
class Tetragon : public Figure {
public:
    Tetragon() { num_sides = 4; name = "Четырёхугольник"; }
};
class Triangle : public Figure {
public:
    Triangle() { num_sides = 3; name = "Треугольник"; }
};
class Other_figure : public Figure {
public:
    Other_figure() { num_sides = 0; name = "Фигура"; }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Tetragon tet;
    Triangle trian;
    Other_figure figure;

    tet.print_num_sides();
    trian.print_num_sides();
    figure.print_num_sides();
    return 0;
}
