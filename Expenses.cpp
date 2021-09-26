#include "Expenses.h"

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

void Expense::setExpenseId(int newExpenseId){
expenseId=newExpenseId;
}

void Expense::setUserId(int newUserId){
userId=newUserId;
}

void Expense::setAmount(string newAmount){
amount=newAmount;
}

void Expense::setDate(int newDate){
date=newDate;
}

void Expense::setItem(string newItem){
item=newItem;
}

int Expense::downloadExpenseId(){
return expenseId;
}

int Expense::downloadUserId(){
return userId;
}

string Expense::downloadAmount(){
return amount;
}

int Expense::downloadDate(){
return date;
}

string Expense::downloadItem(){
return item;
}

bool Expense::operator<(Expense& expense){
return (date<expense.downloadDate());
}

bool Expense::operator>(const Expense& expense)const{
return (date>expense.date);
}


