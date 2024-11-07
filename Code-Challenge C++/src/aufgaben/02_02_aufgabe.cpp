#include <iostream>
#include <vector>

int main()
{
    std::vector<int> eingabe{5, 34, 2, 8, 6, 2};

    std::cout << "Ausgabe der Produkte " << std::endl;

    for (int i {0}; i<eingabe.size();++i) {
        int produkt{1};
        for (int j{0};j<eingabe.size();++j) {
            if(j==i) continue;
            produkt*=eingabe[j];
        }
        std::cout << i << ": " << produkt << std::endl;
    }

    return 0;
}