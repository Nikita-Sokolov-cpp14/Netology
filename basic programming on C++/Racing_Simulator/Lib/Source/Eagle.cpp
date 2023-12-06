#include "../Headers/Eagle.h"

Eagle::Eagle(int dist) {
    distance = dist;
    speed = 8;
    coef_dist = 0.06;
    name = "Орел";
    calc_time();
}
