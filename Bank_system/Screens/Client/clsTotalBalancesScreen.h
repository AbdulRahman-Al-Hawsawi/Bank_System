#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsUtil.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"

class clsTotalBalancesScreen : protected clsScreen
{
private:



static void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "\t\t\t| " << left << setw(15) << Client.AccountNumber()
         << "| " << left << setw(25) << Client.FullName()
         << "| " << left << setw(15) << Client.AccountBalance() << endl;
}

public:

static void ShowTotalBalancesScreen()
{

    vector<clsBankClient> vClients = clsBankClient::GetClientList();
    string SubTitle = "Balance List (" + to_string(vClients.size()) + ") Client(s).";

    _DrawScreenHeader("Total Balances Screen",SubTitle);

    cout << "\t\t\t============================================================================\n";
    cout << "\t\t\t| " << left << setw(15) << "Account Number"
         << "| " << left << setw(25) << "Client Name"
         << "| " << left << setw(15) << "Balance" << endl;
    cout << "\t\t\t============================================================================\n";

         double TotalBalances = clsBankClient::GetTotalBalances();

         if(vClients.size() == 0)
         cout << "\t\t\tNo Clients Available in the system " << endl;
         else
         for(clsBankClient& C : vClients)
         {
             PrintClientRecordBalanceLine(C);
         }
    cout << "\t\t\t============================================================================\n";
         cout << "\t\t\t\t\t\tTotal Balances = " << TotalBalances  << endl;
         cout << "\t\t\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;
}



};
