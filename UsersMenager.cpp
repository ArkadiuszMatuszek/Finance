#include "UsersMenager.h"



UserMenager::UserMenager(string nameOfFileWithUser):fileWithUser(nameOfFileWithUser){
newUsers = fileWithUser.LoadUsersFromFile();
}

void UserMenager::userRegistation() {

    Users users = SetDateForNewUser();

    newUsers.push_back(users);
    fileWithUser.addUserToFile(users);


}

Users UserMenager::SetDateForNewUser() {

    Users users;

    string login, password, name, surname;
    int id;
    newUsers = fileWithUser.LoadUsersFromFile();

    users.setId(downloadIdForNewUser());

    vector<Users>::iterator itr=newUsers.begin();

    cout << "Please, insert your login " << endl;
    cin >> login;
    users.setLogin(login);
    cout << newUsers.size() << endl;

    for(int i=0; i<newUsers.size(); i++) {
        if(newUsers[i].downloadLogin() == login) {
            cout << "Znaleziono juz taki login " << endl;
            Sleep(1000);
            system("cls");
            userRegistation();
        }

        itr++;
    }
    cout << "Please, insert your password " << endl;
    cin >> password;
    users.setPassword(password);

    cout << "Please, insert your name " << endl;
    cin >> name;
    users.setName(name);

    cout << "Please, insert your surname " << endl;
    cin >> surname;
    users.setSurname(surname);

    cout << "Your account was created" << endl;

    return users;








}

void UserMenager::userLogin() {


    string login, password;
    int idZalogowanegoUzytkownika;
    Users users;

    newUsers = fileWithUser.LoadUsersFromFile();

    cout << "Please, insert your login" << endl;
    cin >> login;
    users.setLogin(login);

    vector<Users>::iterator itr=newUsers.begin();

    for(int i=0; i<newUsers.size(); i++) {
        if(newUsers[i].downloadLogin() == login) {
            for(int numberOfTrail = 3; numberOfTrail>0; numberOfTrail--) {
                cout << "Please, insert your password " << endl;
                cin >> password;
                users.setPassword(password);

                if(newUsers[i].downloadPassword() == password) {
                    cout << "You are success logged in " << endl;
                     newUsers[i].setId(newUsers[i].downloadId());
                    loggedUserId = newUsers[i].downloadId();
                    cout << loggedUserId << endl;
                    break;

                }
            }
            system("cls");
            break;
        }
        itr++;

    }


}

int UserMenager::downloadIdForNewUser() {
    if(newUsers.empty() == true)
        return 1;
    else
        return newUsers.back().downloadId() + 1;
}

int UserMenager::downloadIdLoggedUser(){
return loggedUserId;
}

bool UserMenager::isUserLogged(){
    if(loggedUserId!=0){
        return true;
    }else{
    return false;
    }

}






