#include <iostream>
#include "chapter5.h"

int main() {
    Customer peter(CustomerState::Premium);
    Customer john(CustomerState::Standard);
 
    // TODO: Zeige hier an wieviel Geld Sie zur Verfügung haben
    printf("John: ");
    john.showBalance();
    printf("Peter: ");
    peter.showBalance();

    std::cout << "Each is going withdraw some Money: First 50, then 100 and finally 200." << std::endl;
    john.withdrawMoney(50);
    peter.withdrawMoney(50);
    john.withdrawMoney(100);
    peter.withdrawMoney(100);
    john.withdrawMoney(200);
    peter.withdrawMoney(200);

    // TODO: Zeige hier an, wieviel Geld beide jetzt zur Verfügung haben.
    printf("John: ");
    john.showBalance();
    printf("Peter: ");
    peter.showBalance();

    return 0;
}