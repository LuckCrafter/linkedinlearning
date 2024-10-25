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
    std::srand(std::time(0));
    int y {(rand()%3)+1};
    printf("Der Spieler hat %i ausgewaehlt.\n",x);
    printf("Der Computer hat %i ausgewaehlt.\n",y);
    
    if (x==y) {printf("Es gewinnt Niemand.\n");}
    if (x-y==1||x-y==(-2)) {printf("Es gewinnt der Spieler.\n");}
    if (x-y==(-1)||x-y==2) {printf("Es gewinnt der Computer.\n");}
    return;
}


/*      Kapitiel 6      */

/*
Challange TicTacToe:
Zwei Spieler:innen spielen gegeneinander.
Spieler:in 1 (Kreuz) beginnt und waehlt ein Feld aus.
Spieler:in 2 (Kreis) beginnt und waehlt ein Feld aus, das frei ist.
Spieler:in 1 ist wieder am Zug. Das wiederholt sich so lange, bis ein:e Spieler:in 3 in einer Reihe hat oder bis kein Feld mehr frei ist.
*/

bool ticTacToeChecker(int const board[3][3]) {
    int check[8] {0};
    for (int i=0;i<9;++i) {
        check[i/3]+=board[i%3][i/3];
        check[(i%3)+3]+=board[i%3][i/3];
        if (i==0||i==4||i==8) check[6]+=board[i%3][i/3];
        if (i==2||i==4||i==6) check[7]+=board[i%3][i/3];
    }
    for (int e:check) {
        if (e==9||e==12) return true;
    }
    return false;
}

void ticTacToePrinter(int const board[3][3]) {
    for (int i=0;i<9;++i) {
        char c {'0'+i};
        if (board[i%3][i/3]==3) c = 'X';
        if (board[i%3][i/3]==4) c = 'O';
        if(i%3==0) printf("+-+-+-+\n");
        printf("|%c",c);
        if(i%3==2) printf("|\n");
    }
    printf("+-+-+-+\n\n");
}

void ticTacToe() {
    bool playerOne {true};
    int board[3][3] {0};
    int turnCounter {0};
    do {
        int input;
        do {
            int player = (playerOne) ? 1 : 2;
            printf("Spieler %i ist am Zug.\n",player);
            ticTacToePrinter(board);
            printf("Waehle dein Feld: ");
            std::cin >> input;
        } while ((input<0||input>8)||board[input%3][input/3]!=0);

        board[input%3][input/3]=(playerOne)?3:4;

        playerOne=!playerOne;
        ++turnCounter;
    } while (!ticTacToeChecker(board) && turnCounter<9);

    ticTacToePrinter(board);
    if(!ticTacToeChecker(board)) return;
    int player = (!playerOne) ? 1 : 2;
    printf("Spieler %d hat gewonnen.\n",player);
    return;
}

int main() {
    ticTacToe();
}