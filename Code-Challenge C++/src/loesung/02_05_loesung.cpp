#include <string>
#include <iostream>
#include <vector>

template <typename T>
T mittelwertFunktion(std::vector<T> eingabe)
{
    T sum = 0;
    for (auto element : eingabe)
        sum += element;

    T mittelwert = static_cast<T>(sum / eingabe.size());
    return mittelwert;
}

int main()
{
    std::vector<int> eingabe_int;
    std::vector<uint> eingabe_uint;
    std::vector<float> eingabe_float;
    std::vector<double> eingabe_double;

    // befuellen der Eingabe Vektoren
    for (int i = 0; i < 30; i++)
    {
        eingabe_int.push_back(i);
        eingabe_uint.push_back(static_cast<uint>(i));
        eingabe_float.push_back(static_cast<float>(i));
        eingabe_double.push_back(static_cast<double>(i));
    }

    int mittelwert_int = mittelwertFunktion(eingabe_int);
    uint mittelwert_uint = mittelwertFunktion(eingabe_uint);
    float mittelwert_float = mittelwertFunktion(eingabe_float);
    double mittelwert_double = mittelwertFunktion(eingabe_double);

    std::cout << "Mittelwert int:    " << mittelwert_int << std::endl;
    std::cout << "Mittelwert uint:   " << mittelwert_uint << std::endl;
    std::cout << "Mittelwert float:  " << mittelwert_float << std::endl;
    std::cout << "Mittelwert double: " << mittelwert_double << std::endl;

    return 0;
}