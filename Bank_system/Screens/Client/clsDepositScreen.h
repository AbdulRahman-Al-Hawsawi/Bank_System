#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"


class clsDepositScreen : protected clsScreen
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

static string _ReadAccountNumber()
{
   return clsInputValidate::ReadString();
}


public:

 static void ShowDepositScreen()
 {

     _DrawScreenHeader("Deposit Screen");

  cout << "\nPlease Enter Account Number: ";
  string AccountNumber = _ReadAccountNumber();

  while(!clsBankClient::IsClientExist(AccountNumber))
  {
      cout << "Account number is not exists, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
  }

  clsBankClient Client = clsBankClient::Find(AccountNumber);

  _PrintClient(Client);

  cout << "Enter deposit amount: ";
  double Amount;
  Amount = clsInputValidate::ReadNumber<double>();

  cout << "Are you sure you want to perform this transaction? N/Y ";

  char Answer = 'n';
  cin >> Answer;



     if(Answer == 'y' || Answer == 'Y')
     {
         Client.Deposit(Amount);
         cout << "\nAmount Deposit Successfully :-)\n";
         cout << "New balance is : " << Client.AccountBalance() << endl;
     }
     else
     {
         cout << "\nOperation was Canceled.\n";
     }

 }




};
