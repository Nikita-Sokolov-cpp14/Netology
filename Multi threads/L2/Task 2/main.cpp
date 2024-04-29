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

    int moment = static_cast<int>(time * 1000 / 50);

    goToXY(1, number + 1);
    std::cout << "\n " << number << "\tid = " << std::this_thread::get_id() << "\t[";

    ul.unlock();

    try {
        for (short progres = 0; progres < 50; ++progres) {
            std::this_thread::sleep_for(std::chrono::milliseconds(moment));

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

void foo_2(short number, int time, int progres) {
    std::unique_lock ul(global_mutex);

    auto start = std::chrono::steady_clock::now();
    int moment = time;

    goToXY(1, number + 1);
    std::cout << "\n " << number << "\tid = " << std::this_thread::get_id() << "\t[";
    ul.unlock();

    try {
        while (progres < 400) {
         
            ul.lock();
            int trig = rand() / 100;
            if (trig == number) {
                throw std::exception("Случайный выпад");
            }
            ul.unlock();
            
            if (progres / 8 < 49) {
                ul.lock();
                goToXY(progres / 8 + 25, number + 2);
                ul.unlock();
                std::cout << "=";
            }
            progres++;

            std::this_thread::sleep_for(std::chrono::milliseconds(moment));
        }
    }
    catch (const std::exception& err) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2 * moment));
        goToXY(78, number + 2);
        std::cout << "ERROR";
        return;
    }

    ul.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(2 * moment));
    goToXY(76, number + 2);
    std::cout << ">";

    auto end = std::chrono::steady_clock::now();
    goToXY(78, number + 2);
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
    std::cout << "Введите время вычисления: ";
    std::cin >> t;

    std::cout << "Поток\tid \t\t progres bar" << std::endl;

    std::vector<std::unique_ptr<std::thread>> trs;
    std::vector<short> progres(N);

    for (int i = 0; i < N; ++i) {
        progres[i] = 0;
    }

    for (int i = 0; i < N; ++i) {

        trs.emplace_back(std::make_unique<std::thread>(
            foo_2, i + 1, t, std::ref(progres[i])));
        //trs.emplace_back(std::make_unique<std::thread>(foo, i + 1, t));
    }

    for (int i = 0; i < N; ++i) {
        trs[i]->join();
    }

    goToXY(0, N + 3);

    return 0;
}

