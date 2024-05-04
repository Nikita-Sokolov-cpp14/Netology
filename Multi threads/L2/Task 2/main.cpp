#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <windows.h>

#include "Timer.h"

std::mutex global_mutex;

//3 вариант
void foo_3(short number, int time) {

    std::unique_lock ul(global_mutex);

    auto start = std::chrono::steady_clock::now();
    int moment = time * 1000 / 200;
    int progres = 0;

    consol_parameter::SetColor(7, 0);
    consol_parameter::SetPosition(1, number + 1);
    std::cout << "\n " << number << "\tid = " << std::this_thread::get_id() << "\t";

    ul.unlock();
    try {
        while (progres < 25) {

            std::this_thread::sleep_for(std::chrono::milliseconds(moment));

            ul.lock();
            int trig = rand() / 50;
            if (trig == number) {
                throw std::exception("Случайный выпад");
            }

            consol_parameter::SetColor(7,7);
            consol_parameter::SetPosition(progres + 25, number + 2);
            std::cout << " ";
            
            progres++;
            std::this_thread::sleep_for(std::chrono::milliseconds(moment));
            ul.unlock();
        }
    }
    catch (const std::exception& err) {
        consol_parameter::SetColor(4, 0);
        consol_parameter::SetPosition(53, number + 2);
        std::cout << "ERROR";
        return;
    }

    ul.lock();
    auto end = std::chrono::steady_clock::now();
    consol_parameter::SetColor(7, 0);
    consol_parameter::SetPosition(53, number + 2);
    std::chrono::duration<double> dur = end - start;
    std::cout << "time = " << dur.count();
    ul.unlock();
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N = 1;
    int t = 1;

    std::cout << "Введите число потоков: ";
    std::cin >> N;
    std::cout << "Введите примерное время вычисления в с: ";
    std::cin >> t;

    std::cout << "Поток\tid \t\t progres bar" << std::endl;

    std::vector<std::unique_ptr<std::thread>> trs;

    for (int i = 0; i < N; ++i) {
        trs.emplace_back(std::make_unique<std::thread>(foo_3, i + 1, t));
    }

    for (int i = 0; i < N; ++i) {
        trs[i]->join();
    }

    consol_parameter::SetColor(7, 0);
    consol_parameter::SetPosition(0, N + 3);

    return 0;
}

