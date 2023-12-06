#include "../Headers/BootsRover.h"

BootsRover::BootsRover(int dist) {
    distance = dist;
    speed = 6;
    driving_time = 60;
    name = "Ботинки-вездеходы";
    calc_time();
}
void BootsRover::set_break_time() {
    break_number == 0 ? break_time = 10 : break_time = 5;
}
