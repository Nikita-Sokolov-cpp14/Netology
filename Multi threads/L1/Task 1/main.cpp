#include <iostream>
#include <thread>

bool flag = true;
int max_counters = 8;
int counter = 4;

void imitClient() {
    while (flag) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (counter > max_counters) {
            flag = 0;
        }
        counter++;
    }
}

void imitWindow() {
    while (counter > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        counter--;
        std::cout << counter << std::endl;
    }
}

int main() {
    auto start = std::chrono::steady_clock::now();

    std::chrono::duration<double> dur;

    std::thread t1(imitClient);
    std::thread t2(imitWindow);

    t1.join();
    t2.join();

    auto end = std::chrono::steady_clock::now();
    dur = end - start;
    std::cout << dur.count() << std::endl;

    std::cout << "counter = " << counter << std::endl;

    return 0;
}