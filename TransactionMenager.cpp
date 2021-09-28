#include "TransactionMenager.h"


TransactionMenager::TransactionMenager(string nameOfFileWithExpenses, string nameOfFileWithIncomes, int loggedUserId):
    fileWithExpenses(nameOfFileWithExpenses), fileWithIncomes(nameOfFileWithIncomes), LOGGED_USER_ID(loggedUserId) {
    expense=fileWithExpenses.loadExpensesFromFile(LOGGED_USER_ID);
    income=fileWithIncomes.loadIncomesFromFile(LOGGED_USER_ID);
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

void TransactionMenager::getBallanceFromCurrentMonth() {

    vector<Incomes> tempIncomes;
    vector<Expense> tempExpenses;
    int date, i, finishDate;
    double sumOfIncomesAmount = 0.0;
    double sumOfExpensesAmount = 0.0;
    double IncomesMinusExpenses = 0.0;


    tempIncomes = sortIncomesFromGreater(tempIncomes);
    tempExpenses = sortExpensesFromGreater(tempExpenses);


    date = helpsmethods.getDateToBilanceFromCurrentMonthFinishDate();
    finishDate = helpsmethods.getDateToBilanceFromCurentMonth();

    IncomesMinusExpenses = showIncomesAndExpenses(tempIncomes,tempExpenses,date,finishDate);

    cout << "IncomesMinusExpenses: " << IncomesMinusExpenses << endl;
    system("pause");


}

void TransactionMenager::getBalanceFromLastMonth() {

    vector<Incomes> tempIncomes;
    vector<Expense> tempExpenses;
    int date, finishDate;
    double sumOfIncomesAmount = 0.0;
    double sumOfExpensesAmount = 0.0;
    double IncomesMinusExpenses = 0.0;


    tempIncomes = sortIncomesFromGreater(tempIncomes);
    tempExpenses = sortExpensesFromGreater(tempExpenses);

    date = helpsmethods.backActualDateOneMonth();
    finishDate = helpsmethods.getDateToBilanceFromPreviouslyMonth();

    IncomesMinusExpenses = showIncomesAndExpenses(tempIncomes,tempExpenses,date,finishDate);

    cout << "IncomesMinusExpenses: " << IncomesMinusExpenses << endl;
    system("pause");




}

void TransactionMenager::getBalanceFromPeriod() {

    vector<Incomes> tempIncomes;
    vector<Expense> tempExpenses;
    int firstDate;
    int secondDate;
    double sumOfIncomesAmount = 0;
    double sumOfExpensesAmount = 0;
    double IncomesMinusExpenses = 0;

    tempIncomes = sortIncomesFromGreater(tempIncomes);
    tempExpenses = sortExpensesFromGreater(tempExpenses);

    cout << "Please insert date from which period: " << endl;
    firstDate = helpsmethods.ConvestationChoosedDateFromStringToInt();
    cout << "Please insert date to which period: " << endl;
    secondDate = helpsmethods.ConvestationChoosedDateFromStringToInt();

    IncomesMinusExpenses = showIncomesAndExpenses(tempIncomes,tempExpenses,secondDate,firstDate);

    cout << "IncomesMinusExpenses: " << IncomesMinusExpenses << endl;
    system("pause");

}

vector <Incomes> TransactionMenager::sortIncomesFromGreater(vector<Incomes> tempIncomes) {
    tempIncomes = income;
    sort(tempIncomes.begin(), tempIncomes.end(), greater<Incomes>());
    return tempIncomes;

}

vector<Expense> TransactionMenager::sortExpensesFromGreater(vector<Expense> tempExpenses) {
    tempExpenses = expense;
    sort(tempExpenses.begin(), tempExpenses.end(), greater<Expense>());
    return tempExpenses;

}

double TransactionMenager::showIncomesAndExpenses(vector<Incomes> tempIncomes, vector<Expense> tempExpenses, int secondDate, int firstDate) {


    double sumOfIncomesAmount = 0;
    double sumOfExpensesAmount = 0;
    double IncomesMinusExpenses = 0;

    for(int i=tempIncomes.size(); i>=0; i--) {
        if(tempIncomes[i].downloadDate() <=secondDate && tempIncomes[i].downloadDate() >=firstDate) {
            cout << "Data to: " << tempIncomes[i].downloadDate() << endl;
            cout << "Nazwa wplywu to: " << tempIncomes[i].downloadItem() << endl;
            cout << "Wartosc wplywu to: " << tempIncomes[i].downloadAmount() << endl;
            cout << endl;
            sumOfIncomesAmount += helpsmethods.stringNaDouble(tempIncomes[i].downloadAmount());
        }
    }

    for(int i=tempExpenses.size(); i>=0; i--) {
        if(tempExpenses[i].downloadDate() <=secondDate && tempExpenses[i].downloadDate() >=firstDate) {
            cout << "Data to: " << tempExpenses[i].downloadDate() << endl;
            cout << "Nazwa wydatku to: " << tempExpenses[i].downloadItem() << endl;
            cout << "Wartosc wydatku to: " << tempExpenses[i].downloadAmount() << endl;
            cout << endl;
            sumOfExpensesAmount += helpsmethods.stringNaDouble(tempExpenses[i].downloadAmount());
        }
    }

    cout << "sumOfIncomesAmount: " <<  sumOfIncomesAmount << endl;
    cout << endl;
    cout << "sumOfExpensesAmount: " <<  sumOfExpensesAmount << endl;
    cout << endl;

    IncomesMinusExpenses = helpsmethods.IncomesMinusExpenses(sumOfIncomesAmount,sumOfExpensesAmount);


    return IncomesMinusExpenses;
}



