#pragma once

#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsDepositScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsWithdrawScreen.h"

class clsTransferScreen : protected clsScreen
{

private:

static string _ReadAccountNumber(string Message){

 cout << Message;
  string AccountNumber = clsInputValidate::ReadString();

  while(!clsBankClient::IsClientExist(AccountNumber))
  {
      cout << "Account number is not exists, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
  }

  return AccountNumber;
}

static float _ReadAmount(clsBankClient SourceClient){

 cout << "\nEnter Transfer Amount? ";
  float Amount;
  cin >> Amount;

 while(SourceClient.AccountBalance() < Amount)
 {
     cout << "Amount Exceeds the available Balance, Enter another Amount? ";
     cin >> Amount;
 }

 return Amount;

}



static void _PrintClient(clsBankClient Client){

        cout << "\nClient Card\n";
        cout << "-----------------------------------\n" ;
        cout << "FullName     : " << Client.FullName() << "\n";
        cout << "Acc.Number   : " << Client.AccountNumber() << "\n";
        cout << "Balance      : " << Client.AccountBalance() << "\n";
        cout << "-----------------------------------" << endl;

 }

public:

static void ShowTransferScreen(){

 _DrawScreenHeader("Transfer Screen ");

  clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to transfer from: "));

  _PrintClient(SourceClient);

  clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to transfer to: "));

  _PrintClient(DestinationClient);

  float Amount = _ReadAmount(SourceClient);

 cout << "\nAre you sure you want to perform this operation? y/n ";
 char Answer;
 cin >> Answer;

 if(toupper(Answer) == 'Y')
 {

 if(SourceClient.Transfer(Amount,DestinationClient)){

  cout << "\nTransfer done Successfully \n";
  _PrintClient(SourceClient);
  _PrintClient(DestinationClient);

 }

 else{

    cout << "\nTransfer Field \n";
 }


}



}

};
