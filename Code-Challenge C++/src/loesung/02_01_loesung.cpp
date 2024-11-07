#include <iostream>
#include <vector>

int berechneVolumenDoppelteFor(std::vector<int> eingabe){
    int max_volumen = 0;

    for (int i = 0; i < eingabe.size(); i++){
        for (int j = 0; j < eingabe.size(); j++){
            int laenge = std::abs(i - j);
            int hoehe = std::min(eingabe[i], eingabe[j]);
            max_volumen = std::max(max_volumen, laenge * hoehe);
        }
    }

    return max_volumen;
}

int berechneVolumen(std::vector<int> eingabe)
{

    int index_links = 0;
    int index_rechts = eingabe.size() - 1;

    int max_volumen = 0;

    // verschiebe indices solange sie sich nicht ueberschneiden
    while (index_links < index_rechts)
    {
        int laenge = index_rechts - index_links;
        int hoehe = std::min(eingabe[index_links], eingabe[index_rechts]);
        max_volumen = std::max(max_volumen, laenge * hoehe);

        // iteriere bei niedrigerer Hoehe weiter
        if (eingabe[index_links] < eingabe[index_rechts])
            index_links++;
        else
            index_rechts--;
    }

    return max_volumen;
}

int main()
{
    std::vector<int> eingabe_1{8, 3, 7, 9, 3, 2, 5, 7, 2, 3, 4};       // erwarteter output 49
    std::vector<int> eingabe_2{1, 1};                                  // erwarteter output 1
    std::vector<int> eingabe_3{8, 6, 2, 5, 4, 8, 3, 7, 9, 3, 2, 5, 7}; // erwarteter output 84

    std::cout << "Doppelte For eingabe 1 " << berechneVolumenDoppelteFor(eingabe_1) << std::endl;
    std::cout << "Doppelte For eingabe 2 " << berechneVolumenDoppelteFor(eingabe_2) << std::endl;
    std::cout << "Doppelte For eingabe 3 " << berechneVolumenDoppelteFor(eingabe_3) << std::endl;
    

    std::cout << " Max Volumen eingabe 1 " << berechneVolumen(eingabe_1) << std::endl;
    std::cout << " Max Volumen eingabe 2 " << berechneVolumen(eingabe_2) << std::endl;
    std::cout << " Max Volumen eingabe 3 " << berechneVolumen(eingabe_3) << std::endl;

    return 0;
}