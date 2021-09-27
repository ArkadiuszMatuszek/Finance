#ifndef FILEWITHUSER_H
#define FILEWITHUSER_H

#include <iostream>
#include <vector>


#include "Users.h"
#include "Markup.h"


using namespace std;

class FileWithUser{

  const string USERS_FILENAME;


public:
    FileWithUser(string nameOfFileWithUser);
    void addUserToFile(Users users);
    vector<Users> LoadUsersFromFile();
    void saveUserAfterChangingPassword(int id, string password);



};

#endif
