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
vector<Incomes> newIncome;
FileWithExpenses fileWithExpenses;
FileWithIncomes fileWithIncomes;
HelpsMethods helpsmethods;

double showIncomesAndExpenses(vector<Incomes> tempIncomes, vector<Expense> tempExpenses,int secondDate,int firstDate);

public:

TransactionMenager(string nameOfFileWithExpenses, string nameOfFileWithIncomes, int loggedUserId);
void addIncomes();
void AddNewExpenses();
void getBalanceFromPeriod();
void getBallanceFromCurrentMonth();
void getBalanceFromLastMonth();
void getBalanceCustom();
void ExpensesFromToday();
void ExpensesFromAnotherDay();
int downloadIdForNewExpenses();
int downloadIdForNewIncomes();
vector<Incomes> sortIncomesFromGreater(vector<Incomes> tempIncomes);
vector<Expense> sortExpensesFromGreater(vector<Expense> tempExpenses);






};

#endif // TRANSACTIONMENAGER_H

