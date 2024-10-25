#include <iostream>

enum class CustomerState {
    New,
    Standard,
    Premium
};

enum CreditCardState {
    New,
    Valid,
    TransferInProgress,
    Invalid,
    Error
};

struct CreditCard {
    CreditCardState mState = CreditCardState::New;
    int mBalance = 100;
};

struct Customer {
    CustomerState mState = CustomerState::New;
    CreditCard mCreditCard;
};

bool verifyStatus(const Customer &cust) {
    // TODO: Alle Karten müssen gültig (valid) sein.
    if (cust.mCreditCard.mState!=CreditCardState::Valid) return false;
    //TODO: Premium-Kunden dürfen sich weiterhin verschulden, Standard-Kunden nicht
    if (cust.mState==CustomerState::Standard && cust.mCreditCard.mBalance<0) return false;
    return true; 
}

void withdrawMoney(Customer &cust, const int amnt) {
    // TODO: Prüfen ob Kunden überhaupt Geld abheben darf; Fehler melden falls nicht.
    if (!verifyStatus(cust)) {
        printf("Not enough Money. Cant withdraw %i,- €\n",amnt);
        return;
    }
    // TODO: Dann Geld abheben;
    cust.mCreditCard.mBalance-=amnt;
}

void showBalance(const CreditCard &card) {
    // TODO: Anzeigen wieviel Geld noch auf der Kreditkarte ist.
    printf("%i,- €\n", card.mBalance);
}

int main() {
    Customer peter;
    Customer john;
    // TODO: Erkläre Peter zu Premiumkunde, John zu Standartkunde.
    john.mState = CustomerState::Standard;
    peter.mState = CustomerState::Premium;
    john.mCreditCard.mState = CreditCardState::Valid;
    peter.mCreditCard.mState = CreditCardState::Valid;

    // TODO: Zeige hier an wieviel Geld Sie zur Verfügung haben
    showBalance(john.mCreditCard);
    showBalance(peter.mCreditCard);   

    std::cout << "Each is going withdraw some Money: First 50, then 100 and finally 200." << std::endl;
    withdrawMoney(john,50);
    withdrawMoney(peter,50);

    withdrawMoney(john,100);
    withdrawMoney(peter,100);

    withdrawMoney(john,200);
    withdrawMoney(peter,200);

    // TODO: Zeige hier an, wieviel Geld beide jetzt zur Verfügung haben.
    showBalance(john.mCreditCard);
    showBalance(peter.mCreditCard);

    return 0;
}