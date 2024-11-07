#include <string>
#include <iostream>

std::string verschluesseln(std::string eingabe, int schluessel)
{
    std::string resultat("");

    for (char const &zeichen : eingabe)
    {
        int anzahl_buchstaben = char('z') - char('a') + 1; // 26

        if (isalpha(zeichen))
        {
            // um schluessel verschieben
            char verschoben = zeichen + schluessel;

            // Ueberlauf bei Z
            if (isupper(zeichen) && (verschoben > char('Z')))
            {
                verschoben -= anzahl_buchstaben;
            }
            // Unterlauf bei A
            if (isupper(zeichen) && (verschoben < char('A')))
            {
                verschoben += anzahl_buchstaben;
            }

            // Ueberlauf bei z
            if (islower(zeichen) && (verschoben > char('z')))
            {
                verschoben -= anzahl_buchstaben;
            }
            // Unterlauf bei a
            if (islower(zeichen) && (verschoben < char('a')))
            {
                verschoben += anzahl_buchstaben;
            }

            resultat += verschoben;
        }
        else
        {
            resultat += zeichen;
        }
    }
    return resultat;
}

std::string entschluesseln(std::string eingabe, int schluessel)
{

    return verschluesseln(eingabe, -schluessel);
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

    std::string alphabet_test("ABC XYZ - abc xyz");
    std::cout << alphabet_test << std::endl;
    std::cout << verschluesseln(alphabet_test, schluessel) << std::endl;

    return 0;
}