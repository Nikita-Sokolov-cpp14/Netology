#include "../Headers/Ground.h"

void Ground::set_break_time() {}
void Ground::calc_time() {
    while (distance > driving_time * speed) {
        set_break_time();
        break_number++;
        full_time += driving_time + break_time;
        distance -= driving_time * speed;
    }
    full_time += static_cast<double>(distance) / speed;
}
