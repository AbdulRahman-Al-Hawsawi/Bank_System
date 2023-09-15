#pragma once

#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsCurrency.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRateScrren : protected clsScreen
{
private:


static float _ReadRate(){

   cout << "\nEnter New Rate: ";
   float NewRate = 0;

   NewRate = clsInputValidate::ReadNumber<float>();
   return NewRate;

}

static void _PrintCurrencyCard(clsCurrency Currency){

    cout << "\nCurrency Card.\n";
    cout << "_______________________\n\n";
    cout << "Country   : " << Currency.Country() << endl;;
    cout << "Code      : " << Currency.CurrencyCode() << endl;
    cout << "Name      : " << Currency.CurrencyName() << endl;
    cout << "Rate(1$)= : " << Currency.Rate() << endl;
    cout << "\n_______________________\n";


}


public:


static void ShowUpdateCurrencyRateScreen(){

  _DrawScreenHeader("Update Currency Rate");


  string CurrencyCode = "";

  cout << "Please Enter Currency Code: ";
  CurrencyCode = clsInputValidate::ReadString();

  while(!clsCurrency::IsCurrencyExist(CurrencyCode))
  {
      cout << "Currency code is not exists, choose another one: ";
        CurrencyCode = clsInputValidate::ReadString();
  }

  clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
  _PrintCurrencyCard(Currency);

   cout << "\nAre you sure you want to update Rate Y/N ";

   char Answer = 'n';
   cin >> Answer;


      if(toupper(Answer) == 'Y'){


        cout << "\nUpdate Currency Rate:\n";
        cout << "____________________________\n\n";

        Currency.UpdateRate(_ReadRate());

        cout << "\nUpdate Successfully\n";
        _PrintCurrencyCard(Currency);

         }
  }


};
