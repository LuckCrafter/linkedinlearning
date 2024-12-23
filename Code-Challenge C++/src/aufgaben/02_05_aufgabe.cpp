#include <string>
#include <iostream>
#include <vector>

template<typename T>
T mittelwertFunktion(std::vector<T> list) {
    T sum {0};
    for (T i : list)
      sum+=i;
    return (sum/list.size());
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

    // todo schrieben Sie eine Funktion die den Mittelwert berechnet und hier zurückgibt
    // Beispiel: int mittelwert_int = mittelwertFunktion(eingabe_int);
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