#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

using namespace std;


#include <iostream>
#include <vector>

#include "Markup.h"
#include "Expenses.h"

class FileWithExpenses{

const string EXPENSES_FILENAME;

public:

FileWithExpenses(string NameOfExpensesFile);
void addeExpensesToFile(Expense expense);
vector<Expense> loadExpensesFromFile(int loggedUserId);


};

#endif
