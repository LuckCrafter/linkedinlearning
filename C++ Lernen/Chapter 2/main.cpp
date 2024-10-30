#include <iostream>
#include <fmt/core.h>

int main() {
    auto msg = "\"Hello World!\"";
    printf("std::printf\t%s\n",msg);
    std::cout << "std::cout\t" << msg << std::endl;
    fmt::print("fmt::print\t{}\n", msg);
    return 0;
}