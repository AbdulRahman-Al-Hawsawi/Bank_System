#pragma once
#include <iostream>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


using namespace std;

class clsAddNewClientScreen : protected clsScreen
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

  cout << "\nEnter PinCode ";
  Clinet.SetPinCode(clsInputValidate::ReadString());

  cout << "\nEnter Account Balance? ";
  Clinet.SetAccountBalance(clsInputValidate::ReadNumber<float>());

 }

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


 static void ShowAddNewClientScreen()
 {

     if(!CheckAccessRights(clsUser::enPermissions::pAddClient))
     {
         return; /// this will exit the function and it will not
     }

     _DrawScreenHeader("Add New Client Screen");

  cout << "\nPlease Enter Account Number: ";
  string AccountNumber = clsInputValidate::ReadString();

  while(clsBankClient::IsClientExist(AccountNumber))
  {
      cout << "Account number is already exists, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
  }

  clsBankClient NewClient = clsBankClient::GetAddNewClinetObject(AccountNumber);

  _ReadClient(NewClient);

  clsBankClient::enSaveResults SaveResult;
  SaveResult = NewClient.Save();

 switch(SaveResult)
 {
 case clsBankClient::enSaveResults::svSucceeded:
     {
         cout << "\nAccount Added  Successfully :-)" << endl;
         _PrintClient(NewClient);
         break;
     }

 case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
          cout << "\nError account was not saved because i'ts Empty " << endl;
          break;
    }

 case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError account was not saved because account number is used" << endl;
        break;
    }

 }

 }


};
