#include "../headers/Romb.h"

Romb::Romb(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) { 
	if (a != b || b != c || c != d) {
		throw creation_error("Ошибка создаия фигуры: все стороны не равны");
	}
	type = "Ромб"; 
}
