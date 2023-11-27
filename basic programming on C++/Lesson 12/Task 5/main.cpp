#include <iostream>
#include <string>

#include "headers/Figure.h"

#include "headers/Triangle.h"
#include "headers/Tetragone.h"

#include "headers/Right_trng.h"
#include "headers/Ravnobed_trng.h"
#include "headers/Ravnostor_trng.h"

#include "headers/Parallelogram.h"
#include "headers/Romb.h"
#include "headers/Rectangle.h"
#include "headers/Square.h"



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
    system("pause");

    return 0;
}