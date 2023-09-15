#pragma once

#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

static void _PrintCurrencyCard(clsCurrency Currency,string Title){

    cout << Title << endl;
    cout << "_______________________\n\n";
    cout << "Country   : " << Currency.Country() << endl;;
    cout << "Code      : " << Currency.CurrencyCode() << endl;
    cout << "Name      : " << Currency.CurrencyName() << endl;
    cout << "Rate(1$)= : " << Currency.Rate() << endl;
    cout << "\n_______________________\n";


}

static clsCurrency _GetCurrency(string Message){

  cout << Message << endl;
  string CurrencyCode = "";

  CurrencyCode = clsInputValidate::ReadString();
  while(!clsCurrency::IsCurrencyExist(CurrencyCode))
  {
      cout << "Currency is not found, choose another one: ";
        CurrencyCode = clsInputValidate::ReadString();
  }

  clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
  return Currency;

}

static float _ReadAmount(){

    cout << "\nEnter Amount to Exchange: ";
    float Amount = 0;

    Amount = clsInputValidate::ReadNumber<float>();
    return Amount;

}

static void _PrintCalculationsResults(float Amount,clsCurrency Currency1 ,clsCurrency Currency2){


    _PrintCurrencyCard(Currency1,"\nConvert From: ");

    float AmountInUSD = Currency1.ConvertToUSD(Amount);

    cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD " << endl;


    if(Currency2.CurrencyCode() == "USD")
    {
        return;
    }

    cout << "\n\nConverting From USD To:\n";

    _PrintCurrencyCard(Currency2,"\nTo: ");

    float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount,Currency2);

    cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode()
     << endl;

}


public:

    static void ShowCurrencyCalculatorScreen(){

     char Continue = 'y';

    while(toupper(Continue)== 'Y')
    {

       system("cls");
      _DrawScreenHeader("Currency Calculator Screen");

      clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");
      clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");
      float Amount = _ReadAmount();

      _PrintCalculationsResults(Amount,Currency1,Currency2);

      cout << "\n\nDo you want to perform another calculation y/n ? ";
      cin >> Continue;

    }


    }

};
