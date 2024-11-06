#include <iostream>
#include <vector>

int main() {

    //wie array aber groesse wird in der laufzeit bestimmt (dyn)
    std::vector<int> myRange;
    for (int i {0}; i<18; ++i) {
        myRange.push_back(200);
        std::cout << "The capacity is " << myRange.capacity() << std::endl;
    }
    myRange[10] = 155;
    std::cout << "The size is " << myRange.size() << std::endl;

    for (const auto e : myRange) {
        std::cout << e << std::endl;
    }

    return 0;
}