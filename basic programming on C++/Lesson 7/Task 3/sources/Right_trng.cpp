#include "../headers/Right_trng.h"

Right_trng::Right_trng(int A, int a, int b, int c) : Triangle(a, b, c, A, 90 - A, 90) {
    type = "Прямоугольный треуголник";
}