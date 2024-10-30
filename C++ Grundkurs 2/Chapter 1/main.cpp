#include <iostream>
#include <fmt/core.h>

template <typename T>
T add (const T a, const T b) {
    return a + b;
}

int main() {
    {
    const std::string a {"Hello "};
    const std::string b {"World"};
    std::string msg = add(a, b);
    fmt::print("{}\n",msg);
    }
    {
    auto msg = add(7, 12);
    fmt::print("{}\n",msg);
    }
    {
    auto msg = add(2.3, 3.2);
    fmt::print("{}\n",msg);
    }
}