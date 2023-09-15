#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"


class clsLoginRegisterScreen : protected clsScreen
{

private:


static void PrintLoginRecordRecordLine(clsUser::stLoginRegisterRecord Record)
{
    cout << "\t\t\t| "  << setw(25) << left << Record.DateTime;
    cout << "| "  << setw(20) << left <<  Record.UserName;
    cout << "| "  << setw(10) << left <<  Record.PassWord;
    cout << "| "  << setw(10) << left <<  Record.Permissions;
}

public:

static void ShowLoginRegisterListScreen()
{

    if(!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
     {
         return; /// this will exit the function and it will not
     }


    vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

    string Title = "Login Register List Screen";
    string SubTitle = "Login List (" + to_string(vLoginRegisterRecord.size()) + ") Login(s).";

    _DrawScreenHeader(Title,SubTitle);

    cout << "\n\t\t\t_______________________________________________________________________________\n\n";
    cout << "\t\t\t| "  << left << setw(25) << "Date/Time";
    cout << "| "  << left << setw(20) << "UserName";
    cout << "| "  << left << setw(10) << "PassWord";
    cout << "| "  << left << setw(10) << "Permission";
    cout << "\n\t\t\t_______________________________________________________________________________\n";

    if(vLoginRegisterRecord.size() == 0)
        cout << "\t\t\tThere is no any login In the system!";
    else
    for(clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
    {
    PrintLoginRecordRecordLine(Record);
    cout << endl;

    }

    cout << "\n\n\t\t\t_______________________________________________________________________________\n";
}




};

