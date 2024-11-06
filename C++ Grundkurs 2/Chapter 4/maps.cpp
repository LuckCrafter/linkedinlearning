#include <iostream>
#include <map>
#include <cmath>

// Maps statt arrays
  // Key : Value statt Index : Value

int main() {
    std::map<int, int>potTenTable;

    for (int i {0}; i<10; ++i) {
        potTenTable[std::pow(10,i)]=i;
    }

    std::cout << "Size: " << potTenTable.size() << std::endl;
    std::cout << "potTenTable[20] is " << potTenTable[20] << std::endl;
    std::cout << "Size: " << potTenTable.size() << std::endl;
    if (potTenTable.find(30) == potTenTable.end()) std::cout << "There is no value for the key 30\n";

    for (const auto e : potTenTable) {
        auto key = e.first;
        std::cout << "potTenTable[" << key << "] = " << e.second << std::endl; 
    }
}