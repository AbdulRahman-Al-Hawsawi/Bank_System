#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

private:


static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord Record)
{
    cout << "\t\t\t| "  << setw(21) << left << Record.DateTime;
    cout << "| "  << setw(10) << left <<  Record.SourceAccountNumber;
    cout << "| "  << setw(10) << left <<  Record.DestinationAccountNumber;
    cout << "| "  << setw(10) << left <<  Record.Amount;
    cout << "| "  << setw(10) << left <<  Record.srcBalanceAfter;
    cout << "| "  << setw(10) << left <<  Record.desBalanceAfter;
    cout << "| "  << setw(10) << left <<  Record.UserName;

}


public:

static void ShowTransferLogRegisterListScreen()
{


    vector<clsBankClient::stTransferLogRecord> vTransferLogRecords = clsBankClient::GetTransferLogList();

    string Title = "Transfer Log List Screen";
    string SubTitle = " (" + to_string(vTransferLogRecords.size()) + ") Log(s).";

    _DrawScreenHeader(Title,SubTitle);

    cout << "\n\t\t\t__________________________________________________________________________________________\n\n";
    cout << "\t\t\t| "  << left << setw(21) << "Date/Time";
    cout << "| "  << left << setw(10) << "s.Account";
    cout << "| "  << left << setw(10) << "d.Account";
    cout << "| "  << left << setw(10) << "Amount";
    cout << "| "  << left << setw(10) << "s.Balance";
    cout << "| "  << left << setw(10) << "d.Balance";
    cout << "| "  << left << setw(10) << "User";
    cout << "\n\t\t\t__________________________________________________________________________________________\n\n";

    if(vTransferLogRecords.size() == 0)
        cout << "\t\t\tThere is no any Transfer log In the system!";
    else
    for(clsBankClient::stTransferLogRecord& Record : vTransferLogRecords)
    {
    PrintTransferLogRecordLine(Record);
    cout << endl;

    }

    cout << "\n\t\t\t__________________________________________________________________________________________\n\n";


}

};


