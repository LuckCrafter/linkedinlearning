#include <iostream>
#include <ctime>
#include <string>

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

int main(){
    return 0;
}