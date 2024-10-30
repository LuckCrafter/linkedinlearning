#include <iostream>
//#include <fmt/core.h>

template <typename T>
T add (const T a, const T b) {
    return a + b;
}

/* With multiple types*/
template <typename T1, typename T2>
void print(T1 a, T2 b){
    std::cout << a << ", " << b << std::endl;
}

/* Dynamic size of types */

void print2() {}

template <typename TYPE, typename... Args>
void print2(TYPE var, Args... args) {
    std::cout << var;
    print2(args...);
}


int main() {
    {
    const std::string a {"Hello "};
    const std::string b {"World"};
    std::string msg = add(a, b);
    //fmt::print("{}\n",msg);
    printf("%s\n",msg);
    }
    {
    auto msg = add(7, 12);
    //fmt::print("{}\n",msg);
    printf("%i\n",msg);
    }
    {
    auto msg = add(2.3, 3.2);
    //fmt::print("{}\n",msg);
    printf("%f\n",msg);
    }

    print(1, 1.2);
    print("hello", 7);
    print(-12, 'c');

    print2("Hi, ", 1, " is a int an not a float like ", 1.2f,"\n");
    print2("Hello World!", "\n");
    print2("Hello Number, ", 1.0,"\n");

    return 0;
}