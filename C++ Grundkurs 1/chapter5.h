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
    void showBalance() {
        printf("%i,00 €\n", mBalance);
    }
};

struct Customer {
    CustomerState mState = CustomerState::New;
    CreditCard mCreditCard;
    
    Customer(CustomerState mState) {
        this->mState = mState;
        mCreditCard.mState=CreditCardState::Valid;
    }

    bool verifyStatus() {
        // TODO: Alle Karten müssen gültig (valid) sein.
        if (mCreditCard.mState!=CreditCardState::Valid) return false;
        //TODO: Premium-Kunden dürfen sich weiterhin verschulden, Standard-Kunden nicht
        if (mState==CustomerState::Standard && mCreditCard.mBalance<0) return false;
        return true; 
    }
    void withdrawMoney(int const amnt) {
        // TODO: Prüfen ob Kunden überhaupt Geld abheben darf; Fehler melden falls nicht.
        if (!verifyStatus()) {
            printf("Not enough Money. Cant withdraw %i,- €\n",amnt);
            return;
        }
        // TODO: Dann Geld abheben;
        mCreditCard.mBalance-=amnt;
    }
    void showBalance() {
        mCreditCard.showBalance();
    }
};