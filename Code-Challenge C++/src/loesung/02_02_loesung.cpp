#include <iostream>
#include <vector>

int main()
{
    std::vector<double> eingabe{5, 34, 2, 8, 6, 2};

    std::cout << "Ausgabe der Produkte " << std::endl;

    // Doppelte for-loop -- schlechte Laufzeit
    std::cout << "Ausgabe: " << std::endl;
    for (int i = 0; i < eingabe.size(); i++)
    {
        double produkt = 1;
        for (int j = 0; j < eingabe.size(); j++)
        {
            if (j != i)
                produkt *= eingabe[j];
        }
        std::cout << "produkt[" << i << "]: " << produkt << std::endl;
    }
    std::cout << std::endl;

    // Schnellere Berechnung mit Trick
    std::vector<double> vorherige_produkte(eingabe.size(), 0.0);
    vorherige_produkte[0] = eingabe[0];
    for (int i = 1; i < eingabe.size(); i++)
    {
        vorherige_produkte[i] = vorherige_produkte[i - 1] * eingabe[i];
    }

    std::vector<double> nachfolgende_produkte(eingabe.size(), 0.0);
    nachfolgende_produkte[eingabe.size() - 1] = eingabe[eingabe.size() - 1];
    for (int i = eingabe.size() - 2; i >= 0; i--)
    {
        nachfolgende_produkte[i] = nachfolgende_produkte[i + 1] * eingabe[i];
    }

    std::cout << "Ausgabe 2: " << std::endl;
    for (int i = 0; i < eingabe.size(); i++)
    {
        double resultat;
        if (i == 0)
            resultat = nachfolgende_produkte[1];
        else if (i == eingabe.size() - 1)
            resultat = vorherige_produkte[eingabe.size() - 2];
        else
            resultat = vorherige_produkte[i - 1] * nachfolgende_produkte[i + 1];

        std::cout << "produkt[" << i << "]: " << resultat << std::endl;
    }

    return 0;
}