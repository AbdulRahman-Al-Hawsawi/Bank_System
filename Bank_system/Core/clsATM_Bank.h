#pragma once

#include <iostream>
#include "clsBankClient.h"

using namespace std;

class clsATM_Bank : private clsBankClient
{
private:


struct stClientData
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
    bool MarkToDelete = false;
    bool MarkToStop = false;
    string DateOfOpenAccount ="";
};


stClientData CurrentClient;

vector<string> SplitString(string S1, string Delimiter)
{
    vector<string> vString;
    short Pos =0;
    string sWord;

    while((Pos = S1.find(Delimiter)) != std::string::npos)
    {
        sWord = S1.substr(0,Pos);
        if(sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0,Pos + Delimiter.length());
    }

    if(S1 != "")
    {
        vString.push_back(S1); /// it add last word if the string.
    }
    return vString;
}

static string _ConvertRecordToLine(stClientData ClientData, string Seperator = "#//#")
 {
     string stClientRecord ="";

   stClientRecord += ClientData.AccountNumber + Seperator;
   stClientRecord += ClientData.PinCode + Seperator;
   stClientRecord += ClientData.Name + Seperator;
   stClientRecord += ClientData.Phone+ Seperator;
   stClientRecord += to_string(ClientData.AccountBalance) + Seperator;
   stClientRecord += ClientData.DateOfOpenAccount;

   return stClientRecord;
 }

 stClientData _ConvertLineToRecord(string Line , string Seperator = "#//#")
 {
     stClientData Client;
     vector<string> vClientData  = SplitString(Line,Seperator);

         Client.AccountNumber = vClientData[0];
         Client.PinCode = vClientData[1];
         Client.Name = vClientData[2];
         Client.Phone = vClientData[3];
         Client.AccountBalance =stod(vClientData[4]);//cast string to double
         Client.DateOfOpenAccount = vClientData[5];

     return Client;
 }

vector<stClientData> _LoadClientLineDataFromFile(string FileName)
{
    fstream MyFile;
    vector<stClientData> vClient;

    MyFile.open(FileName, ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData = "";
        stClientData Client;

             while(getline(MyFile >> ws,LineData))
             {

            Client = ConvertLineToRecord(LineData);
            vClient.push_back(Client);

             }
        MyFile.close();

    }
    return vClient;

}







bool DepositToClientByAccountNumber(string AccountNumber , double Amount , vector<stClientData> vClients)
{
           char Answer = 'n';

           cout << "\nAre you sure you want perform this transaction? Y/N? ";
           cin >> Answer;
           if(toupper(Answer) == 'Y')
           {
               for(stClientData& C : vClients)
               {
                   if(C.AccountNumber == AccountNumber)
                   {
                       C.AccountBalance += Amount;
               SaveDataLineToFile(ClientsFileName,vClients);
cout << "\nDone successfully new balance is: " << C.AccountBalance << endl;
                       return true;
                   }
               }
           }
           return false;
}

short ReadQuickWithdrawAmount()
{
    short Option ;
    while(Option < 1 || Option > 9)
    {
        cout << "Choice what to do [1 to 9] ";
        cin >> Option;
    }
    return Option;
}

short GetQuickWithdrawAmount(short Choice)
{
    switch(Choice)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 300;
    case 6:
        return 400;
    case 7:
        return 600;
    case 8:
        return 1000;
    default:
        return 0;
    }
}

void PerformeQuickWithdrawOption(short QuickWithdrawOption)
{
    if(QuickWithdrawOption == 9)
        return;

 /// Validate that the amount does not exceeds the balance
 short WithdrawBalance =  GetQuickWithdrawAmount(QuickWithdrawOption);

    if(WithdrawBalance > CurrentClient.AccountBalance)
     {
       cout <<"\nAmount Exceeds the balance, you can withdraw up to : " << CurrentClient.AccountBalance << endl;
       cout << "Press any key to continue...";
       system("pause>0");
       ShowQuickWithdrawScreen();

     }

   stClientData Client;
   vector<stClientData> vClients = LoadClientLineDataFromFile(ClientsFileName);
   DepositToClientByAccountNumber(CurrentClient.AccountNumber,WithdrawBalance * -1,vClients);
   CurrentClient.AccountBalance -= WithdrawBalance;
}

void ShowQuickWithdrawScreen()
{
     system("cls");
    cout << "========================================\n";
    cout << "\t Quick Withdraw Screen\n";
    cout << "========================================\n";
    cout << "\t[1] 20\t\t[2] 50" << endl;
    cout << "\t[3] 100\t\t[4] 200" << endl;
    cout << "\t[5] 400\t\t[6] 600" << endl;
    cout << "\t[7] 900\t\t[8] 1000" << endl;
    cout << "\t[9] Exit" << endl;
    cout << "========================================\n";

    PerformeQuickWithdrawOption(GetQuickWithdrawAmount(ReadQuickWithdrawAmount()));
}

double ReadWithdraw()
{
    int Amount;

    cout << "Enter an Amount Multiple of 5's ? ";
    cin >> Amount;

    while(Amount % 5 != 0)
    {
        cout << "Enter an Amount Multiple of 5's ? ";
        cin >> Amount;
    }

    return Amount;
}

void PerformeNormalWithdrawOption()
{

 /// Validate that the amount does not exceeds the balance
 double WithdrawAmount = ReadWithdraw() ;

    if(WithdrawAmount > CurrentClient.AccountBalance)
     {
       cout <<"\nAmount Exceeds the balance, you can withdraw up to : " << CurrentClient.AccountBalance << endl;
       cout << "Press any key to continue...";
       system("pause>0");
       ShowNormalWithdrawScreen();
     }

  stClientData Client;
  vector<stClientData> vClients = LoadClientLineDataFromFile(ClientsFileName);
  DepositToClientByAccountNumber(CurrentClient.AccountNumber,WithdrawAmount * -1,vClients);
  CurrentClient.AccountBalance -= WithdrawAmount;

}



double ReadDepositAmount()
{
    double Amount;
    cout << "\nEnter a positive Amount? ";
    cin >> Amount;

    while(Amount <= 0)
    {
     cout << "\nEnter a positive Amount? ";
     cin >> Amount;
    }
    return Amount;
}

void PerformeDepositOption()
{

     double DepositAmount = ReadDepositAmount();

   clsBankClient Client;
   clsBankClient::
   vector<clsBankClient> vClients = GetClientList()LoadClientLineDataFromFile(ClientsFileName);
   DepositToClientByAccountNumber(CurrentClient.AccountNumber,DepositAmount,vClients);
   CurrentClient.AccountBalance += DepositAmount;

}


static bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, clsBankClient& Client)
{

    clsBankClient Client =  Find(AccountNumber,PinCode);

        if(Client.IsEmpty())
        {
            return false;
        }

        return true;
}



};
