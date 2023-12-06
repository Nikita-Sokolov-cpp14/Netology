#include "../Headers/CamelBoost.h"

CamelBoost::CamelBoost(int dist) {
    speed = 40;
    driving_time = 10;
    break_time = 5;
    distance = dist;
    name = "Верблюд-быстроход";
    calc_time();
}
void CamelBoost::set_break_time() {
    break_number == 0 ? break_time = 5 : break_number == 1 ? break_time = 6.5 : break_time = 8;
}
