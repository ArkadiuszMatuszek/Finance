#include "Finance.h"

Finance::Finance(string nameOfFileWithUser, string nameOfFileWithExpenses, string nameOfFileWithIncomes):
    usermenager(nameOfFileWithUser),EXPENSES_FILENAME(nameOfFileWithExpenses),INCOMES_FILENAME(nameOfFileWithIncomes){
    transactionMenager=nullptr;
    }

Finance::~Finance(){
    delete transactionMenager;
    transactionMenager=nullptr;
}


void Finance::userRegistation(){
usermenager.userRegistation();
}

int Finance::userLogin(){
usermenager.userLogin();
transactionMenager = new TransactionMenager(EXPENSES_FILENAME,INCOMES_FILENAME, usermenager.downloadIdLoggedUser());
}

void Finance::addExpense(){
transactionMenager->AddNewExpenses();
}

void Finance::addIncome(){
transactionMenager->addIncomes();
}


bool Finance::isUserLogged(){
    usermenager.isUserLogged();
}

void Finance::getBalance(){
transactionMenager->getBallanceFromCurrentMonth();
}








