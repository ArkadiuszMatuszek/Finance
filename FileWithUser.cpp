#include "FileWithUser.h"

FileWithUser::FileWithUser(string nameOfFileWithUser):USERS_FILENAME(nameOfFileWithUser){}


void FileWithUser::addUserToFile(Users user){

    CMarkup xml;

    bool fileExists = xml.Load("Users.xml");

    if(!fileExists){
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.downloadId());
    xml.AddElem("Login", user.downloadLogin());
    xml.AddElem("Password", user.downloadPassword());
    xml.AddElem("Name", user.downloadName());
    xml.AddElem("Surname", user.downloadSurname());

    xml.Save(USERS_FILENAME);
}

vector<Users> FileWithUser::LoadUsersFromFile(){

    Users users;
    vector<Users> uzytkownicy;
    CMarkup xml;



    xml.Load(USERS_FILENAME);

    xml.FindElem("Users");
    xml.IntoElem();

    while(xml.FindElem("User")){
            xml.IntoElem();
        xml.FindElem("UserId");
        int intUserId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.FindElem("Login");
        MCD_STR strLogin = xml.GetData();
        xml.FindElem("Password");
        MCD_STR strPassword = xml.GetData();
        xml.FindElem("Name");
        MCD_STR strName = xml.GetData();
        xml.FindElem("Surname");
        MCD_STR strSurname = xml.GetData();
        xml.OutOfElem();



        users.setId(intUserId);
        users.setLogin(strLogin);
        users.setPassword(strPassword);
        users.setName(strName);
        users.setSurname(strSurname);
        uzytkownicy.push_back(users);



    }



   return uzytkownicy;

}


