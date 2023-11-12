#include "../headers/Parallelogram.h"

Parallelogram::Parallelogram(int A, int a, int b) : Tetragone(A, 180 - A, A, 180 - A, a, b, a, b) {
    type = "Параллелограм";
}