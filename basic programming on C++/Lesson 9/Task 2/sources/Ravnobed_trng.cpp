#include "../headers/Ravnobed_trng.h"

Ravnobed_trng::Ravnobed_trng(int A, int B, int C, int a, int b, int c) : Triangle(a, b, c, A, B, C) {
    if (A != C || a != c) {
        throw creation_error("������ �������� ������. �������: ���� � � � �� ����� �/��� ������� � � � �� �����.");
    }
    type = "�������������� ����������";
}