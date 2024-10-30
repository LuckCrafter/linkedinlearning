#include <iostream>
//#include <thread>
#include <string>
#include <future>

struct Concurrent {
    void test1(const int i, const std::string& str) {
        std::cout << str << ' ' << i << std::endl;
    }
    void test2(const std::string& str) {
        std::cout << str << std::endl;
    }
    int operator()(const int i) {
        std::cout << i << std::endl;
        return i+10;
    }
};

int main() {
    Concurrent conc;
    auto a1 = std::async(&Concurrent::test1, &conc, 42, "Hello");

    auto a2 = std::async(std::launch::deferred, &Concurrent::test2, conc, "world!");

    auto a3 = std::async(std::launch::async, Concurrent(), 43);

    a2.wait();
    std::cout << a3.get() << std::endl;



    return 0;
}