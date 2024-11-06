#include <iostream>
#include <string>
#include <vector>
#include <exception>

int main(){

    std::vector<std::string> data;

    try {
        data.push_back("Test");
        data.push_back("Test2");
        std::cout << data.at(10) << std::endl;
        data.push_back("Test3");
        data.push_back("Test5");
    } catch(const std::exception &e) {
            std::cout << e.what() << std::endl;
            data.push_back("Test after exception");
    } catch(...) {
        std::cout << "Unknown Exception caught!\n";
    }

    for(const auto e : data)
      std::cout << e << std::endl;
    return 0;
}