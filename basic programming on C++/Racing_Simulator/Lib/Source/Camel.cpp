#include "../Headers/Camel.h"

Camel::Camel(int dist){
       speed = 10;
       driving_time = 30;
       distance = dist;
       name = "Верблюд";
       calc_time();
}

void Camel::set_break_time() {
    break_number == 0 ? break_time = 5 : break_time = 8;
}
