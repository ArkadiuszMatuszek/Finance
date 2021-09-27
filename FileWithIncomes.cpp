#include "fileWithIncomes.h"

FileWithIncomes::FileWithIncomes(string nameOfFileWithIncomes):INCOMES_FILENAME(nameOfFileWithIncomes){}

void FileWithIncomes::addIncomesToFile(Incomes incomes){

CMarkup xml;
    bool fileExists = xml.Load(INCOMES_FILENAME);

    if(!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", incomes.downloadUserId());
    xml.AddElem("IncomeId", incomes.downloadIncomeId());
    xml.AddElem("Date", incomes.downloadDate());
    xml.AddElem("Item", incomes.downloadItem());
    xml.AddElem("Amount", incomes.downloadAmount());

    xml.Save(INCOMES_FILENAME);
}


vector<Incomes> FileWithIncomes::loadIncomesFromFile(int loggedUserId){

Incomes incomes;
vector<Incomes> Income;
 CMarkup xml;

 xml.Load(INCOMES_FILENAME);

 xml.FindElem("Users");
 xml.IntoElem();

 while(xml.FindElem("User")){
    xml.IntoElem();
    xml.FindElem("UserId");
        int intUserId = atoi(MCD_2PCSZ(xml.GetData()));
        if(loggedUserId == intUserId){
        incomes.setUserId(intUserId);
        }else{
        xml.RestorePos();
        continue;
        }
        xml.FindElem("IncomeId");
        int intIncomeId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("Date");
        int intDate = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("Item");
        MCD_STR strItem = xml.GetData();
        xml.FindElem("Amount");
        MCD_STR strAmount = xml.GetData();
        xml.OutOfElem();



        incomes.setIncomeId(intIncomeId);
        incomes.setDate(intDate);
        incomes.setItem(strItem);
        incomes.setAmount(strAmount);
        Income.push_back(incomes);



 }

 return Income;

}



