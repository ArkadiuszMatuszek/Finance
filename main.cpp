#include <iostream>
#include <windows.h>
#include <vector>
#include "Markup.h"
#include "Finance.h"
#include "FileWithUser.h"
#include "Users.h"


using namespace std;


char menuAfterLogin(){
    char select;
cout << "1. Add Incomes " << endl;
cout << "2. Add Expenses " << endl;
cout << "3. Balance from curent month " << endl;
cout << "4. Balance from previously month " << endl;
cout << "5. Balance from ... ... - you can set date from ... to... " << endl;
cout << "6. Change password " << endl;
cout << "7. Logout " << endl;
cin >> select;
return select;
}

char menuBeforeLogin(){
    char select;
cout << "1. Registration" << endl;
cout << "2. LogIn" << endl;
cout << "9. Exit" <<endl;
cout << endl;
cout << "Please, choose option from menu " << endl;
cin >> select;
return select;
}


int main()
{

Finance finance("Users.xml","Expenses.xml","Incomes.xml");
Users users;
char select;
char x = 0;

while(true){
        if(!finance.isUserLogged()){
        select = menuBeforeLogin();
    switch(select){
case '1':
    finance.userRegistation();
    break;
case '2':
    finance.userLogin();
    break;
case '9':
    exit(0);

    }
}else{
    select = menuAfterLogin();
    switch(select){
case '1':
    finance.addIncome();
    break;
case '2':
    finance.addExpense();
    break;
case '3':
    finance.getBalance();
case '7':
    exit(0);
    }


}
}
    return 0;
}


