#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


class clsAddNweUserScreen : protected clsScreen
{
  private:



static short _ReadPermissions(){

    char Access = 'N';
    short PermissionsNumber =0;

    cout << "\nDo you want to give full access? y/n ";
     cin  >> Access ;

     if(toupper(Access) == 'Y')
        return   -1;

    cout << "\nDo you want to give access to :\n";

    cout << "\nShow Clients List? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pShowClient;

    cout << "\nAdd New Clients? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pAddClient;

    cout << "\nDelete Clients? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pDeleteClient;

    cout << "\nUpdate Clients? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pUpdateClient;

    cout << "\nFind Clients? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pFindClient;

    cout << "\nShow Transactions? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pTransactions;

    cout << "\nManage Users? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pManageUser;

    cout << "\nShow Login Register? y/n ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += clsUser::enPermissions::pShowLoginRegister;


    return PermissionsNumber;

}

static void _ReadUser(clsUser& User){

  cout << "\nEnter FirstName: ";
  User.SetFirstName(clsInputValidate::ReadString());

  cout << "\nEnter LastName: ";
  User.SetLastName(clsInputValidate::ReadString());

  cout << "\nEnter Email: ";
  User.SetEmail(clsInputValidate::ReadString());

  cout << "\nEnter Phone: ";
  User.SetPhone(clsInputValidate::ReadString());

  cout << "\nEnter PassWord: ";
  User.SetPassWord(clsInputValidate::ReadString());

  cout << "\nEnter Permissions: ";
  User.SetPermissions(_ReadPermissions());

 }

static void _PrintUser(clsUser NewUser){

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


 static void ShowAddNewUserScreen(){


     _DrawScreenHeader("Add New User Screen");

  cout << "\nPlease Enter UserName: ";
  string UserName = clsInputValidate::ReadString();

  while(clsUser::IsUserExist(UserName))
  {
      cout << "UserName is already exists, choose another one: ";
        UserName = clsInputValidate::ReadString();
  }

  clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

  _ReadUser(NewUser);

  cout << "\nAre you sure you want to add this user ?Y/N: ";
  char Answer = 'n';
  cin >> Answer;


  if(toupper(Answer) == 'Y')
  {


  clsUser::enSaveResults SaveResult;
  SaveResult = NewUser.Save();

 switch(SaveResult)
 {
 case clsUser::enSaveResults::svSucceeded:
     {
         cout << "\nUser Added  Successfully :-)" << endl;
         _PrintUser(NewUser);
         break;
     }

 case clsUser::enSaveResults::svFaildEmptyObject:
    {
          cout << "\nError User was not saved because i'ts Empty " << endl;
          break;
    }

 case clsUser::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError account was not saved because UserName is used" << endl;
        break;
    }

 }
  }

 }


};
