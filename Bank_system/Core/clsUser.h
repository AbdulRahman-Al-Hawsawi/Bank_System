#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsPerson.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsString.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsUtil.h"


class clsUser : public clsPerson
{
private:

     enum enMode { EmptyMode =0, UpdateMode =1, AddNewMode =2};


    enMode _Mode;
    string _UserName;
    string _PassWord;
    int    _Permissions;
    int    _EncryptKey = 10;
    bool   _MarkForDelete = false;




string _PrepareLogInRecord(string Seperator ="#//#"){

 string LoginRecord = "" ;

 LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
 LoginRecord += UserName() + Seperator;
 LoginRecord += clsUtil::EncryptText(PassWord()) + Seperator;;
 LoginRecord += to_string(Permissions());
 return LoginRecord;

}

static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#"){

        vector<string> vUser = clsString::Split(Line,Separator);

        return clsUser(enMode::UpdateMode,vUser[0],vUser[1],vUser[2],vUser[3],vUser[4],clsUtil::DecryptText(vUser[5]),stod(vUser[6]));
    }

static string _ConvertUserObjectToLine(clsUser UserData, string Seperator = "#//#"){

   string stUserRecord ="";

   stUserRecord += UserData.FirstName()+ Seperator;
   stUserRecord += UserData.LastName() + Seperator;
   stUserRecord += UserData.Email() + Seperator;
   stUserRecord += UserData.Phone() + Seperator;
   stUserRecord += UserData.UserName() + Seperator;
   stUserRecord += clsUtil::EncryptText(UserData.PassWord()) + Seperator;
   stUserRecord += to_string(UserData.Permissions());
   return stUserRecord;
 }

static vector<clsUser> _LoadUserDataFromFile(){

    fstream MyFile;
    vector<clsUser> vUser;

    MyFile.open("Users", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

           clsUser User = _ConvertLineToUserObject(LineData);
            vUser.push_back(User);

             }
        MyFile.close();

    }
    return vUser;

}

void _SaveUsersDateToFile(vector<clsUser> User){

  fstream MyFile;
  MyFile.open("Users", ios::out );

  if(MyFile.is_open())
  {
      string DataLine = "";

         for(clsUser& U : User)
          {

             if(U.MarkForDelete() == false)
              {
                  /// we only write record that are not marked for delelte
                  DataLine =  _ConvertUserObjectToLine(U);
                  MyFile << DataLine  << endl;
              }

          }

      MyFile.close();
  }
}

void _AddDataLineToFile(string DataLine){

  fstream MyFile;
  MyFile.open("Users", ios::out | ios::app );

  if(MyFile.is_open())
  {
      MyFile << DataLine  << endl;

      MyFile.close();
  }
}

void _Update(){

   vector<clsUser> _vUser;
   _vUser = _LoadUserDataFromFile();

   for(clsUser& U : _vUser)
   {
       if(U.UserName() == UserName())
       {
           U = *this;
           break;
       }
   }

   _SaveUsersDateToFile(_vUser);

}

void _AddNew(){

    _AddDataLineToFile(_ConvertUserObjectToLine(*this));

}

static clsUser _GetEmptyUserObject(){

    return clsUser(enMode::EmptyMode,"","","","","","",0);
}


public:

     enum enPermissions{

     pAll = -1, pShowClient = 1, pAddClient =2, pDeleteClient =4,pUpdateClient =8,
     pFindClient =16, pTransactions =32, pManageUser =64, pShowLoginRegister = 128

    };

    struct stLoginRegisterRecord
    {

    string DateTime;
    string UserName;
    string PassWord;
    int Permissions;

    };


static stLoginRegisterRecord _ConvertLoginLineToRecord(string LineData){

vector <string> vLoginData = clsString::Split(LineData,"#//#");
stLoginRegisterRecord LoginRegister;

    LoginRegister.DateTime = vLoginData[0];
    LoginRegister.UserName = vLoginData[1];
    LoginRegister.PassWord = clsUtil::DecryptText(vLoginData[2]);
    LoginRegister.Permissions = stoi(vLoginData[3]);

    return LoginRegister;

}


    clsUser(enMode Mode,string FirstName,string LastName,string Email,string Phone,string UserName,string PassWord,int Permissions)
    : clsPerson(FirstName,LastName,Email,Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _PassWord = PassWord;
        _Permissions = Permissions;

    }

     bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkForDelete()
    {
        return _MarkForDelete;
    }

    string UserName()
    {
        return _UserName;
    }

    void SetPassWord(string PassWord)
    {
        _PassWord = PassWord;
    }

    string PassWord()
    {
        return _PassWord;
    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    float Permissions()
    {
        return _Permissions;
    }


   static clsUser Find(string UserName){

    fstream MyFile;

    MyFile.open("Users", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {
                clsUser User = _ConvertLineToUserObject(LineData);
                if(User.UserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
             }
        MyFile.close();

    }
    return _GetEmptyUserObject();

}

   static clsUser Find(string UserName,string PassWord){

    fstream MyFile;

    MyFile.open("Users", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

                clsUser User = _ConvertLineToUserObject(LineData);

                if(User.UserName() == UserName && User.PassWord() == PassWord)
                {
                    MyFile.close();
                    return User;
                }
             }
        MyFile.close();

    }
    return _GetEmptyUserObject();

}

bool Delete(){

    vector<clsUser> vUsers = _LoadUserDataFromFile();

    for(clsUser& U : vUsers)
    {
        if(U.UserName() == _UserName)
        {
            U._MarkForDelete = true;
            break;
        }
    }

    _SaveUsersDateToFile(vUsers);

    *this = _GetEmptyUserObject();

    return true;
}

enum enSaveResults{ svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

 enSaveResults Save(){

    switch(_Mode)
    {
    case  enMode::EmptyMode:
        {
            if(IsEmpty())
            {
              return enSaveResults::svFaildEmptyObject;
            }
        }

    case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }

    case enMode::AddNewMode:
        {
            /// this will add new record to file or database
            if(clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                 _AddNew();
                 ///we need to set the mode to update after add new
                 _Mode = enMode::UpdateMode;
                 return enSaveResults::svSucceeded;
            }

        }

    }
}

static bool IsUserExist(string UserName){

    clsUser User = clsUser::Find(UserName);
    return (!User.IsEmpty());
}

static clsUser GetAddNewUserObject(string UserName){

 return clsUser(enMode::AddNewMode,"","","","",UserName,"",0);

}

static vector<clsUser> GetUsersList(){

    return _LoadUserDataFromFile();
}

 bool CheckAccessPermission(enPermissions Permission)
{
   if(this->_Permissions == enPermissions::pAll)
    return true;

   if((Permission & this->_Permissions) == Permission)
    return true;
   else
    return false;
}

void RegisterLogIn(){

  fstream MyFile;
  string LineData ="";

  MyFile.open("LogInRegister.txt", ios::out | ios::app);

  if(MyFile.is_open()){

     LineData = _PrepareLogInRecord();

     MyFile <<   LineData << "\n";

     MyFile.close();

  }
    }

 static  vector<stLoginRegisterRecord> GetLoginRegisterList(){

    fstream MyFile;
    vector<stLoginRegisterRecord> vLoginRegister;

    MyFile.open("LogInRegister.txt", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

              vLoginRegister.push_back(_ConvertLoginLineToRecord(LineData));

             }
        MyFile.close();

    }
    return vLoginRegister;


   }


};
