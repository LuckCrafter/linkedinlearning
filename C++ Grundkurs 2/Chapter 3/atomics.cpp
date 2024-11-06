#include <thread>
#include <iostream>
#include <atomic>

int main() {
    std::atomic<int> c {0};
    std::thread t1([&] {
        for (int i {0};i<1000000;i++) c++;
    });

    std::thread t2([&] {
        for (int i {0};i<1000000;i++) c++;
    });

    t1.join();
    t2.join();

    std::cout << c<< std::endl;
    return 0;
}