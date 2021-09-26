#include "TransactionMenager.h"


TransactionMenager::TransactionMenager(string nameOfFileWithExpenses, string nameOfFileWithIncomes, int loggedUserId):
    fileWithExpenses(nameOfFileWithExpenses), fileWithIncomes(nameOfFileWithIncomes), LOGGED_USER_ID(loggedUserId) {
    expense=fileWithExpenses.loadExpensesFromFile();
    income=fileWithIncomes.loadIncomesFromFile();
}

void TransactionMenager::AddNewExpenses() {

    int choose;
    string item, amount;
    Expense expenses;

    cout << LOGGED_USER_ID << endl;
    system("pause");

    cout << "1. Expenses from today ? " << endl;
    cout << "2. Expenses from another day " << endl;
    cout << "Please choose! " << endl;
    cin >> choose;
    system("cls");


    if(choose == 1 ) {
        expenses.setDate(helpsmethods.ConvestationActualDateFromStringToInt());
    } else if(choose == 2) {
        expenses.setDate(helpsmethods.ConvestationChoosedDateFromStringToInt());
    }

    cout << "Please insert, what kind of expense it is " << endl;
    cin >> item;

    cout << "Please insert, value of this expense " << endl;
    cin >> amount;


    expenses.setExpenseId(downloadIdForNewExpenses());
    expenses.setUserId(LOGGED_USER_ID);
    expenses.setItem(item);
    expenses.setAmount(helpsmethods.changeCommaToDot(amount));

    expense.push_back(expenses);



    fileWithExpenses.addeExpensesToFile(expenses);

}

void TransactionMenager::addIncomes() {
    int choose;
    string item, amount;
    Incomes incomes;




    cout << "1. Incomes from today ? " << endl;
    cout << "2. Incomes from another day " << endl;
    cout << "Please choose! " << endl;
    cin >> choose;
    system("cls");


    if(choose == 1) {
        incomes.setDate(helpsmethods.ConvestationActualDateFromStringToInt());
    } else if(choose == 2) {
        incomes.setDate(helpsmethods.ConvestationChoosedDateFromStringToInt());
    }

    cout << "Please insert, what kind of incomes it is " << endl;
    cin >> item;

    cout << "Please insert, value of this incomes " << endl;
    cin >> amount;

    incomes.setIncomeId(downloadIdForNewIncomes());
    incomes.setUserId(LOGGED_USER_ID);
    incomes.setItem(item);
    incomes.setAmount(helpsmethods.changeCommaToDot(amount));


    income.push_back(incomes);


    fileWithIncomes.addIncomesToFile(incomes);

}

int TransactionMenager::downloadIdForNewExpenses() {
    if(expense.empty() == true)
        return 1;
    else
        return expense.back().downloadExpenseId()+1;
}

int TransactionMenager::downloadIdForNewIncomes() {

    if(income.empty() == true)
        return 1;
    else
        return income.back().downloadIncomeId()+1;
}

void TransactionMenager::getBallanceFromCurrentMonth(){

    vector<Incomes> tempIncomes;
    vector<Expense> tempExpenses;
    int date, i;
    date = helpsmethods.ConvestationActualDateFromStringToInt();

    tempIncomes = sortIncomesFromGreater(tempIncomes);



    while(i<tempIncomes.size() && tempIncomes[i].downloadDate() <=date){
            cout << "jestem tutaj " << endl;
            cout << tempIncomes[i].downloadDate() << endl;
            cout << tempIncomes[i].downloadItem() << endl;
            cout << tempIncomes[i].downloadAmount() << endl;

   }


}

void TransactionMenager::showAllExpenses(){

    for(int i=0; i<expense.size(); i++){
        cout << expense[i].downloadUserId() << endl;
        cout << expense[i].downloadAmount() << endl;
        cout << expense[i].downloadDate() << endl;
        cout << expense[i].downloadItem() << endl;
        cout << expense[i].downloadExpenseId() << endl;
    }

}

void TransactionMenager::showAllIncomes(){

    for(int i=0; i<income.size(); i++){
        cout << income[i].downloadUserId() << endl;
        cout << income[i].downloadAmount() << endl;
        cout << income[i].downloadDate() << endl;
        cout << income[i].downloadItem() << endl;
        cout << income[i].downloadIncomeId() << endl;

    }

}

vector <Incomes> TransactionMenager::sortIncomesFromGreater(vector<Incomes> tempIncomes){
    tempIncomes = income;
    sort(tempIncomes.begin(), tempIncomes.end(), greater<Incomes>());
    return tempIncomes;

}

vector<Expense> TransactionMenager::sortExpensesFromGreater(vector<Expense> tempExpenses){
    tempExpenses = expense;
    sort(tempExpenses.begin(), tempExpenses.end(), greater<Expense>());
    return tempExpenses;

}


