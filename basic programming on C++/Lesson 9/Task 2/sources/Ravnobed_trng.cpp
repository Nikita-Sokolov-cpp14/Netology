#include "../headers/Ravnobed_trng.h"

Ravnobed_trng::Ravnobed_trng(int A, int B, int C, int a, int b, int c) : Triangle(a, b, c, A, B, C) {
    if (A != C || a != c) {
        throw creation_error("Ошибка создания фигуры. Причина: Углы А и С не равны и/или стороны а и с не равны.");
    }
    type = "равнобедренный треуголник";
}