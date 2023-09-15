#pragma once

#include <iostream>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/InterfaceCommunication.h"

using namespace std;

class clsPerson : public InterfaceCommunication
{

private:

    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    /// property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    /// property get
    string FirstName()
    {
        return _FirstName;
    }

    /// property Set
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    /// property get
    string LastName()
    {
        return _LastName;
    }

    ///property get
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    /// property Set
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    /// property get
    string Email()
    {
        return _Email;
    }

    /// property Set
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    /// property get
    string Phone()
    {
        return _Phone;
    }


    void SendEmail(string Title, string Body){


    }

    void SendFax(string Title, string Body){


    }

    void SendSMS(string Title, string Body){


    }
};
