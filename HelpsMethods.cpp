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

    return newDate;

}

int HelpsMethods::ConvestationChoosedDateFromStringToInt() {

    string date = "";
    string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, oldDate, YY, DD, MM;
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
    MM = dateM+dateMM;
    DD = dateD+dateDD;



    if(date.length() !=10 || date[4]!= '-' || date[7]!='-') {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }
    if(StringNaInt(YY)%4 != 0 && StringNaInt(dateM)==0 && StringNaInt(dateMM)==2 && StringNaInt(DD)>=29) {
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

    if(StringNaInt(dateM)==0 && (StringNaInt(dateMM)==4 || StringNaInt(dateMM)==6 || StringNaInt(dateMM)==9 || StringNaInt(MM)==11) && StringNaInt(DD)==31) {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }
    if((StringNaInt(dateD)>3) || (StringNaInt(dateD)==3 && StringNaInt(dateDD)>1)) {
        cout << "Date is not correct, please insert date again! " << endl;
        ConvestationChoosedDateFromStringToInt();
    }



    oldDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    newDate = StringNaInt(oldDate);
    //cout << newDate << endl;


    return newDate;

}

string HelpsMethods::changeCommaToDot(string amount) {

    //cout << "amount " << amount << endl;
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

   // cout << "StartDate: " <<  startDate << endl;
    //cout << "FinishDate: " << finishDate << endl;
    system("pause");

    return finishDate;
}

int HelpsMethods::getDateToBilanceFromPreviouslyMonth(){
    string date;
   int finishDate;
   string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, strFinishDate, YY, MM, DD;
   int newMM;


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
    //cout << "Aktualnie sprawdzany miesiac to: " << newMM << endl;
    system("pause");

    if(newMM == 1){
        newMM = 12;
    }

    if(newMM<10){
    dateMM = intNaString(newMM);
    dateM = "0";
    MM = dateM+dateMM;
    }else{
    MM = intNaString(newMM);
    }

    dateD = "0";
    dateDD = "1";

    strFinishDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    finishDate = StringNaInt(strFinishDate);



    return finishDate;
}

int HelpsMethods::backActualDateOneMonth(){

   string date;
   int finishDate;
   string dateY, dateYY, dateYYY, dateYYYY, dateM, dateMM, dateD, dateDD, strFinishDate, YY, MM, DD;
   int newMM;


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
    //cout << "Aktualnie sprawdzany miesiac to: " << newMM << endl;
    system("pause");

    if(newMM == 1){
        newMM = 12;
    }

    if(newMM<10){
    dateMM = intNaString(newMM);
    dateM = "0";
    MM = dateM+dateMM;
    }else{
    MM = intNaString(newMM);
    //cout << "MM " << MM << endl;
    }


    if(StringNaInt(dateM)==0 && (StringNaInt(dateMM)==4 || StringNaInt(dateMM)==6 || StringNaInt(dateMM)==9 || StringNaInt(MM)==11)){
   // cout << "jestem tutaj 1" << endl;
        dateD = "3";
        dateDD = "1";

    }else{
     //   cout << "jestem tutaj 2" << endl;
    dateD = "3";
    dateDD = "0";

    }


    strFinishDate = dateY+dateYY+dateYYY+dateYYYY+dateM+dateMM+dateD+dateDD;
    finishDate = StringNaInt(strFinishDate);



    return finishDate;
}

 double HelpsMethods::IncomesMinusExpenses(double a, double b){

double results = 0;

results = a-b;

return results;

}
