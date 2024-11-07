#include <iostream>

double exponentFunktionForLoop(int basis, int exponent)
{
    double result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= basis;
    }
    return result;
}

double exponentFunktionRekursion(int basis, int exponent)
{
    // Abbruch wenn Sie alle Exponenten haben
    if (exponent == 0)
        return 1.0;

    // Rekursion fuer halbe exponenten
    double resultat_halber_exp = exponentFunktionRekursion(basis, static_cast<int>(exponent / 2));

    // Exponent ist gerade
    if (exponent % 2 == 0)
        return resultat_halber_exp * resultat_halber_exp;
    else
        return basis * resultat_halber_exp * resultat_halber_exp;
}

double exponentFunktion(int basis, int exponent)
{
    double result = 1;

    while (true)
    {
        // Wenn ungerade: multipliziere mit Basis
        if (exponent & 1)
            result *= basis;

        // Dividiere Exponent durch 2
        exponent >>= 1;

        // exponent 0 ist, sind Sie fertig
        if (!exponent)
            break;

        // naechste Basis
        basis *= basis;
    }
    return result;
}

int main()
{
    std::cout << "For Loop " << std::endl;
    std::cout << "5^8: " << exponentFunktionForLoop(5, 8) << " -- richtiges Ergebnis 390625" << std::endl;
    std::cout << "9^3: " << exponentFunktionForLoop(9, 3) << " -- richtiges Ergebnis 729" << std::endl;

    std::cout << "Rekursion " << std::endl;
    std::cout << "5^8: " << exponentFunktionRekursion(5, 8) << " -- richtiges Ergebnis 390625" << std::endl;
    std::cout << "9^3: " << exponentFunktionRekursion(9, 3) << " -- richtiges Ergebnis 729" << std::endl;

    std::cout << "Bitshift " << std::endl;
    std::cout << "5^8: " << exponentFunktion(5, 8) << " -- richtiges Ergebnis 390625" << std::endl;
    std::cout << "9^3: " << exponentFunktion(9, 3) << " -- richtiges Ergebnis 729" << std::endl;
    return 0;
}