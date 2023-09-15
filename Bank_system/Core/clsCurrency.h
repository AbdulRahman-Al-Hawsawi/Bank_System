#pragma once

#include <iostream>
#include <fstream>
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsString.h"

using namespace std;

class clsCurrency
{

private:
        enum enMode { EmptyMode =0, UpdateMode =1};

    enMode _Mode;
    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float  _Rate;

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#"){

        vector<string> vClient = clsString::Split(Line,Separator);

        return clsCurrency (enMode::UpdateMode,vClient[0],vClient[1],vClient[2],stod(vClient[3]));
    }

static string _ConvertCurrencyObjectToLine(clsCurrency CurrencyData, string Seperator = "#//#"){

     string stCurrencyRecord ="";

     stCurrencyRecord += CurrencyData.Country() + Seperator;
     stCurrencyRecord += CurrencyData.CurrencyCode() + Seperator;
     stCurrencyRecord += CurrencyData.CurrencyName() + Seperator;
     stCurrencyRecord +=to_string(CurrencyData.Rate()) + Seperator;

     return stCurrencyRecord;

 }


static clsCurrency _GetEmptyCurrencyObject(){

    return clsCurrency(enMode::EmptyMode,"","","",0);
}

void _SaveCurrencyDataToFile(vector<clsCurrency> sCurrency){

  fstream MyFile;
  MyFile.open("Currencies", ios::out );

  if(MyFile.is_open())
  {
      string DataLine = "";

         for(clsCurrency& C : sCurrency)
          {
                  DataLine =  _ConvertCurrencyObjectToLine(C);
                  MyFile << DataLine  << endl;
          }


      MyFile.close();
  }
}

static vector<clsCurrency> _LoadCurrencyDataFromFile(){

    fstream MyFile;
    vector<clsCurrency> vCurrency;

    MyFile.open("Currencies", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

           clsCurrency Currency = _ConvertLineToCurrencyObject(LineData);
            vCurrency.push_back(Currency);

             }
        MyFile.close();

    }
    return vCurrency;

}

void _Update(){

   vector<clsCurrency> _vCurrency;
   _vCurrency = _LoadCurrencyDataFromFile();

   for(clsCurrency& C : _vCurrency)
   {
       if(C.CurrencyCode() == CurrencyCode())
       {
           C = *this;
           break;
       }
   }

   _SaveCurrencyDataToFile(_vCurrency);

}



    public:

        clsCurrency(enMode Mode,string Country,string CurrencyCode, string CurrencyName,float Rate){

        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;

        }
        bool IsEmpty(){

        return (_Mode == enMode::EmptyMode);

        }

        string Country(){

        return _Country;

        }

        string CurrencyCode() {

        return _CurrencyCode;

        }

        string CurrencyName(){

        return _CurrencyName;

        }

        void UpdateRate(float Rate)
        {
            _Rate = Rate;
            _Update();

        }

        float Rate(){

        return _Rate;

        }

static clsCurrency FindByCode(string CurrencyCode){

    fstream MyFile;
    CurrencyCode = clsString::UpperAllString(CurrencyCode);

    MyFile.open("Currencies", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

                clsCurrency Currency = _ConvertLineToCurrencyObject(LineData);
                if(clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode )
                {
                    MyFile.close();
                    return Currency;
                }
             }
        MyFile.close();

    }
    return _GetEmptyCurrencyObject();

}

static clsCurrency FindByCountry(string Country){

    fstream MyFile;
    Country = clsString::UpperAllString(Country);

    MyFile.open("Currencies", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

                clsCurrency Currency = _ConvertLineToCurrencyObject(LineData);
                if(clsString::UpperAllString(Currency.Country()) == Country )
                {
                    MyFile.close();
                    return Currency;
                }
             }
        MyFile.close();

    }
    return _GetEmptyCurrencyObject();

}

static bool IsCurrencyExist(string CurrencyCode){

 clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
 return (!C1.IsEmpty());

}

static vector<clsCurrency> GetCurrenciesList(){

return _LoadCurrencyDataFromFile();

}

float ConvertToUSD(float Amount){

return (float)(Amount/ Rate());

}

float ConvertToOtherCurrency(float Amount,clsCurrency CurrencyTo){

 float AmountInUSD = ConvertToUSD(Amount);

 if(CurrencyTo.CurrencyCode() == "USD"){

    return AmountInUSD;
 }

 return (float)(AmountInUSD * CurrencyTo.Rate());

}

};
