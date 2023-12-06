#include "../Headers/Air.h"

void Air::calc_time() {
    full_time = distance * (1 - coef_dist) / speed;
}
