#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <windows.h>

//#pragma execution_character_set("utf-8")

using namespace std::chrono;

void sum(std::vector<int>& s, std::vector<int>& a, std::vector<int>& b, long i_start, long size) {
    for (long i = i_start; i < i_start + size; ++i) {
        s[i] = a[i] + b[i];
    }

}

void sum_p2(std::vector<int>& s, std::vector<int>& a, std::vector<int>& b) {
    long mid = a.size() / 2;
    std::thread t1(sum, std::ref(s), std::ref(a), std::ref(b), 0, mid);
    std::thread t2(sum, std::ref(s), std::ref(a), std::ref(b), mid, a.size() - mid);

    t1.join();
    t2.join();
}

void sum_p4(std::vector<int>& s, std::vector<int>& a, std::vector<int>& b) {
    long size = a.size() / 4;
    long pos1 = 0;
    long pos2 = size;
    long pos3 = size * 2;
    long pos4 = size * 3;

    std::thread t1(sum, std::ref(s), std::ref(a), std::ref(b), pos1, size);
    std::thread t2(sum, std::ref(s), std::ref(a), std::ref(b), pos2, size);
    std::thread t3(sum, std::ref(s), std::ref(a), std::ref(b), pos3, size);
    std::thread t4(sum, std::ref(s), std::ref(a), std::ref(b), pos4, a.size() - 3 * size);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

void sum_p8(std::vector<int>& s, std::vector<int>& a, std::vector<int>& b) {
    long size = a.size() / 8;

    std::thread t1(sum, std::ref(s), std::ref(a), std::ref(b), 0, size);
    std::thread t2(sum, std::ref(s), std::ref(a), std::ref(b), size, size);
    std::thread t3(sum, std::ref(s), std::ref(a), std::ref(b), size * 2, size);
    std::thread t4(sum, std::ref(s), std::ref(a), std::ref(b), size * 3, size);
    std::thread t5(sum, std::ref(s), std::ref(a), std::ref(b), size * 4, size);
    std::thread t6(sum, std::ref(s), std::ref(a), std::ref(b), size * 5, size);
    std::thread t7(sum, std::ref(s), std::ref(a), std::ref(b), size * 6, size);
    std::thread t8(sum, std::ref(s), std::ref(a), std::ref(b), size * 7, a.size() - 7 * size);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
}

void sum_p16(std::vector<int>& s, std::vector<int>& a, std::vector<int>& b) {
    long size = a.size() / 16;

    std::thread t1(sum, std::ref(s), std::ref(a), std::ref(b), 0, size);
    std::thread t2(sum, std::ref(s), std::ref(a), std::ref(b), size, size);
    std::thread t3(sum, std::ref(s), std::ref(a), std::ref(b), size * 2, size);
    std::thread t4(sum, std::ref(s), std::ref(a), std::ref(b), size * 3, size);
    std::thread t5(sum, std::ref(s), std::ref(a), std::ref(b), size * 4, size);
    std::thread t6(sum, std::ref(s), std::ref(a), std::ref(b), size * 5, size);
    std::thread t7(sum, std::ref(s), std::ref(a), std::ref(b), size * 6, size);
    std::thread t8(sum, std::ref(s), std::ref(a), std::ref(b), size * 7, size);
    std::thread t9(sum, std::ref(s), std::ref(a), std::ref(b), size * 8, size);
    std::thread t10(sum, std::ref(s), std::ref(a), std::ref(b), size * 9, size);
    std::thread t11(sum, std::ref(s), std::ref(a), std::ref(b), size * 10, size);
    std::thread t12(sum, std::ref(s), std::ref(a), std::ref(b), size * 11, size);
    std::thread t13(sum, std::ref(s), std::ref(a), std::ref(b), size * 12, size);
    std::thread t14(sum, std::ref(s), std::ref(a), std::ref(b), size * 13, size);
    std::thread t15(sum, std::ref(s), std::ref(a), std::ref(b), size * 14, size);
    std::thread t16(sum, std::ref(s), std::ref(a), std::ref(b), size * 15, a.size() - 15 * size);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    t15.join();
    t16.join();
}

std::map<int, std::chrono::duration<double>> calc_time(std::vector<int>& s, std::vector<int>& a, std::vector<int>& b) {
    std::map<int, std::chrono::duration<double>> times;

    auto start = std::chrono::steady_clock::now();
    sum(s, a, b, 0, a.size());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur_1 = end - start;

    start = std::chrono::steady_clock::now();
    sum_p2(s, a, b);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur_2 = end - start;

    start = std::chrono::steady_clock::now();
    sum_p4(s, a, b);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur_4 = end - start;

    start = std::chrono::steady_clock::now();
    sum_p8(s, a, b);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur_8 = end - start;

    start = std::chrono::steady_clock::now();
    sum_p16(s, a, b);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur_16 = end - start;

    times[1] = dur_1;
    times[2] = dur_2;
    times[4] = dur_4;
    times[8] = dur_8;
    times[16] = dur_16;

    return times;
}

int main() {

    setlocale(LC_ALL, "Russian");
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    //setvbuf(stdout, nullptr, _IOFBF, 1000);


    std::vector<int> a_1e3(1000);
    std::vector<int> b_1e3(1000);
    std::vector<int> s_1e3(1000);
    for (int i = 0; i < 1000; i++) {
        a_1e3[i] = i;
        b_1e3[i] = i;
    }

    std::vector<int> a_1e4(10000);
    std::vector<int> b_1e4(10000);
    std::vector<int> s_1e4(10000);
    for (int i = 0; i < 10000; i++) {
        a_1e4[i] = i / 3;
        b_1e4[i] = i / 3;
    }

    std::vector<int> a_1e5(100000);
    std::vector<int> b_1e5(100000);
    std::vector<int> s_1e5(100000);
    for (int i = 0; i < 100000; i++) {
        a_1e5[i] = i / 30;
        b_1e5[i] = i / 30;
    }
    std::vector<int> a_1e6(1000000);
    std::vector<int> b_1e6(1000000);
    std::vector<int> s_1e6(1000000);
    for (int i = 0; i < 1000000; i++) {
        a_1e6[i] = i / 3;
        b_1e6[i] = i / 3;
    }

    std::map<int, std::chrono::duration<double>> times_1e3 = calc_time(s_1e3, a_1e3, b_1e3);
    std::map<int, std::chrono::duration<double>> times_1e4 = calc_time(s_1e4, a_1e4, b_1e4);
    std::map<int, std::chrono::duration<double>> times_1e5 = calc_time(s_1e5, a_1e5, b_1e5);
    std::map<int, std::chrono::duration<double>> times_1e6 = calc_time(s_1e6, a_1e6, b_1e6);

    std::cout << "Аппаратное число процессов: " << std::thread::hardware_concurrency() << std::endl;

    std::cout << "\t\t 1000 \t\t 10000 \t\t 100000 \t 1000000" << std::endl;
    std::cout << "1 поток\t\t" << times_1e3[1].count() << "s\t" << times_1e4[1].count() << "s\t";
    std::cout << times_1e5[1].count() << "s\t" << times_1e6[1].count() << "s" << std::endl;

    std::cout << "2 потока\t" << times_1e3[2].count() << "s\t" << times_1e4[2].count() << "s\t";
    std::cout << times_1e5[2].count() << "s\t" << times_1e6[2].count() << "s\t" << std::endl;

    std::cout << "4 потока\t" << times_1e3[4].count() << "s\t" << times_1e4[4].count() << "s\t";
    std::cout << times_1e5[4].count() << "s\t" << times_1e6[4].count() << "s\t" << std::endl;

    std::cout << "8 потоков\t" << times_1e3[8].count() << "s\t" << times_1e4[8].count() << "s\t";
    std::cout << times_1e5[8].count() << "s\t" << times_1e6[8].count() << "s\t" << std::endl;

    std::cout << "16 потоков\t" << times_1e3[16].count() << "s\t" << times_1e4[16].count() << "s\t";
    std::cout << times_1e5[16].count() << "s\t" << times_1e6[16].count() << "s\t" << std::endl;

    return 0;
}