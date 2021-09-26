#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

using namespace std;


#include <iostream>
#include <vector>

#include "Markup.h"
#include "Incomes.h"

class FileWithIncomes{

const string INCOMES_FILENAME;

public:
FileWithIncomes(string nameOfFileWithIncomes);
void addIncomesToFile(Incomes incomes);
vector<Incomes> loadIncomesFromFile();


};

#endif
