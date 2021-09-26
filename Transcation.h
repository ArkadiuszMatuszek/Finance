#ifndef TRANSCATION_H
#define TRANSCATION_H


#include <iostream>

using namespace std;

class Transcation{

public:

    Transcation();
    friend class TranscationManager;
    friend class FileWithExpenses;
    friend class FileWithIncomes;


};


#endif
