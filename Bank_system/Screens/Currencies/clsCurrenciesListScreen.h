#pragma once

#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsCurrency.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
{
    cout << "\t\t| "  << setw(28) << left << Currency.Country();
    cout << "| "  << setw(6) << left << Currency.CurrencyCode();
    cout << "| "  << setw(40) << left << Currency.CurrencyName();
    cout << "| "  << setw(6) << left << Currency.Rate();
}

public:

static void ShowCurrenciesListScreen()
{


    vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

    string Title = "Currencies List Screen";
    string SubTitle = "(" + to_string(vCurrencies.size()) + ") Currency.";

    _DrawScreenHeader(Title,SubTitle);

    cout << "\n\t\t____________________________________________________________________________________________\n\n";
    cout << "\t\t| "  << left << setw(28) << "Country";
    cout << "| "  << left << setw(6) << "Code";
    cout << "| "  << left << setw(40) << "Name";
    cout << "| "  << left << setw(6) << "Rate/(1$)";
    cout << "\n\t\t____________________________________________________________________________________________\n";

    if(vCurrencies.size() == 0)
        cout << "\t\tNo Currencies Available In the system!";
    else
    for(clsCurrency& Currency : vCurrencies)
    {
    _PrintCurrencyRecordLine(Currency);
    cout << endl;

    }

    cout << "\n\n\t\t____________________________________________________________________________________________\n";
}



};
