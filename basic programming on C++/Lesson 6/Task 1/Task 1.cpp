#include <iostream>
#include <string>

class Figure {
protected: 
    int num_sides;
    std::string name;
public:
    void print_num_sides(std::string name, int sides) { std::cout << name << ": " << sides << std::endl; }
    int get_sides() { return num_sides; }
    std::string get_name() { return name; }
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

    tet.print_num_sides(tet.get_name(), tet.get_sides());
    trian.print_num_sides(trian.get_name(), trian.get_sides());
    figure.print_num_sides(figure.get_name(), figure.get_sides());
    return 0;
}
