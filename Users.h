#ifndef USERS_H
#define USERS_H

#include <iostream>

using namespace std;

class Users{

string login;
string password;
string name;
string surname;
int userId;


public:

void setId(int newUserId);
void setLogin(string newLogin);
void setName(string newName);
void setSurname(string newSurname);
void setPassword(string newPassword);

int downloadId();
string downloadLogin();
string downloadName();
string downloadSurname();
string downloadPassword();





};



#endif
