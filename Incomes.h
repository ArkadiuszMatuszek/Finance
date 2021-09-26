#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

using namespace std;

class Incomes{

int incomeId, userId, date;
string item, amount;


public:

void setIncomeId(int newIncomeId);
void setUserId(int newUserId);
void setAmount(string  newAmount);
void setDate(int newDate);
void setItem(string newItem);

int downloadIncomeId();
int downloadUserId();
string  downloadAmount();
int downloadDate();
string downloadItem();

bool operator<(Incomes& incomes);
bool operator>(const Incomes& incomes) const;

};



#endif
