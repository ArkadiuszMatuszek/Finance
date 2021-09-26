#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expense{

int expenseId, userId,date;
string item, amount;




public:




void setExpenseId(int newExpenseId);
void setUserId(int newUserId);
void setAmount(string newAmount);
void setDate(int newDate);
void setItem(string newItem);

int downloadExpenseId();
int downloadUserId();
string downloadAmount();
int downloadDate();
string downloadItem();

bool operator<(Expense& expense);
bool operator>(const Expense& expense) const;
};




#endif
