#include "FileWithExpenses.h"

FileWithExpenses::FileWithExpenses(string nameOfFileWithExpenses):EXPENSES_FILENAME(nameOfFileWithExpenses){}

void FileWithExpenses::addeExpensesToFile(Expense expense){

CMarkup xml;
    bool fileExists = xml.Load(EXPENSES_FILENAME);

   if(!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    cout << expense.downloadAmount() << endl;
    system("pause");

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", expense.downloadUserId());
    xml.AddElem("ExpenseId", expense.downloadExpenseId());
    xml.AddElem("Date", expense.downloadDate());
    xml.AddElem("Item", expense.downloadItem());
    xml.AddElem("Amount", expense.downloadAmount());

    xml.Save(EXPENSES_FILENAME);
}

vector<Expense> FileWithExpenses::loadExpensesFromFile(int loggedUserId){

Expense expense;
vector<Expense> Expens;
CMarkup xml;

xml.Load(EXPENSES_FILENAME);


xml.FindElem("Users");
 xml.IntoElem();

 while(xml.FindElem("User")){

    xml.IntoElem();
    xml.FindElem("UserId");
        int intUserId = atoi(MCD_2PCSZ(xml.GetData()));
        if(loggedUserId == intUserId){
        expense.setUserId(intUserId);
        }else{
        xml.RestorePos();
        continue;
        }
        xml.FindElem("ExpenseId");
        int intExpenseId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("Date");
        int intDate = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("Item");
        MCD_STR strItem = xml.GetData();
        xml.FindElem("Amount");
        MCD_STR strAmount = xml.GetData();
        xml.OutOfElem();

        expense.setUserId(intUserId);
        expense.setExpenseId(intExpenseId);
        expense.setDate(intDate);
        expense.setItem(strItem);
        expense.setAmount(strAmount);
        Expens.push_back(expense);



 }

 return Expens;
}




