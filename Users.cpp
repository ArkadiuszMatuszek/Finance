#include "Users.h"



void Users::setId(int newUserId){
userId = newUserId;
}

void Users::setLogin(string newLogin){
login = newLogin;
}

void Users::setName(string newName){
name = newName;
}

void Users::setSurname(string newSurname){
surname = newSurname;
}

void Users::setPassword(string newPassword){
password = newPassword;
}

int Users::downloadId(){
return userId;
}

string Users::downloadLogin(){
return login;
}

string Users::downloadName(){
return name;
}

string Users::downloadSurname(){
return surname;
}
string Users::downloadPassword(){
return password;
}


