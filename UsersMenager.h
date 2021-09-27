#ifndef USERSMENAGER_H
#define USERSMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Users.h"
#include "FileWithUser.h"

using namespace std;

class UserMenager{

int loggedUserId{0};
vector <Users> newUsers;
FileWithUser fileWithUser;


public:
UserMenager(string nameOfFileWithUser);
void userRegistation();
void userLogin();
void loadUsersFromFile();
int downloadIdForNewUser();
Users SetDateForNewUser();
int downloadIdLoggedUser();
bool isUserLogged();
void passwordChange();
int logout();







};


#endif
