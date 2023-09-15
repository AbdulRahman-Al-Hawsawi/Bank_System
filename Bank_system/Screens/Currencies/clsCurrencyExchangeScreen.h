#pragma once

#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Currencies/clsCurrenciesListScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Currencies/clsFindCurrencyScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Currencies/clsUpdateCurrencyRateScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Currencies/clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
    enum enCurrenciesMainMenuOptions{
         eCurrenciesList =1, eFindCurrency =2, eUpdateCurrencyRate =3, eCurrencyCalculator =4, eMainMenu =5};

    static void _GoBackToCurrenciesMenu(){

    cout << "\n\t\t\tPress any key to go to Main Menu...";
    system("pause>0");
    ShowCurrenciesMenu();
}

static short _ReadCurrenciesMainMenuOptions(){

    cout << "\t\t\tChose What do you want to do [1 to 5]? ";
    short Choice;

    Choice = clsInputValidate::ReadNumberBetween<short>(1,5,"\t\t\tEnter Number Between 1,5: ");
    return Choice;
}

static void _ShowCurrenciesListScreen(){

///cout << " Currencies List screen will be here \n";
    clsCurrenciesListScreen::ShowCurrenciesListScreen();

}

static void _ShowFindCurrencyScreen(){

///cout << "Find Currency Screen will be here\n";
    clsFindCurrencyScreen::ShowFindCurrencyScreen();

}

static void _ShowUpdateCurrencyRateScreen(){

///cout << "Update Currency screen will be here\n";
    clsUpdateCurrencyRateScrren::ShowUpdateCurrencyRateScreen();


}

static void _ShowCurrencyCalculatorScreen(){

///cout << "Currency Calculator Screen will be here\n";
     clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

}


static void _PerformCurrenciesMainMenuOptins(enCurrenciesMainMenuOptions Option){


switch(Option)
{
case enCurrenciesMainMenuOptions::eCurrenciesList:
    {
        system("cls");
        _ShowCurrenciesListScreen();
        _GoBackToCurrenciesMenu();
        break;
    }

case enCurrenciesMainMenuOptions::eFindCurrency:
    system("cls");
    _ShowFindCurrencyScreen();
    _GoBackToCurrenciesMenu();
    break;

case enCurrenciesMainMenuOptions::eUpdateCurrencyRate:
    system("cls");
    _ShowUpdateCurrencyRateScreen();
    _GoBackToCurrenciesMenu();
    break;

case enCurrenciesMainMenuOptions::eCurrencyCalculator:
    system("cls");
    _ShowCurrencyCalculatorScreen();
    _GoBackToCurrenciesMenu();
    break;

case enCurrenciesMainMenuOptions::eMainMenu:
  {
    /// do nothing here the main screen will handle it :-)
  }
}


}


public:

    static void  ShowCurrenciesMenu(){

    system("cls");
    _DrawScreenHeader("Currency Exchange Main Screen");

    cout <<  setw(27)  << left <<  "\t\t\t===============================================" << endl;
    cout <<  setw(27)  << left <<"\t\t\t\t\Currency  Exchange Menu" << endl;
    cout <<  setw(27)  << left << "\t\t\t===============================================" << endl;
    cout <<  setw(27)  << left << "\t\t\t\t[1] List Currencies." << endl;
    cout <<  setw(27)  << left << "\t\t\t\t[2] Find Currency." << endl;
    cout <<  setw(27)  << left << "\t\t\t\t[3] Update Rate." << endl;
    cout <<  setw(27)  << left << "\t\t\t\t[4] Currency Calculator." << endl;
    cout <<  setw(27)  << left << "\t\t\t\t[5] Main Menu." << endl;
    cout <<  setw(27)  << left << "\t\t\t===============================================" << endl;
    _PerformCurrenciesMainMenuOptins((enCurrenciesMainMenuOptions)_ReadCurrenciesMainMenuOptions());


 }
};
