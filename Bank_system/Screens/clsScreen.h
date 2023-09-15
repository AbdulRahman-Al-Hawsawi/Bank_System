#pragma once
#include <iostream>
#include <ctime>
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/Global.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsDate.h"


class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title,string SubTitle = "")
    {
        cout << "\t\t\t-----------------------------------------------" << "\n";
        cout << "\t\t\t\t\t" << Title << "\n";
        if(SubTitle != "")
        {
            cout << "\t\t\t\t\t" << SubTitle << "\n";
        }
        cout << "\t\t\t-----------------------------------------------" << "\n";
        cout << "\n\t\t\tUser: " << CurrentUser.UserName() << "\n";
        cout <<"\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";


    }




    static bool CheckAccessRights (clsUser::enPermissions Permission){

    if(!CurrentUser.CheckAccessPermission(Permission))
    {

    cout << "\t\t\t======================================\n";
    cout << "\t\t\tAccess Denied! Contact Your Admin\n";
    cout << "\t\t\t======================================\n\n";
    return false;
    }
    else
    {
        return true;
    }

}
};
