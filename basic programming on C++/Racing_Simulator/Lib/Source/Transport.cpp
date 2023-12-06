#include "../Headers/Transport.h"


double Transport::get_time() { return full_time; }
void Transport::calc_time() { }
bool Transport::operator>(Transport right) {
    return this->full_time > right.full_time;
}
std::string Transport::get_name() {
    return name;
}
