#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(): Account() {

    interestRate = 0;
}

SavingsAccount::SavingsAccount(double b, double r) : Account(b) {

    interestRate = r;
}

SavingsAccount::~SavingsAccount() {}

double SavingsAccount::calculateInterest() {
    
    double interest = 0;

    interest = Account::getBalance() * interestRate;

    return interest;
}

void SavingsAccount::setInterestRate(double iR) {

    interestRate = iR;
}

double SavingsAccount::getInterestRate() {

    return interestRate;
}
