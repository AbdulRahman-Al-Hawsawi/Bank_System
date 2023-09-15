#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsPerson.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode =0, UpdateMode =1, AddNewMode =2};

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float  _AccountBalance;
    bool   _MarkForDelete = false;



void _RegisterTransferLog(float Amount,clsBankClient DestinationClient, string UserName ){

   fstream MyFile;
   string  LineData = _PrepareTransferLogRecord(Amount,DestinationClient,UserName);

    MyFile.open("TransferLog", ios::out | ios::app);
    if(MyFile.is_open())
    {

         MyFile <<  LineData << endl;

        MyFile.close();

    }

}

string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName,string Seperator = "#//#"){

string LogRecord = "";

 LogRecord += clsDate::GetSystemDateTimeString() + Seperator;
 LogRecord += AccountNumber() + Seperator;
 LogRecord += DestinationClient.AccountNumber() + Seperator;
 LogRecord += to_string(Amount) + Seperator;
 LogRecord += to_string(AccountBalance()) + Seperator;
 LogRecord += to_string(DestinationClient.AccountBalance()) + Seperator;
 LogRecord += UserName;

 return LogRecord;

 }

static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#"){

        vector<string> vClient = clsString::Split(Line,Separator);

        return clsBankClient(enMode::UpdateMode,vClient[0],vClient[1],vClient[2],vClient[3],vClient[4],vClient[5],stod(vClient[6]));
    }

static string _ConvertClientObjectToLine(clsBankClient ClientData, string Seperator = "#//#"){

     string stClientRecord ="";
   stClientRecord += ClientData.FirstName()+ Seperator;
   stClientRecord += ClientData.LastName() + Seperator;
   stClientRecord += ClientData.Email() + Seperator;
   stClientRecord += ClientData.Phone() + Seperator;
   stClientRecord += ClientData.AccountNumber() + Seperator;
   stClientRecord += ClientData.PinCode() + Seperator;
   stClientRecord += to_string(ClientData.AccountBalance());

   return stClientRecord;
 }

static vector<clsBankClient> _LoadClientDataFromFile(){

    fstream MyFile;
    vector<clsBankClient> vClient;

    MyFile.open("Clients.txt", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

           clsBankClient Client = _ConvertLineToClientObject(LineData);
            vClient.push_back(Client);

             }
        MyFile.close();

    }
    return vClient;

}

void _SaveClientsDateToFile(vector<clsBankClient> sClient){

  fstream MyFile;
  MyFile.open("Clients.txt", ios::out );

  if(MyFile.is_open())
  {
      string DataLine = "";

         for(clsBankClient& C : sClient)
          {

             if(C.MarkForDelete() == false)
              {
                  /// we only write record that are not marked for delelte
                  DataLine =  _ConvertClientObjectToLine(C);
                  MyFile << DataLine  << endl;
              }

          }

      MyFile.close();
  }
}

void _AddDataLineToFile(string stDataLine){

  fstream MyFile;
  MyFile.open("Clients.txt", ios::out | ios::app );

  if(MyFile.is_open())
  {
      MyFile << stDataLine  << endl;

      MyFile.close();
  }
}

void _Update(){

   vector<clsBankClient> _vClient;
   _vClient = _LoadClientDataFromFile();

   for(clsBankClient& C : _vClient)
   {
       if(C.AccountNumber() == AccountNumber())
       {
           C = *this;
           break;
       }
   }

   _SaveClientsDateToFile(_vClient);

}

void _AddNew(){

    _AddDataLineToFile(_ConvertClientObjectToLine(*this));

}

static clsBankClient _GetEmptyClientObject(){

    return clsBankClient(enMode::EmptyMode,"","","","","","",0);
}

public:

    clsBankClient(enMode Mode,string FirstName,string LastName,string Email,string Phone,string AccountNumber,string PinCode,float AccountBalance)
    : clsPerson(FirstName,LastName,Email,Phone)
    {
        _Mode = Mode;
        _PinCode = PinCode;
        _AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;

    }

    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float  Amount;
        float  srcBalanceAfter;
        float  desBalanceAfter;
        string UserName;
    };


 static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line, string Seperator ="#//#"){

  stTransferLogRecord TransferLogRecord;
  vector<string> vData = clsString::Split(Line,Seperator);

  TransferLogRecord.DateTime          = vData[0];
  TransferLogRecord.SourceAccountNumber  = vData[1];
  TransferLogRecord.DestinationAccountNumber  = vData[2];
  TransferLogRecord.Amount            = stod(vData[3]);
  TransferLogRecord.srcBalanceAfter   = stod(vData[4]);
  TransferLogRecord.desBalanceAfter   = stod(vData[5]);
  TransferLogRecord.UserName          = vData[6];

  return TransferLogRecord;

  }


     bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkForDelete()
    {
        return _MarkForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string PinCode()
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float AccountBalance()
    {
        return _AccountBalance;
    }


   static clsBankClient Find(string AccountNumber){

    fstream MyFile;

    MyFile.open("Clients.txt", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {
                clsBankClient Client = _ConvertLineToClientObject(LineData);
                if(Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
             }
        MyFile.close();

    }
    return _GetEmptyClientObject();

}

   static clsBankClient Find(string AccountNumber,string PinCode){

    fstream MyFile;

    MyFile.open("Clients.txt", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {

                clsBankClient Client = _ConvertLineToClientObject(LineData);
                if(Client.AccountNumber() == AccountNumber && Client.PinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
             }
        MyFile.close();

    }
    return _GetEmptyClientObject();

}

bool Delete(){

    vector<clsBankClient> vClients = _LoadClientDataFromFile();

    for(clsBankClient& C : vClients)
    {
        if(C.AccountNumber() == _AccountNumber)
        {
            C._MarkForDelete = true;
            break;
        }
    }

    _SaveClientsDateToFile(vClients);

    *this = _GetEmptyClientObject();

    return true;
}

void Deposit(double Amount){

_AccountBalance += Amount;
  Save();

 }

bool Withdraw(double Amount){

  if(Amount > _AccountBalance)
  {
    return false;
  }
  else
  {
  _AccountBalance -= Amount;
  Save();
  return true;
  }

 }


enum enSaveResults{ svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

 enSaveResults Save(){

    switch(_Mode)
    {
    case  enMode::EmptyMode:
        {
            if(IsEmpty())
            {
              return enSaveResults::svFaildEmptyObject;
            }
        }

    case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }

    case enMode::AddNewMode:
        {
            /// this will add new record to file or database
            if(clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                 _AddNew();
                 ///we need to set the mode to update after add new
                 _Mode = enMode::UpdateMode;
                 return enSaveResults::svSucceeded;
            }

        }

    }
}

static bool IsClientExist(string AccountNumber){

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    return (!Client.IsEmpty());
}

static clsBankClient GetAddNewClinetObject(string AccountNumber){

 return clsBankClient(enMode::AddNewMode,"","","","",AccountNumber,"",0);

}

static vector<clsBankClient> GetClientList(){

    return _LoadClientDataFromFile();
}

static float GetTotalBalances(){

    vector<clsBankClient> vClients = _LoadClientDataFromFile();
    double TotalBalances = 0;

    for(clsBankClient& Client : vClients)
    {
        TotalBalances += Client.AccountBalance();
    }

    return TotalBalances;
}

bool Transfer(float Amount, clsBankClient& DestinationClient){

  if(Amount > AccountBalance())
  {
      return false;
  }
  else{

    Withdraw(Amount);
    DestinationClient.Deposit(Amount);
    _RegisterTransferLog(Amount,DestinationClient,CurrentUser.UserName());
    return true;
  }

}

static vector<stTransferLogRecord> GetTransferLogList(){

 fstream MyFile;
     vector<stTransferLogRecord> vTransferLogs;

    MyFile.open("TransferLog", ios::in); /// Read mode
    if(MyFile.is_open())
    {

        string LineData;

             while(getline(MyFile >> ws,LineData))
             {
                stTransferLogRecord TransferLog = _ConvertLineToTransferLogRecord(LineData);
                vTransferLogs.push_back(TransferLog);
             }

        MyFile.close();
        return vTransferLogs;

}
}


};
