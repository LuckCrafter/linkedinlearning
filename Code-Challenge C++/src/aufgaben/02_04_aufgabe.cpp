#include <string>
#include <iostream>

std::string verschluesseln(std::string eingabe, int schluessel)
{
    std::string resultat("leer");
    return resultat;
}

std::string entschluesseln(std::string eingabe, int schluessel)
{
    std::string resultat("leer");
    return resultat;
}

int main()
{
    std::string eingabe("Koennen Sie diese Aufgabe loesen?");

    int schluessel = 3;
    std::string verschluesselte_eingabe = verschluesseln(eingabe, schluessel);
    std::string entluesselte_eingabe = entschluesseln(verschluesselte_eingabe, schluessel);

    std::cout << "Eingabe:                 " << eingabe << std::endl;
    std::cout << "Verschluesselte Eingabe: " << verschluesselte_eingabe << std::endl;
    std::cout << "Entschluesselte Eingabe: " << entluesselte_eingabe << std::endl;

    return 0;
}