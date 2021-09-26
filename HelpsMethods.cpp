#include "Helpsmethods.h"

string HelpsMethods::intNaString(int num) {

    string str = to_string(num);
    return str;
}


int HelpsMethods::StringNaInt(string str_num) {
    int num = stoi(str_num);
    return num;
}

string HelpsMethods::doubleNaString(double num) {
    string str = to_string(num);
    return str;
}

double HelpsMethods::stringNaDouble(string num) {
    double newNum = atof(num.c_str());
    return newNum;
}




int HelpsMethods::ConvestationActualDateFromStringToInt() {

    string date, dateY, dateM, dateD;
    int newDate;

    SYSTEMTIME time;
    GetSystemTime(&time);


    dateY = intNaString(time.wYear);
    dateM = intNaString(time.wMonth);
    dateD = intNaString(time.wDay);

//cout << dateY << dateM << dateD;

    date = dateY+dateM+dateD;
    newDate = StringNaInt(date);

    return newDate;

}

int HelpsMethods::ConvestationChoosedDateFromStringToInt() {

    string date = "";
    string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, oldDate, YY;
    int newDate = 0;
    char sign;

    cout << "Please insert date in YYYY-MM-DD format! " << endl;
    cin >> date;

    dateY = date[0];
    dateYY = date[1];
    dateYYY = date[2];
    dateYYYY = date[3];
    dateM = date[5];
    dateMM = date[6];
    dateD = date[8];
    dateDD = date[9];


    YY = dateY+dateYY+dateYYY+dateYYYY;


    if(date.length() !=10 || date[4]!= '-' || date[7]!='-') {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }
    if(StringNaInt(YY)%4 != 0 && StringNaInt(dateM)==0 && StringNaInt(dateMM)==2 && StringNaInt(dateD)==2 && StringNaInt(dateDD) == 9) {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }
    if(StringNaInt(dateY)<2) {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }
    if((StringNaInt(dateM) == 1 && StringNaInt(dateMM)>2) || StringNaInt(dateM)>1) {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }
    if((StringNaInt(dateD)>3) || (StringNaInt(dateD)==3 && StringNaInt(dateDD)>1)) {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }



    oldDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    newDate = StringNaInt(oldDate);
    cout << newDate << endl;


    return newDate;

}

string HelpsMethods::changeCommaToDot(string amount) {

    cout << "amount " << amount << endl;
    string newAmount;


    for(int i=0; i<amount.length()-1; i++) {
        if(amount[i]==',') {
            amount[i] = '.';
        }
    }

    return amount;




}
