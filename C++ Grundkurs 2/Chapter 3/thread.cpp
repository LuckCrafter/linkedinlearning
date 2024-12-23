#include <iostream>
#include <thread>
#include <mutex>

int main() {

    std::mutex mutex;

    std::thread t1( [&] {
        std::unique_lock lock(mutex);
        std::cout << "1. Lock." << std::endl;
        std::cout << "1. My turn!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "1. Still my turn!" << std::endl;
        std::cout << "1. Release" << std::endl;
    });

    std::thread t2( [&] {
        std::unique_lock lock(mutex);
        std::cout << "2. Lock." << std::endl;
        std::cout << "2. My turn!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "2. Still my turn!" << std::endl;
        std::cout << "2. Release" << std::endl;
    });

    t1.join();
    t2.join();
    return 0;
}