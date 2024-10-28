#include <iostream>
#include <ctime>
#include <string>

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

int main(){
    return 0;
}