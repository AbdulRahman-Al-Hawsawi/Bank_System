#pragma once
#include <iostream>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


class clsUpdateClientScreen : protected clsScreen
{

private:

static void _ReadClient(clsBankClient& Clinet)
 {

  cout << "\nEnter FirstName: ";
  Clinet.SetFirstName(clsInputValidate::ReadString());

  cout << "\nEnter LastName: ";
  Clinet.SetLastName(clsInputValidate::ReadString());

  cout << "\nEnter Email: ";
  Clinet.SetEmail(clsInputValidate::ReadString());

  cout << "\nEnter Phone: ";
  Clinet.SetPhone(clsInputValidate::ReadString());

  cout << "\nEnter PinCode: ";
  Clinet.SetPinCode(clsInputValidate::ReadString());

  cout << "\nEnter Account Balance: ";
  Clinet.SetAccountBalance(clsInputValidate::ReadNumber<float>());

 }

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

static void ShowUpdateClintScreen()
 {

      if(!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
     {
         return; /// this will exit the function and it will not
     }

     _DrawScreenHeader("Update Client Screen");

  cout << "\nPlease Enter Account Number: ";
  string AccountNumber = clsInputValidate::ReadString();

  while(!clsBankClient::IsClientExist(AccountNumber))
  {
      cout << "Account number not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
  }

  clsBankClient Client = clsBankClient::Find(AccountNumber);
  _PrintClient(Client);

  cout << "Are you sure you want to update this client? N/Y ";
  char Answer = 'n';
  cin >> Answer;


  if(Answer == 'y' || Answer == 'Y')
  {


  cout << "\n\nUpdate Client Info:" << endl;
  cout << "------------------------------------" << endl;

  _ReadClient(Client);
  clsBankClient::enSaveResults SaveResult;
   SaveResult = Client.Save();

 switch(SaveResult)
 {
 case clsBankClient::enSaveResults::svSucceeded:
     {
         cout << "\nAccount Update Successfully :-)" << endl;
         _PrintClient(Client);
         break;
     }

 case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
          cout << "\nError account was not saved because i'ts Empty " << endl;
          break;
    }

 }

 }

 }


};

