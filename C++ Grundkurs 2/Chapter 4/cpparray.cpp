#include <iostream>
#include <array>

int main() {
    std::array<int, 16> myRange;

    myRange.fill(200);
    std::cout << "The size is " << myRange.size() << std::endl;
    myRange[10] = 155;

    for(auto e = myRange.begin() ; e != myRange.end() ; e++) {
        std::cout << *e << std::endl;
    }

    return 0;
}