#ifndef HELPSMETHODS_H
#define HELPSMETHODS_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <string>
#include <stdlib.h>


using namespace std;

class HelpsMethods{

public:


string intNaString(int num);
string doubleNaString(double num);
int StringNaInt(string str_num);
int ConvestationActualDateFromStringToInt();
int ConvestationChoosedDateFromStringToInt();
string changeCommaToDot(string amount);
double stringNaDouble(string num);

};




#endif
