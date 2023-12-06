#include "../Headers/FlyingCapret.h"

FlyingCapret::FlyingCapret(int dist) {
    distance = dist;
    speed = 10;
    name = "Ковер-самолет";
    if (distance < 1000) {
        coef_dist = 0;
    }
    else if (distance < 5000) {
        coef_dist = 0.05;
    }
    else if (distance < 10000) {
        coef_dist = 0.1;
    }
    else {
        coef_dist = 0.05;
    }
    calc_time();
}
