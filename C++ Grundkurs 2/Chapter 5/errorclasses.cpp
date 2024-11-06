#include <iostream>
#include <string>
#include <vector>
#include <exception>

class OutOfMemExeption : public std::exception {
    virtual const char* what() const throw() {
        return "Sorry, your array is too short.";
    }
} outOfMemExeption;

int main(){

    std::vector<std::string> data;

    try {
        data.push_back("Test");
        data.push_back("Test2");

        if(data.size() < 10) throw outOfMemExeption;
        
        std::cout << data.at(10) << std::endl;
        
        data.push_back("Test3");
        data.push_back("Test5");
    } catch(const char *str) {
        std::cerr << str << std::endl;
        data.push_back("Test after exception thrown with str"); 
    } catch(const std::exception &e) {
            std::cerr << e.what() << std::endl;
            data.push_back("Test after exception");
    } catch(...) {
        std::cerr << "Unknown Exception caught!\n";
    }

    for(const auto e : data)
      std::cout << e << std::endl;
    return 0;
}