#include "../Headers/Racing.h"

#include "../Headers/Camel.h"
#include "../Headers/CamelBoost.h"
#include "../Headers/Centaur.h"
#include "../Headers/BootsRover.h"
#include "../Headers/FlyingCapret.h"
#include "../Headers/Eagle.h"
#include "../Headers/Broomstic.h"


void Racing::init(int switcher, int dist) {
    if (switcher == 1) { Camel C_1(dist); name = C_1.get_name(); time = C_1.get_time(); }
    else if (switcher == 2) { CamelBoost C_2(dist); name = C_2.get_name(); time = C_2.get_time(); }
    else if (switcher == 3) { Centaur C_3(dist); name = C_3.get_name(); time = C_3.get_time(); }
    else if (switcher == 4) { BootsRover C_4(dist); name = C_4.get_name(); time = C_4.get_time(); }
    else if (switcher == 5) { FlyingCapret C_5(dist); name = C_5.get_name(); time = C_5.get_time(); }
    else if (switcher == 6) { Eagle C_6(dist); name = C_6.get_name(); time = C_6.get_time(); }
    else if (switcher == 7) { Broomstic C_7(dist); name = C_7.get_name(); time = C_7.get_time(); }
}
bool Racing::operator>(Racing right) {
    if (time > right.time) { return true; }
    else { return false; }
}
std::ostream& operator<<(std::ostream& left, Racing right) {
    return (left << right.name << ". Время: " << right.time);
}
