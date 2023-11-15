#include "../headers/Rectangle.h"

Rectangle::Rectangle(int A, int B, int C, int D, int a, int b, int c, int d) : Parallelogram(A, B, C, D, a, b, c, d) { 
	if (A != 90 || B != 90 || C != 90 || D != 90) {
		throw creation_error("Ошибка создания фигуры: Углы не равны 90.");
	}
	type = "Прямоугольник"; 
}