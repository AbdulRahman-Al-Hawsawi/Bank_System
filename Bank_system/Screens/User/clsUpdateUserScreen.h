#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{
private:


enum enMainMenuPermissions
{
    pShowClient =1, pAddClient =2, pDeleteClient =4, pUpdateClient =8, pFindClient =16,
    pTransactions =32, pManageUser =64
};

static short _ReadPermissions(){

    char Access = 'N';
    short PermissionsNumber =0;

    cout << "\nDo you want to give full access? ";
     cin  >> Access ;

     if(toupper(Access) == 'Y')
        return   -1;

    cout << "\nDo you want to give access to :\n";

    cout << "\nShow Clients List? ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += enMainMenuPermissions::pShowClient;

    cout << "\nAdd New Clients? ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += enMainMenuPermissions::pAddClient;

    cout << "\nDelete Clients? ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += enMainMenuPermissions::pDeleteClient;

    cout << "\nUpdate Clients? ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += enMainMenuPermissions::pUpdateClient;

    cout << "\nFind Clients? ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += enMainMenuPermissions::pFindClient;

    cout << "\nShow Transactions? ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += enMainMenuPermissions::pTransactions;

    cout << "\nManage Users? ";
    cin >> Access;
    if(toupper(Access) == 'Y')
    PermissionsNumber += enMainMenuPermissions::pManageUser;


    return PermissionsNumber;

}

static void _ReadUserInfo(clsUser& User){

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


 static void ShowUpdateUserScreen(){


     _DrawScreenHeader("Update User Screen");

  cout << "\nPlease Enter UserName: ";
  string UserName = clsInputValidate::ReadString();

  while(!clsUser::IsUserExist(UserName))
  {
      cout << "UserName is not exists, choose another one: ";
        UserName = clsInputValidate::ReadString();
  }

  clsUser User = clsUser::Find(UserName);

  _PrintUserInfo(User);


  cout << "\nAre you sure you want to update this user ?Y/N: ";
  char Answer = 'n';
  cin >> Answer;


  if(toupper(Answer) == 'Y')
  {

      cout  << "\nUpdate User Info\n";

      _ReadUserInfo(User);

  clsUser::enSaveResults SaveResult;
  SaveResult = User.Save();

 switch(SaveResult)
 {
 case clsUser::enSaveResults::svSucceeded:
     {
         cout << "\nUser Update Successfully :-)" << endl;
         _PrintUserInfo(User);
         break;
     }

 case clsUser::enSaveResults::svFaildEmptyObject:
    {
          cout << "\nError User was not saved because i'ts Empty " << endl;
          break;
    }

 case clsUser::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError User was not saved because UserName is used" << endl;
        break;
    }

 }
  }

 }
};
