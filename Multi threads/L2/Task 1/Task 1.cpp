#include <iostream>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

std::atomic_flag atomic_flag = ATOMIC_FLAG_INIT;
std::atomic<bool> flag = true;
std::atomic<int> counter = 4;

void imitClient() {
    int max_counters = 8;

    while (flag.load()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (counter.load() > max_counters) {
            flag.store(false);
        }
        counter.store(counter.load() + 1);
        std::cout << "Client: " << counter << std::endl;
    }
}

void imitWindow() {
    while (counter.load() > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        counter.store(counter.load() - 1);
        std::cout << "Window: " << counter << std::endl;
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
