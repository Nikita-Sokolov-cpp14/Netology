#include <iostream>
#include <thread>

using namespace std::chrono;

void imitClient(int& counter) {
    counter++;
}

void imitWindow(int& counter) {
    counter--;
}

int main() {
    auto start = std::chrono::steady_clock::now();

    int counter = 4;
    int max_counters = 8;
    bool flag = true;
    int i = 0;

    std::chrono::duration<double> dur;

    while (counter > 0) {

        std::this_thread::sleep_for(1s);
        i++;

        if (flag) {
            std::thread t1(imitClient, std::ref(counter));
            t1.join();

            if (counter > max_counters) {
                flag = 0;
            }
        }

        if (i % 2 == 0) {
            std::thread t2(imitWindow, std::ref(counter));
            t2.join();
        }

        std::cout << "counter = " << counter << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    dur = end - start;
    std::cout << dur.count() << std::endl;

    std::cout << "counter = " << counter << std::endl;
    return 0;
}