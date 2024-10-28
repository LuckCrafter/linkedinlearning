#include <iostream>
#include <ctime>
#include <string>

/*      Kapitiel 5      */

/*
Challenge Schere-Stein-Papier:
Der bzw. die User:in spielt gegen den Computer Schere-Stein-Papier.
Der bzw. die User:in gibt die Auswahl 1 (Schere), 2 (Stein) oder 3 (Papier) ein.
Der Computer wählt zufällig Schere, Stein oder Papier aus.
Das Programm laeuft wie folgt ab:
  Der Spieler hat <X> ausgewaehlt.
  Der Computer hat <Y> ausgewaehlt.
  Es gewinnt <Computer, Spieler, Niemand>.
*/
void schereSteinPapier() {
    int x {0};
    std::string winner {"Niemand"};
    
    do {
        std::cout << "Waehle (1) Schere, (2) Stein, (3) Papier aus: ";
        std::cin >> x;
    } while (x<1||3<x);
    std::srand(std::time(0)); // time specific randomizer
    int y {(rand()%3)+1};
    printf("Der Spieler hat %i ausgewaehlt.\n",x);
    printf("Der Computer hat %i ausgewaehlt.\n",y);
    
    if (x==y) {printf("Es gewinnt Niemand.\n");}
    if (x-y==1||x-y==(-2)) {printf("Es gewinnt der Spieler.\n");}
    if (x-y==(-1)||x-y==2) {printf("Es gewinnt der Computer.\n");}
    return;
}

int main(){
    return 0;
}