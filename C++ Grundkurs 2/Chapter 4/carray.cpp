#include <iostream>


int main() {
    int myRange[16];
    std::cout << "The size is " << 16 << std::endl;
    for (int i {0};i<16;++i) {
        myRange[i]=200;
    }
    myRange[10] = 155;
    for (auto e : myRange) std::cout << e << std::endl;
    return 0;
}