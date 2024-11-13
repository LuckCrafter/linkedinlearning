#include <string>
#include <iostream>
#include <array>

const std::array<std::array<char, 2>, 3> g_symbols {{{'a','z'},{'A','Z'},{'0','9'}}};

bool between(const char c, const char a, const char b) {
    return (a<=c&&c<=b);
}

std::string verschluesseln(std::string eingabe, int schluessel)
{

    std::string resultat(eingabe);
    for (int i {0}; i < resultat.length(); ++i){
        for (auto symbol : g_symbols) {
            if(!between(resultat[i],symbol[0],symbol[1])) continue;

            resultat[i]+=schluessel;
            while(!between(resultat[i],symbol[0],symbol[1]))
              resultat[i] -= (symbol[1]-symbol[0]+1); // add Rotation
            break;
        }
    }
    return resultat;
}

std::string entschluesseln(std::string eingabe, int schluessel)
{
    std::string resultat(eingabe);
    for (int i {0}; i < resultat.length(); ++i) {
        for (auto symbol : g_symbols) {
            if(!between(resultat[i],symbol[0],symbol[1])) continue;
            
            resultat[i]-=schluessel;
            while(!between(resultat[i],symbol[0],symbol[1]))
              resultat[i] += (symbol[1]-symbol[0]+1); // add Rotation
            break;
        }
    }
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