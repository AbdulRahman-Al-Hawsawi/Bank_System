#pragma once
#include <iostream>
#include "clsPerson.h"


class clsEmployee : public clsPerson
{
private:

    string _Title;
    string _Department;
    float  _Salary;

public:

    clsEmployee(short ID,string FirstName,string LastName,string Email,string Phone,string Title, string Department,float Salary) : clsPerson(ID,FirstName,LastName,Email,Phone)
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string Title()
    {
        return _Title;
    }

    void setDepartment(string Department)
    {
        _Department = Department;
    }

    string Department()
    {
        return _Department;
    }

    void setSalary(float Salary)
    {
       _Salary = Salary;
    }

    float Salary()
    {
        return _Salary;
    }

    void Print()
    {
        cout << "\nInfo" << endl;
        cout << "-----------------------------------" << endl;
        cout << "ID           : " << ID() << endl;
        cout << "FirstName    : " << FirstName() << endl;
        cout << "LastName     : " << LastName() << endl;
        cout << "FullName     : " << FullName() << endl;
        cout << "Title        : " << _Title << endl;
        cout << "Department   : " << _Department << endl;
        cout << "Salary       : " << _Salary << endl;
        cout << "Email        : " << Email() << endl;
        cout << "Phone        : " << Phone() << endl;
        cout << "-----------------------------------" << endl;

    }

};
