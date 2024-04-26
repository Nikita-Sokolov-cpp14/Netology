#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

#include <iostream>
#include <windows.h> // Для работы с функциями управления цветом консоли
using namespace std;

std::mutex glm;

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void updateProgressBar(int progress) {
    int barWidth = 70;

    float fraction = static_cast<float>(progress) / 100;
    int pos = static_cast<int>(barWidth * fraction);

    setConsoleColor(7); // Зеленый цвет текста
    cout << "[";
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) cout << "=";
        else cout << " ";
    }
    cout << "] " << int(fraction * 100.0) << "%\r";
    cout.flush();
}

void foo(int number, int time, int& progres) {
    //glm.lock();
    //std::unique_lock<std::mutex> mlg(glm);
    //std::lock_guard mlg(glm);
    //glm.lock();


    long moment = time * 10;
    std::cout << "\t[";

    for (int i = 0; i < 100; ++i) {
        std::cout << '=';
        std::this_thread::sleep_for(std::chrono::milliseconds(moment));
        progres++;
    }

}

int main() {

    /*
    for (int i = 0; i <= 100; i++) {
        updateProgressBar(i);
        Sleep(100); // Для демонстрационных целей - пауза
    }
    setConsoleColor(7); // Возвращаем белый цвет текста
    cout << endl;
    */
    
    
    int N = 5;
    std::vector<std::unique_ptr<std::thread>> trs;
    std::vector<int> progres(N);

    for (int i = 0; i < N; ++i) {
        progres[i] = 0;
        trs.emplace_back(std::make_unique<std::thread>(foo, i + 1, 2, std::ref(progres[i])));
    }

    std::cout << "1234__" << std::endl;

    for (int i = 0; i < N; ++i) {
        trs[i]->join();
    }


    return 0;
}

