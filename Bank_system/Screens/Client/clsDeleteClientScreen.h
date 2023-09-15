#pragma once
#include <iostream>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


class clsDeleteClientScreen : protected clsScreen
{

private:


static void _PrintClient(clsBankClient Client){

        cout << "\nClient Card" << endl;
        cout << "-----------------------------------" << endl;
        cout << "FirstName    : " << Client.FirstName() << endl;
        cout << "LastName     : " << Client.LastName() << endl;
        cout << "FullName     : " << Client.FullName() << endl;
        cout << "Email        : " << Client.Email() << endl;
        cout << "Phone        : " << Client.Phone() << endl;
        cout << "Acc.Number   : " << Client.AccountNumber() << endl;
        cout << "PassWord     : " << Client.PinCode() << endl;
        cout << "Balance      : " << Client.AccountBalance() << endl;
        cout << "-----------------------------------" << endl;

 }


 public:

static void ShowDeleteClientScreen()
 {

      if(!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
     {
         return; /// this will exit the function and it will not
     }

     _DrawScreenHeader("Delete Client Screen");

  cout << "\nPlease Enter Account Number: ";
  string AccountNumber = clsInputValidate::ReadString();

  while(!clsBankClient::IsClientExist(AccountNumber))
  {
      cout << "Account number is not exists, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
  }

  clsBankClient Client = clsBankClient::Find(AccountNumber);

 _PrintClient(Client);

  cout << "Are you sure you want to delete this client? N/Y ";

  char Answer = 'n';
  cin >> Answer;


 if(Answer == 'y' || Answer == 'Y')
 {

     if(Client.Delete())
     {
         cout << "\nClient Delete Successfully :-)" << endl;
         _PrintClient(Client);
     }
     else
     {
         cout << "\nError Client was not deleted. " << endl;
     }

 }

 }


};

