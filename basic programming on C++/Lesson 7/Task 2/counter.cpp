#include "counter.h"

void Counter::set_count(int count) { this->count = count; }
Counter::Counter() { count = 1; }
void Counter::step(char comand) {
    switch (comand) {
    case '+': count++; break;
    case '-': count--; break;
    case '=': std::cout << count << std::endl; break;
    case 'x': std::cout << "�� �������!"; break;
    default: std::cout << "������!\n";
    }
}

