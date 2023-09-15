#pragma once
#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsListUsersScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsAddNewUserScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsDeleteUserScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsUpdateUserScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsFindUserScreen.h"

class clsManageUsersScreen  : protected clsScreen
{

private:


enum enManageUsersMenuOptions{

    eUsersList =1, eAddUsers =2, eDeleteUsers =3, eUpdateUsers =4,
    eFindUsers =5, eMainMenu =6
};

static void _GoToBackManageMenu(){

    cout << "\nPress any key to go to Main Menu...";
    system("pause>0");
    ShowManageMenuScreen();
}

static short _ReadManageUsersMenuOption(){

    cout << "\t\t\tWhat do you want to do [1 to 6]? ";
    short Choice;
    Choice = clsInputValidate::ReadNumberBetween(1,6,"Invalid Number, Enter Number between 1,6");
    return Choice;
}

static void _ShowListUsersScreen(){

   /// cout << "Users list will be here\n";
        clsListUsersScreen::ShowListUsersScreen();

}

static void _ShowAddUsersScreen(){

   /// cout << "Add users Screen will be here\n";
        clsAddNweUserScreen::ShowAddNewUserScreen();

}

static void _ShowDeleteUsersScreen(){

///cout << "Delete users Screen will be here\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();

}

static void _ShowUpdateUserScreen(){

///cout << "Update users screen will be here\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();

}

static void _ShowFindUserScreen(){

///cout << "Find users Screen will be here\n";
        clsFindUserScreen::ShowFindUserScreen();

}

static void _PerformManageUsersMenu(enManageUsersMenuOptions ManageUsersOption){


    switch(ManageUsersOption)
    {
        case enManageUsersMenuOptions::eUsersList:
        {
           /// CheckPermission(CurrentUser.Permissions,enPermissions::enShowUsers);
            system("cls");
            _ShowListUsersScreen();
            _GoToBackManageMenu();
            break;
        }
        case enManageUsersMenuOptions::eAddUsers:
           /// CheckPermission(CurrentUser.Permissions,enPermissions::enAddUser);
            system("cls");
            _ShowAddUsersScreen();
            _GoToBackManageMenu();
            break;

        case enManageUsersMenuOptions::eDeleteUsers:
         ///   CheckPermission(CurrentUser.Permissions,enPermissions::enDeleteUser);
            system("cls");
            _ShowDeleteUsersScreen();
            _GoToBackManageMenu();
            break;

        case enManageUsersMenuOptions::eUpdateUsers:
          ///  CheckPermission(CurrentUser.Permissions,enPermissions::enUpdateUser);
            system("cls");
            _ShowUpdateUserScreen();
            _GoToBackManageMenu();
            break;

        case enManageUsersMenuOptions::eFindUsers:
          ///  CheckPermission(CurrentUser.Permissions,enPermissions::enFindUser);
            system("cls");
            _ShowFindUserScreen();
            _GoToBackManageMenu();
            break;

        case enManageUsersMenuOptions::eMainMenu:
           {

           }
    }
}


public:

static void ShowManageMenuScreen()
{
 system("cls");

  if(!CheckAccessRights(clsUser::enPermissions::pManageUser))
     {
         return; /// this will exit the function and it will not
     }

 _DrawScreenHeader("Manage Users Screen");
 cout << "\t\t\t===============================================" << endl;
 cout << "\t\t\t\t\tManage Menu Screen" << endl;
 cout << "\t\t\t===============================================" << endl;
 cout << "\t\t\t\t[1] List Users." << endl;
 cout << "\t\t\t\t[2] Add New User." << endl;
 cout << "\t\t\t\t[3] Delete User." << endl;
 cout << "\t\t\t\t[4] Update User." << endl;
 cout << "\t\t\t\t[5] Find User." << endl;
 cout << "\t\t\t\t[6] Main Menu." << endl;
 cout << "\t\t\t===============================================" << endl;
 _PerformManageUsersMenu((enManageUsersMenuOptions)_ReadManageUsersMenuOption());

}



};
