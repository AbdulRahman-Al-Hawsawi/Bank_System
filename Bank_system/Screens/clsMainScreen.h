#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsString.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsClientListScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsAddNewClientScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsDeleteClientScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsUpdateClientScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsFindClientScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsTransactionScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsManageUsersScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/Global.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsLoginScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsLoginRegisterScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Currencies/clsCurrencyExchangeScreen.h"



class clsMainScreen : protected clsScreen
{
private:

enum enMainMenuOptions{

    eClientList =1 , eAddClient =2, eDeleteClient =3,eUpdateClient =4,eFindClient =5,
    eShowTransactionMenu = 6, eManageUser =7, eRegesterLogin =8, eCurrencyExchange = 9,eLogOut =10
};

static void _GoToBackMainMenu(){

    cout << "\n\t\t\tPress any key to go to Main Menu...";
    system("pause>0");
    ShowMainMenu();
}

static short _ReadMainMenuOption(){

    cout << "\t\t\tChose What do you want to do [1 to 10]? ";
    short Choice;
    Choice = clsInputValidate::ReadNumberBetween(1,10,"\t\t\tEnter Number Between 1,10: ");
    return Choice;
}

static void _ShowClientListScreen(){

  ///  cout << "Show Client List Screen will be here" << endl;
  clsClientListScreen::ShowClientsListScreen();

}

static void _ShowAddClientScreen(){

///cout << "Add Client Screen will be here" << endl;
    clsAddNewClientScreen::ShowAddNewClientScreen();

}

static void _ShowDeleteClientScreen(){

///cout << "Delete Client Screen will be here" << endl;
        clsDeleteClientScreen::ShowDeleteClientScreen();

}

static void _ShowUpdateClientScreen(){

///cout << "Update Client Screen will be here" << endl;
        clsUpdateClientScreen::ShowUpdateClintScreen();

}

static void _ShowFindClientScreen(){

///cout << "Find Client screen will be here" << endl;
        clsFindClientScreen::ShowFindClientScreen();

}

static void _ShowTransactionMenu(){

///cout << "Transactions Screen will be here " << endl;
        clsTrasactionScreen::ShowTransactionMenu();

}

static void _ShowManageMenuScreen(){

///cout << "Manage Screen will be here" << endl;
        clsManageUsersScreen::ShowManageMenuScreen();

}

static void _ShowRegisterLoginScreen(){

    clsLoginRegisterScreen::ShowLoginRegisterListScreen();

}

static void _ShowCurrencyExchangeScreen(){

///cout << "Currency Exchange Menu will be here\n";
    clsCurrencyExchangeMainScreen::ShowCurrenciesMenu();

}

static void _Logout(){

CurrentUser = clsUser::Find("","");


/// then it will go back to main function

}

static void _PerformeMainMenuOption(enMainMenuOptions MainMenuOption){

    switch(MainMenuOption)
    {
    case enMainMenuOptions::eClientList:
    {
        system("cls");
        _ShowClientListScreen();
        _GoToBackMainMenu();
        break;
    }
    case enMainMenuOptions::eAddClient:

        system("cls");
        _ShowAddClientScreen();
        _GoToBackMainMenu();
        break;

    case enMainMenuOptions::eDeleteClient:

        system("cls");
        _ShowDeleteClientScreen();
        _GoToBackMainMenu();
        break;

    case enMainMenuOptions::eUpdateClient:

        system("cls");
        _ShowUpdateClientScreen();
        _GoToBackMainMenu();
        break;

    case enMainMenuOptions::eFindClient:

        system("cls");
        _ShowFindClientScreen();
        _GoToBackMainMenu();
        break;

    case enMainMenuOptions::eShowTransactionMenu:

        system("cls");
        _ShowTransactionMenu();
        _GoToBackMainMenu();
        break;

    case enMainMenuOptions::eManageUser:

        system("cls");
        _ShowManageMenuScreen();
        _GoToBackMainMenu();
        break;

    case enMainMenuOptions::eRegesterLogin:
        system("cls");
        _ShowRegisterLoginScreen();
        _GoToBackMainMenu();

    case enMainMenuOptions::eCurrencyExchange:
        system("cls");
        _ShowCurrencyExchangeScreen();
        _GoToBackMainMenu();

    case enMainMenuOptions::eLogOut:
        system("cls");
        _Logout();
        break;

    }
}


public:


static void ShowMainMenu(){


  system("cls");
 _DrawScreenHeader("Main Screen");

 cout <<  setw(27)  << left <<  "\t\t\t===============================================" << endl;
 cout <<  setw(27)  << left <<"\t\t\t\t\tMain Menue Screen" << endl;
 cout <<  setw(27)  << left << "\t\t\t===============================================" << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[1] Show Client List." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[2] Add New Client." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[3] Delete Client." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[4] Update Client Info." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[5] Find Client." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[6] Transaction." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[7] Manage User." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[8] Login Register." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[9] Currency Exchange." << endl;
 cout <<  setw(27)  << left << "\t\t\t\t[10] Exit." << endl;
 cout <<  setw(27)  << left << "\t\t\t===============================================" << endl;
 _PerformeMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());

}
};
