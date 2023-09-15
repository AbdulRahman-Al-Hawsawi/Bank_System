#pragma once
#include <iostream>
#include <string>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsUser.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsMainScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/Global.h"


class clsLoginScreen : protected clsScreen
{
private:


static bool _Login(){

    bool _LoginFaild = false;
    short _FaildLoginCount =0;
    string _UserName = "", _Password = "";

    do{


    if(_LoginFaild)
    {
        _FaildLoginCount++;
        cout << "\nInvalid UserName/Password\n";
        cout << "You have " << (3-_FaildLoginCount) << " Trial(s) to login.\n";
    }

    if(_FaildLoginCount == 3 )
    {
        cout << "\nYou are Locked after 3 failed trails\n";
        return false;
    }

    cout << "\nEnter User Name? ";
    cin >> _UserName;
    cout << "Enter Password? ";
    cin >> _Password;

    CurrentUser = clsUser::Find(_UserName,_Password);

    _LoginFaild = CurrentUser.IsEmpty();

    }while(_LoginFaild);

     CurrentUser.RegisterLogIn();
     clsMainScreen::ShowMainMenu();
     return true;

}


public:


    static bool ShowLoginScreen(){

        system("cls");
        _DrawScreenHeader("Login Screen");
       return _Login();

    }
};
