#include <iostream>

int fibonacci(int n)
{
    // ersten elemente der Folgen 
    // n=0 retourniere 0
    // n=1 retourniere 1
    if (n <= 1) return n;

    // Fn = Fn-1 + Fn-2
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{

    std::cout << "n=5: " << fibonacci(5) << " -- richtiges F5 = 5" << std::endl;
    std::cout << "n=15: " << fibonacci(15) << " -- richtiges F15 = 610" << std::endl;
    return 0;
}