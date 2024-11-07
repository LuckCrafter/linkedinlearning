#include <iostream>
#include <vector>

int berechneVolumen(std::vector<int> eingabe)
{
    // todo berechne Volumen
    return 0;
}

int main()
{
    std::vector<int> eingabe_1{8, 3, 7, 9, 3, 2, 5, 7, 2, 3, 4};       // erwarteter output 49
    std::vector<int> eingabe_2{1, 1};                                  // erwarteter output 1
    std::vector<int> eingabe_3{8, 6, 2, 5, 4, 8, 3, 7, 9, 3, 2, 5, 7}; // erwarteter output 84

    std::cout << "Max Volumen eingabe 1 " << berechneVolumen(eingabe_1) << std::endl;
    std::cout << "Max Volumen eingabe 2 " << berechneVolumen(eingabe_2) << std::endl;
    std::cout << "Max Volumen eingabe 3 " << berechneVolumen(eingabe_3) << std::endl;

    return 0;
}