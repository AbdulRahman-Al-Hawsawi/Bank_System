#pragma once

#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsCurrency.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsString.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:


static void _PrintCurrencyCard(clsCurrency Currency){

    cout << "\nCurrency Card.\n";
    cout << "_______________________\n\n";
    cout << "Country   : " << Currency.Country() << endl;;
    cout << "Code      : " << Currency.CurrencyCode() << endl;
    cout << "Name      : " << Currency.CurrencyName() << endl;
    cout << "Rate(1$)= : " << Currency.Rate() << endl;
    cout << "\n_______________________\n";


}

static void _ShowResult(clsCurrency Currency){

    if(!Currency.IsEmpty()){

        cout << "\nCurrency Found :-)\n";
        _PrintCurrencyCard(Currency);
    }
    else{

        cout <<  "\nCurrency is Not Found :-(\n";
    }
}


public:

    static void ShowFindCurrencyScreen(){

        _DrawScreenHeader("Find Currency Screen");

    cout << "Find By: [1] Code or [2] Country ? ";
    short Answer = 1;
    cin >> Answer;

    if(Answer == 1){

     string CurrencyCode;
     cout << "\nPlease Enter Currency Code: ";
     CurrencyCode = clsInputValidate::ReadString();
     clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
     _ShowResult(Currency);

    }
    else{

    string Country;
    cout << "\nPlease Enter Country Name: ";
    Country = clsInputValidate::ReadString();
    clsCurrency Currency = clsCurrency::FindByCountry(Country);
    _ShowResult(Currency);


    }

    }
};
