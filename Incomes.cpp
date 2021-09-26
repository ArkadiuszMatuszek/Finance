#include "Incomes.h"

void setIncomeId(int newIncomeId);
void setUserId(int newUserId);
void setAmount(int newAmount);
void setDate(int newDate);
void setItem(string newItem);

int downloadIncomeId();
int downloadUserId();
int downloadAmount();
int downloadDate();
string downloadItem();

void Incomes::setIncomeId(int newIncomeId){
incomeId=newIncomeId;
}

void Incomes::setUserId(int newUserId){
userId=newUserId;
}

void Incomes::setAmount(string  newAmount){
amount=newAmount;
}

void Incomes::setDate(int newDate){
date=newDate;
}

void Incomes::setItem(string newItem){
item=newItem;
}

int Incomes::downloadIncomeId(){
return incomeId;
}

int Incomes::downloadUserId(){
return userId;
}

string  Incomes::downloadAmount(){
return amount;
}

int Incomes::downloadDate(){
return date;
}

string Incomes::downloadItem(){
return item;
}

bool Incomes::operator<(Incomes& incomes){
return (date<incomes.downloadDate());
}

bool Incomes::operator>(const Incomes& incomes)const{
return (date>incomes.date);
}
