#include "../headers/Right_trng.h"

Right_trng::Right_trng(int A,int B, int C, int a, int b, int c) : Triangle(a, b, c, A, B, C) {

    if (C != 90) {
        throw creation_error("Ошибка создания фигуры. Угол С не равен 90.");
    }
    type = "прямоугольный треуголник";
}