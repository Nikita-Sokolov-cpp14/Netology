#include "../headers/Square.h"


Square::Square(int A, int B, int C, int D, int a, int b, int c, int d) : Romb(A, B, C, D, a, b, c, d) { 
	if (A != 90 || B != 90 || C != 90 || D != 90) {
		throw creation_error("ќшибка создани€ фигуры. ”глы не равны 90.");
	}
	type = " вадрат"; 
}