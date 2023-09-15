#pragma once
#include <iostream>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


class clsFindClientScreen : protected clsScreen
{
private:


static void _PrintClient(clsBankClient NewClient){

        cout << "\nClient Card" << endl;
        cout << "-----------------------------------" << endl;
        cout << "FirstName    : " << NewClient.FirstName() << endl;
        cout << "LastName     : " << NewClient.LastName() << endl;
        cout << "FullName     : " << NewClient.FullName() << endl;
        cout << "Email        : " << NewClient.Email() << endl;
        cout << "Phone        : " << NewClient.Phone() << endl;
        cout << "Acc.Number   : " << NewClient.AccountNumber() << endl;
        cout << "PassWord     : " << NewClient.PinCode() << endl;
        cout << "Balance      : " << NewClient.AccountBalance() << endl;
        cout << "-----------------------------------" << endl;

 }

public:


static void ShowFindClientScreen(){

     if(!CheckAccessRights(clsUser::enPermissions::pFindClient))
     {
         return; /// this will exit the function and it will not
     }


     _DrawScreenHeader("Find Client Screen");

  cout << "\nPlease Enter Account Number: ";
  string AccountNumber = clsInputValidate::ReadString();

  while(!clsBankClient::IsClientExist(AccountNumber))
  {
      cout << "Account number is not exists, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
  }

  clsBankClient Client = clsBankClient::Find(AccountNumber);


     if(!Client.IsEmpty())
     {
         cout << "\nClient found  :-)" << endl;
     }
     else
     {
         cout << "\ Client was not found. " << endl;
     }

     _PrintClient(Client);


 }





};
