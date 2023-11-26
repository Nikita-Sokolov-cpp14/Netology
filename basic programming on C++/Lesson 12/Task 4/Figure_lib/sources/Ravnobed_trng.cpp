#include "../headers/Ravnobed_trng.h"

Ravnobed_trng::Ravnobed_trng(int A, int B, int a, int b) : Triangle(a, b, a, A, B, A) {
    type = "Равнобедренный треуголник";
}