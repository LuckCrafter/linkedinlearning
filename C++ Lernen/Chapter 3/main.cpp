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

int main(){
    kapitel3();
    return 0;
}