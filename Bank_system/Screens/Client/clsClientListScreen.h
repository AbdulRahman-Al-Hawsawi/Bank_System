#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsMainScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsBankClient.h"


class clsClientListScreen : protected clsScreen
{

 private:

static void PrintClientRecordLine(clsBankClient Clients)
{
    cout << "\t\t\t| "  << setw(15) << left << Clients.AccountNumber();
    cout << "| "  << setw(10) << left << Clients.PinCode();
    cout << "| "  << setw(25) << left << Clients.FullName();
    cout << "| "  << setw(10) << left << Clients.Phone();
    cout << "| "  << setw(12) << left << Clients.AccountBalance();
}

public:

static void ShowClientsListScreen()
{

     if(!CheckAccessRights(clsUser::enPermissions::pShowClient))
     {
         return; /// this will exit the function and it will not
     }

    vector<clsBankClient> vClients = clsBankClient::GetClientList();

    string Title = "Client List Screen";
    string SubTitle = "Client List (" + to_string(vClients.size()) + ") Client(s).";

    _DrawScreenHeader(Title,SubTitle);

    cout << "\n\t\t\t_______________________________________________________________________________\n\n";
    cout << "\t\t\t| "  << left << setw(15) << "Account Number";
    cout << "| "  << left << setw(10) << "Pin Code";
    cout << "| "  << left << setw(25) << "Client Name";
    cout << "| "  << left << setw(10) << "Phone";
    cout << "| "  << left  << setw(12) << "Balance";
    cout << "\n\t\t\t_______________________________________________________________________________\n";

    if(vClients.size() == 0)
        cout << "\t\t\tNo Client Available In the system!";
    else
    for(clsBankClient& Client : vClients)
    {
    PrintClientRecordLine(Client);
    cout << endl;

    }

    cout << "\n\n\t\t\t_______________________________________________________________________________\n";
}


};
