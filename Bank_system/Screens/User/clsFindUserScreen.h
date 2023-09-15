#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


class clsFindUserScreen : protected clsScreen
{

private:


static void _PrintUserInfo(clsUser NewUser){

        cout << "\nUser Card" << endl;
        cout << "-----------------------------------" << endl;
        cout << "FirstName    : " << NewUser.FirstName() << endl;
        cout << "LastName     : " << NewUser.LastName() << endl;
        cout << "FullName     : " << NewUser.FullName() << endl;
        cout << "Email        : " << NewUser.Email() << endl;
        cout << "Phone        : " << NewUser.Phone() << endl;
        cout << "User Name    : " << NewUser.UserName() << endl;
        cout << "PassWord     : " << NewUser.PassWord() << endl;
        cout << "Permissions  : " << NewUser.Permissions() << endl;
        cout << "-----------------------------------" << endl;

 }

 public:


 static void ShowFindUserScreen(){


     _DrawScreenHeader("Find User Screen");

  cout << "\nPlease Enter UserName: ";
  string UserName = clsInputValidate::ReadString();

  while(!clsUser::IsUserExist(UserName))
  {
      cout << "UserName is not exists, choose another one: ";
        UserName = clsInputValidate::ReadString();
  }

  clsUser User = clsUser::Find(UserName);

  if(!User.IsEmpty())
  {
      cout << "User Found :-)\n";
  }
  else
  {
      cout << "User not found :-(\n";
  }

  _PrintUserInfo(User);



  }


};
