#include <vector>
#include <iostream>
#include <ranges>

int main(){
    std::vector<int> list {10,11,12,13,14,15,16,17,18};
    for (const auto& e : list | std::views::filter([](int x) {return (x%2==0);})) //x = e
      std::cout << e << std::endl;
}