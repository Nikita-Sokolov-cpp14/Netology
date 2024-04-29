#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <windows.h>

std::mutex global_mutex;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void goToXY(short x, short y) {
    SetConsoleCursorPosition(hConsole, { x, y });
}

void foo(short number, float time) {

    auto start = std::chrono::steady_clock::now();

    std::unique_lock ul(global_mutex);

    int moment = static_cast<int>(time * 1000);

    goToXY(1, number + 1);
    std::cout << "\n " << number << "\tid = " << std::this_thread::get_id() << "\t[";

    ul.unlock();

    try {
        for (short progres = 0; progres < 50; ++progres) {

            std::this_thread::sleep_for(std::chrono::milliseconds(moment));

            SetConsoleTextAttribute(hConsole, 7);

            int trig = rand() / 300;
            if (trig == number) {
                throw std::exception("Случайный выпад");
            }

            ul.lock();
            goToXY(progres + 25, number + 2);
            if (progres != 49) {
                std::cout << "=";
            }     
            else {
                std::cout << ">";
            }
            ul.unlock();
        }
    }
    catch (const std::exception& err) {
        //SetConsoleTextAttribute(hConsole, 31);
        ul.lock();
        goToXY(80, number + 2);
        std::cout << "ERROR";
        ul.unlock();
        return;
    }
    ul.lock();
    auto end = std::chrono::steady_clock::now();
    goToXY(80, number + 2);
    std::chrono::duration<double> dur = end - start;
    std::cout << "time = " << dur.count();
    ul.unlock();
}

int main() {

    setlocale(LC_ALL, "Russian");

    int N = 1;
    float t = 0.02;

    std::cout << "Введите число потоков: ";
    std::cin >> N;
    std::cout << "Введите время вычисления: ";
    std::cin >> t;

    std::cout << "Поток\tid \t\t progres bar" << std::endl;

    std::vector<std::unique_ptr<std::thread>> trs;
    std::vector<short> progres(N);

    for (int i = 0; i < N; ++i) {

        trs.emplace_back(std::make_unique<std::thread>(foo, i + 1, t));
    }

    for (int i = 0; i < N; ++i) {
        trs[i]->join();
    }

    SetConsoleTextAttribute(hConsole, 7);
    goToXY(0, N + 3);
    return 0;
}

