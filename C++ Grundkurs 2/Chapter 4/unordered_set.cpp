#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <chrono>

template <typename T>
void addMyNames(T &cont) {
    cont.insert("John");
    cont.insert("Steve");
    cont.insert("Alan");
    cont.insert("Josh");
    cont.insert("Josh");
    cont.insert("Jeff");
    cont.insert("Jeff");
    cont.insert("Bryan");
}

int main() {
    std::set<std::string> names;
    std::unordered_set<std::string> unordered_names;

    std::chrono::duration<double, std::milli> durationOrdered_ms;
    std::chrono::duration<double, std::milli> durationUnordered_ms;

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        addMyNames(names);
        auto t2 = std::chrono::high_resolution_clock::now();
        durationOrdered_ms = t2 - t1;
    }

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        addMyNames(unordered_names);
        auto t2 = std::chrono::high_resolution_clock::now();
        durationUnordered_ms = t2 - t1;
    }

    std::cout << "Ordered Variant:\nTime for insertion (ms): " << durationOrdered_ms.count() << std::endl;
    for(const auto &e : names) std::cout << e << "\n";

    std::cout << "\nUnrdered Variant:\nTime for insertion (ms): " << durationUnordered_ms.count() << std::endl;
    for(const auto &e : unordered_names) std::cout << e << "\n";
    
}