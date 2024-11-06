#include <iostream>
#include <map>
#include <unordered_map>
#include <cmath>
#include <chrono>

template <typename T>
void buildPotTable(T &cont) {
    for (int i {0}; i<10; i++) cont[std::pow(10,i)]=i;
}

int main() {
    std::map<int,int> potTenTable;
    std::unordered_map<int,int> unordered_potTenTable;

    std::chrono::duration<double, std::milli> durationOrdered_ms;
    std::chrono::duration<double, std::milli> durationUnordered_ms;

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        buildPotTable(potTenTable);
        auto t2 = std::chrono::high_resolution_clock::now();
        durationOrdered_ms = t2 - t1;
    }

    {
        auto t1 = std::chrono::high_resolution_clock::now();
        buildPotTable(unordered_potTenTable);
        auto t2 = std::chrono::high_resolution_clock::now();
        durationUnordered_ms = t2 - t1;
    }

    std::cout << "Ordered Variant:\nTime for insertion (ms): " << durationOrdered_ms.count() << std::endl;
    for(const auto &e : potTenTable) std::cout << "potTenTable[" << e.first << "] = " << e.second << "\n";

    std::cout << "\nUnrdered Variant:\nTime for insertion (ms): " << durationUnordered_ms.count() << std::endl;
    for(const auto &e : unordered_potTenTable) std::cout << "unordered_potTenTable[" << e.first << "] = " << e.second << "\n";
    
}