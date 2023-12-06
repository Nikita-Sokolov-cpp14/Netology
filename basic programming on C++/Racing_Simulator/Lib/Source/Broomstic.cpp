#include "../Headers/Broomstic.h"

Broomstic::Broomstic(int dist) {
    distance = dist;
    speed = 20;
    coef_dist = static_cast<int>(distance / 1000) / 100;
    name = "Метла";
    calc_time();
}
