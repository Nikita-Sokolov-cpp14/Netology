#include "../headers/Parallelogram.h"

Parallelogram::Parallelogram(int A, int B, int C, int D, int a, int b, int c, int d) : Tetragone(A, B, C, D, a, b, c, d) {
    if (A != C || B != D || a != c || b != d) {
        throw creation_error("Ошибка создания фигуры: Стороны a,c и b,d не равны и/или углы A,C и B,D не равны");
    }
    
    type = "Параллелограм";
}