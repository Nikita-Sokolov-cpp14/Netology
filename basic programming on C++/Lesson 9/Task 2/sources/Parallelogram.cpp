#include "../headers/Parallelogram.h"

Parallelogram::Parallelogram(int A, int B, int C, int D, int a, int b, int c, int d) : Tetragone(A, B, C, D, a, b, c, d) {
    if (A != C || B != D || a != c || b != d) {
        throw creation_error("������ �������� ������: ������� a,c � b,d �� ����� �/��� ���� A,C � B,D �� �����");
    }
    
    type = "�������������";
}