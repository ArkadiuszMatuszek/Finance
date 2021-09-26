#ifndef FINANCE_H
#define FINANCE_H


#include <iostream>
#include <vector>
#include "UsersMenager.h"
#include "TransactionMenager.h"




using namespace std;

class Finance{

UserMenager usermenager;
TransactionMenager *transactionMenager;
const string EXPENSES_FILENAME, INCOMES_FILENAME;


public:
Finance(string fileWithUser, string fileWithExpenses, string fileWithIncomes);
~Finance();
void userRegistation();
int userLogin();
void saveUsersToFile();
void addExpense();
void addIncome();
bool isUserLogged();
void getBalance();





};



#endif // FINANCE_H
