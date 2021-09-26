#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include "Expenses.h"
#include "Incomes.h"
#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "Users.h"
#include "HelpsMethods.h"


using namespace std;

class TransactionMenager{

const int LOGGED_USER_ID;
vector<Expense> expense;
vector<Incomes> income;
FileWithExpenses fileWithExpenses;
FileWithIncomes fileWithIncomes;
HelpsMethods helpsmethods;

public:

TransactionMenager(string nameOfFileWithExpenses, string nameOfFileWithIncomes, int loggedUserId);
void addIncomes();
void AddNewExpenses();
void getBalance(int firstDate, int secondDate);
void getBallanceFromCurrentMonth();
void getBalanceFromLastMonth();
void getBalanceCustom();
void ExpensesFromToday();
void ExpensesFromAnotherDay();
int downloadIdForNewExpenses();
int downloadIdForNewIncomes();
void showAllExpenses();
void showAllIncomes();
vector<Incomes> sortIncomesFromGreater(vector<Incomes> tempIncomes);
vector<Expense> sortExpensesFromGreater(vector<Expense> tempExpenses);





};

#endif // TRANSACTIONMENAGER_H

