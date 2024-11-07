#include <iostream>

double exponentFunktion(const int basis, const int exponent)
{
    if (basis==0&&exponent<0) return 0;
    bool posExp {(exponent>=0)};
    int ex = (posExp) ? exponent : -exponent;
    // Implementieren Sie hier die exponentialfunktion
    double result=1;
    for(int i {0};i< ex;++i)
      result*=basis;
    return (posExp) ? result : 1/result;
}

int main()
{
    std::cout << "5^8: " << exponentFunktion(5, 8) << " -- richtiges Ergebnis 390625" << std::endl;
    std::cout << "9^3: " << exponentFunktion(9, 3) << " -- richtiges Ergebnis 729" << std::endl;
    return 0;
}