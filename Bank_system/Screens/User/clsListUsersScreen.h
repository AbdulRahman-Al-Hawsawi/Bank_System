#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"

class clsListUsersScreen : protected clsScreen
{

private:


static void _PrintUserData(clsUser User)
{
    cout << "\t\t|" << left << setw(15) << User.UserName();
    cout << "|" << left << setw(23) << User.FullName();
    cout << "|" << left << setw(10) << User.Phone();
    cout << "|" << left << setw(15) << User.Email();
    cout << "|" << left << setw(12) << User.PassWord();
    cout << "|" << left << setw(15) << User.Permissions() << endl;
}

public:

static void ShowListUsersScreen()
{
     vector<clsUser> vUsers = clsUser::GetUsersList();

     string Title = " Users List Screen";
     string SubTitle = "(" + to_string(vUsers.size()) + ") User(s).";

     _DrawScreenHeader(Title,SubTitle);
    cout << "\t\t============================================================================================\n";
    cout << "\t\t|" << left << setw(15) << "User Name ";
    cout << "|" << left << setw(23) << "Full Name";
    cout << "|" << left << setw(10) << "Phone ";
    cout << "|" << left << setw(15) << "Email ";
    cout << "|" << left << setw(12) << "PassWord ";
    cout << "|" << left << setw(15) << "Permissions " << endl;
    cout << "\t\t============================================================================================\n";

    if(vUsers.size() == 0)
        cout << "There is no Users in the system!\n";
    else
    for(clsUser& U : vUsers)
    {
        _PrintUserData(U);
    }

    cout << "\t\t============================================================================================\n";

}



};
