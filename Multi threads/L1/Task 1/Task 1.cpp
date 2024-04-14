#include <iostream>
#include <thread>

void foo() {

}

int main()
{
    std::thread t1(foo);
    t1.join();
    //t1.detach();

    return 0;
}