#include <iostream>
#include <ctime>
#include <string>

/*      Kapitel 3       */

/*
Challange 1:
1. Legen Sie ein Array mit 5 Werten fest.
2. Weisen Sie jedem Wert im Array den 3-fachen Wert des Index zu.
3. Geben Sie die Anzahl der Werte aus, die größer gleich 6 sind.
*/
void kapitel3() {
    int myArray[5];
    for(int i=0;i<5;++i) {
        myArray[i]=i*3;
    }
    int counter {0};
    for(auto e : myArray) {
        if (e>=6) ++counter;
    }
    std::cout << counter;
}


/*      Kapitiel 4      */

/*
Challenge 1: Void Fubktion
1. Erstellen Sie eine void-Funktion mit dem Namen ausgabeMeinArray, die ein array als Parameter übernimmt.
2. Geben Sie die einzelnen Elemente des Arrays auf der Konsole aus.
*/
void ausgabeMeinArray(int myArray[], int length) {
    for (int i;i<length;++i) {
        std::cout << myArray[i] << std::endl;
    }
}
/*
Challenge 2: Float Funktion
1. Erstellen SIe eine float Funktion, die zwei float-Werte als Parameter übernimmt.
2. Die Funktion berechnet die Multiplikation aus dem ersten Parameter und dem um 2 erhoeten zweiten Parameter.
*/
float multiplus2(float a, float b) {
    return (a*(b+2));
}

/*
Challenge 3: 
1. Erstellen Sie eine bool Funktion, die 3 integer Parameter übernimmt.
2. Geben Sie true zurueck, wenn die erste Variable kleiner ist als die zweite und die zweite kleiner ist als die dritte. Sonst gib false zurueck
*/
bool isSort(int a, int b, int c){
    return ( a<b && b<c);
}

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
    std::srand(std::time(0));
    int y {(rand()%3)+1};
    printf("Der Spieler hat %i ausgewaehlt.\n",x);
    printf("Der Computer hat %i ausgewaehlt.\n",y);
    
    if (x==y) {printf("Es gewinnt Niemand.\n");}
    if (x-y==1||x-y==(-2)) {printf("Es gewinnt der Spieler.\n");}
    if (x-y==(-1)||x-y==2) {printf("Es gewinnt der Computer.\n");}
    return;
}

int main() {
    kapitel3();
    return 0;
}