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

    string date, dateY, dateM, newDateM, dateMM, dateD, newDateD, dateDD;
    int newDate;

    SYSTEMTIME time;
    GetSystemTime(&time);


    dateY = intNaString(time.wYear);
    dateM = intNaString(time.wMonth);
    dateD = intNaString(time.wDay);

    newDateM = dateM[0];
    dateMM = dateM[1];
    newDateD = dateD[0];
    dateDD = date[1];

    if(StringNaInt(dateM)<=9) {
        newDateM = "0";
        dateMM = intNaString(time.wMonth);
        dateM = newDateM+dateMM;
    }

    if(StringNaInt(dateD)<=9) {
        newDateD = "0";
        dateDD = intNaString(time.wDay);
        dateD = newDateD+dateDD;
    }


    date = dateY+dateM+dateD;
    newDate = StringNaInt(date);
    system("cls");

    return newDate;

}

int HelpsMethods::ConvestationChoosedDateFromStringToInt() {

    string date = "";
    string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, oldDate, YY, DD, MM;
    int newDate;
    char sign;



    for(int i=0; i<=4; i++) {
        system("cls");
        cout << "Urgent, you have only " << 3-i << " trials to type correct date! Please be careful!" << endl;
        cout << i << endl;
        if(i == 3) {
            cout << "You typed 3 times wrong dates, program will close" << endl;
            exit(0);
        }
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
        MM = dateM+dateMM;
        DD = dateD+dateDD;

        if((date.length() !=10 || date[4]!= '-' || date[7]!='-')
                ||(StringNaInt(YY)%4 != 0 && StringNaInt(dateM)==0 && StringNaInt(dateMM)==2 && StringNaInt(DD)>=29)
                || (StringNaInt(dateY)<2)
                || ((StringNaInt(dateM) == 1 && StringNaInt(dateMM)>2) || StringNaInt(dateM)>1)
                || (StringNaInt(dateM)==0 && (StringNaInt(dateMM)==4 || StringNaInt(dateMM)==6 || StringNaInt(dateMM)==9 || StringNaInt(MM)==11) && StringNaInt(DD)==31)
                || ((StringNaInt(dateD)>3) || (StringNaInt(dateD)==3 && StringNaInt(dateDD)>1))) {
            cout << "Date is not correct, try again"  << endl;
            Sleep(1000);
        } else {
            cout << "Date is correct " << endl;
            system("cls");
            break;
        }
    }

    oldDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    newDate = StringNaInt(oldDate);
    system("cls");

    return newDate;





}

string HelpsMethods::changeCommaToDot(string amount) {

    string newAmount;

    for(int i=0; i<amount.length()-1; i++) {
        if(amount[i]==',') {
            amount[i] = '.';
        }
    }

    return amount;
}

int HelpsMethods::getDateToBilanceFromCurentMonth() {

    string date;
    int startDate, finishDate;
    string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, strFinishDate ;


    date = intNaString(ConvestationActualDateFromStringToInt());

    dateY = date[0];
    dateYY = date[1];
    dateYYY = date[2];
    dateYYYY = date[3];
    dateM = date[4];
    dateMM = date[5];
    dateD = date[6];
    dateDD = date[7];

    startDate = StringNaInt(date);

    dateD = "0";
    dateDD = "1";

    strFinishDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    finishDate = StringNaInt(strFinishDate);
    system("cls");

    return finishDate;
}

int HelpsMethods::getDateToBilanceFromPreviouslyMonth() {
    string date;
    int finishDate;
    string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, strFinishDate, YY, MM, DD;
    int newMM;

    system("cls");

    date = intNaString(ConvestationActualDateFromStringToInt());

    dateY = date[0];
    dateYY = date[1];
    dateYYY = date[2];
    dateYYYY = date[3];
    dateM = date[4];
    dateMM = date[5];
    dateD = date[6];
    dateDD = date[7];

    YY = dateY+dateYY+dateYYY+dateYYYY;
    MM = dateM+dateMM;
    DD = dateD+dateDD;

    newMM = StringNaInt(MM)-1;

    if(newMM == 1) {
        newMM = 12;
    }

    if(newMM<10) {
        dateMM = intNaString(newMM);
        dateM = "0";
        MM = dateM+dateMM;
    } else {
        MM = intNaString(newMM);
    }

    dateD = "0";
    dateDD = "1";

    strFinishDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    finishDate = StringNaInt(strFinishDate);
    system("cls");



    return finishDate;
}

int HelpsMethods::backActualDateOneMonth() {

    string date;
    int finishDate;
    string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, strFinishDate, YY, MM, DD;
    int newMM;

    system("cls");

    date = intNaString(ConvestationActualDateFromStringToInt());

    dateY = date[0];
    dateYY = date[1];
    dateYYY = date[2];
    dateYYYY = date[3];
    dateM = date[4];
    dateMM = date[5];
    dateD = date[6];
    dateDD = date[7];

    YY = dateY+dateYY+dateYYY+dateYYYY;
    MM = dateM+dateMM;
    DD = dateD+dateDD;

    newMM = StringNaInt(MM)-1;


    if(newMM == 1) {
        newMM = 12;
    }

    if(newMM<10) {
        dateMM = intNaString(newMM);
        dateM = "0";
        MM = dateM+dateMM;
    } else {
        MM = intNaString(newMM);
    }


    if(MM == "01" || MM == "03" || MM == "05" || MM == "07" || MM == "08" || MM == "10" ||  MM == "12" ) {
        DD = "31";
    } else if(MM == "02") {
        DD = "28";
    } else {
        DD = "30";
    }


    strFinishDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+DD;
    finishDate = StringNaInt(strFinishDate);
    system("cls");



    return finishDate;
}

int HelpsMethods::getDateToBilanceFromCurrentMonthFinishDate() {
    string date;
    int finishDate;
    string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, strFinishDate, YY, MM, DD;
    int newMM;

    system("cls");
    date = intNaString(ConvestationActualDateFromStringToInt());

    dateY = date[0];
    dateYY = date[1];
    dateYYY = date[2];
    dateYYYY = date[3];
    dateM = date[4];
    dateMM = date[5];
    dateD = date[6];
    dateDD = date[7];

    YY = dateY+dateYY+dateYYY+dateYYYY;
    MM = dateM+dateMM;
    DD = dateD+dateDD;

    newMM = StringNaInt(MM);
    if(newMM == 1) {
        newMM = 12;
    }

    if(newMM<10) {
        dateMM = intNaString(newMM);
        dateM = "0";
        MM = dateM+dateMM;
    } else {
        MM = intNaString(newMM);
    }


    if(StringNaInt(dateM)==0 && (StringNaInt(dateMM)==4 || StringNaInt(dateMM)==6 || StringNaInt(dateMM)==9 || StringNaInt(MM)==11)) {
        dateD = "3";
        dateDD = "1";

    } else {
        dateD = "3";
        dateDD = "0";

    }


    strFinishDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    finishDate = StringNaInt(strFinishDate);
    system("cls");



    return finishDate;
}

double HelpsMethods::IncomesMinusExpenses(double a, double b) {

    double results = 0;

    results = a-b;

    return results;

}

