#include "../headers/Ravnostor_trng.h"

Ravnostor_trng::Ravnostor_trng(int A, int B, int C, int a, int b, int c) : Triangle(a, b, c, A, B, C) {
    if (a != b || a != c || A != 60 || B != 60 || C != 60) {
        throw creation_error("Ошибка создания фигуры: все стороны не равны м/или все углы не равны 60");
    }
    type = "Равносторонний треуголник";
}