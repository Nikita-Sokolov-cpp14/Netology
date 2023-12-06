#include "../Headers/Centaur.h"

Centaur::Centaur(int dist) {
    distance = dist;
    speed = 15;
    driving_time = 8;
    name = "Кентавр";
    calc_time();
}
void Centaur::set_break_time() {
    break_time = 2;
}
