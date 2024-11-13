#include <iostream>
#include <array>
#include <vector>
//#include <list>
#include <span>

/* C++20 */

void printC(std::span<int> container) {
    for(const auto& e : container)
        std::cout << e << " ";
    std::cout << std::endl;
    return;
}

int main(){
    int arr1 [] {1,2,3,4,5,6,7,8};
    std::array<int, 8> arr2 {1,2,3,4,5,6,7,8};
    std::vector<int> arr3 {1,2,3,4,5,6,7,8};
    //std::list<int> arr4 {1,2,3,4,5,6,7,8};

    printC(arr1);
    printC(arr2);
    printC(arr3);
    //printC(arr4); // list dont work

    return 0;
}