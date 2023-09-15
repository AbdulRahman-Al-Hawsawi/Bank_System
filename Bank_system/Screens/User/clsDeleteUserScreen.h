#pragma once
#include <iostream>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


class clsDeleteUserScreen : protected clsScreen
{

private:


static void _PrintUser(clsUser User){

        cout << "\nClient Card" << endl;
        cout << "-----------------------------------" << endl;
        cout << "FirstName    : " << User.FirstName() << endl;
        cout << "LastName     : " << User.LastName() << endl;
        cout << "FullName     : " << User.FullName() << endl;
        cout << "Email        : " << User.Email() << endl;
        cout << "Phone        : " << User.Phone() << endl;
        cout << "UserName     : " << User.UserName() << endl;
        cout << "PassWord     : " << User.PassWord() << endl;
        cout << "Balance      : " << User.Permissions() << endl;
        cout << "-----------------------------------" << endl;

 }


 public:

static void ShowDeleteUserScreen(){


  _DrawScreenHeader("Delete User Screen");

  cout << "\nPlease Enter UserName: ";
  string UserName = clsInputValidate::ReadString();

  while(!clsUser::IsUserExist(UserName))
  {
      cout << "UsserName is not exists, choose another one: ";
        UserName = clsInputValidate::ReadString();
  }

  clsUser User = clsUser::Find(UserName);

 _PrintUser(User);

  cout << "Are you sure you want to delete this User? N/Y ";

  char Answer = 'n';
  cin >> Answer;


 if(Answer == 'y' || Answer == 'Y')
 {

     if(User.Delete())
     {
         cout << "\nUser Delete Successfully :-)\n";
         _PrintUser(User);
     }
     else
     {
         cout << "\nError User was not deleted.\n";
     }

 }

 }


};

