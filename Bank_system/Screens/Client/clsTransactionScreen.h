#pragma once

#include <iostream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/clsScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsDepositScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsWithdrawScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsTotalBalancesScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsTransferScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/Client/clsTransferLogScreen.h"


class clsTrasactionScreen : protected clsScreen
{
private:

enum enTransactionsMenu{

    eShowDepositScreen = 1, eShowWithdrawScreen = 2, eShowTotalBalance = 3, eShowTransferScreen = 4, eShowTransferLogScreen = 5,
    eShowMainMenu = 6
};

static short _ReadTransactionsOption(){

    cout <<  setw(27)  << left << "\t\t\tChose what do you want to do? [1 to 6]? ";
    short Choice;
    Choice = clsInputValidate::ReadNumberBetween(1,6,"Enter number between 1,5: ");
    return Choice;
}

static void _GoBackToTransactionsMenu(){

    cout << "\n\t\t\tPress any key to go to Transaction Menu...";
    system("pause>0");
    ShowTransactionMenu();
}

static void _ShowDepositScreen(){

///cout << "Deposit Screen will be here\n";
        clsDepositScreen::ShowDepositScreen();

}

static void _ShowWithdrawScreen(){

///cout << "Withdraw Screen will be here\n";
    clsWithdrawScreen::ShowWithdrawScreen();

}

static void _ShowTotalBalancesScreen(){

///cout << "Total Balances Screen will be here\n";
    clsTotalBalancesScreen::ShowTotalBalancesScreen();

}

static void _ShowTransferScreen(){

///cout << "Transfer Screen will be here\n";
      clsTransferScreen::ShowTransferScreen();

}

static void _ShowTransferLogScreen(){

   /// cout << "Transfer Log Screen will be here\n";
   clsTransferLogScreen::ShowTransferLogRegisterListScreen();

}

static void _PerformTransactionsMenu(enTransactionsMenu TransactionsMenuOption){

    switch(TransactionsMenuOption)
    {
        case enTransactionsMenu::eShowDepositScreen:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case enTransactionsMenu::eShowWithdrawScreen:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenu::eShowTotalBalance:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenu::eShowTransferScreen:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenu::eShowTransferLogScreen:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenu::eShowMainMenu:
            {
             /// do nothing here the main screen will handle it :-)

            }

    }
}


public:

static void ShowTransactionMenu()
{

     if(!CheckAccessRights(clsUser::enPermissions::pTransactions))
     {
         return; /// this will exit the function and it will not
     }

     system("cls");
    _DrawScreenHeader("Transaction Screen");
    cout <<  setw(27)  << left << "\t\t\t=================================\n";
    cout <<  setw(27)  << left << "\t\t\t\tTransactions Menu Screen\n";
    cout <<  setw(27)  << left << "\t\t\t=================================\n";
    cout <<  setw(27)  << left << "\t\t\t\t[1] Deposit.\n";
    cout <<  setw(27)  << left << "\t\t\t[2] Withdraw.\n";
    cout <<  setw(27)  << left << "\t\t\t[3] Total Balances.\n";
    cout <<  setw(27)  << left << "\t\t\t\t[4] Transfer.\n";
    cout <<  setw(27)  << left << "\t\t\t[5] Transfer Log.\n";
    cout <<  setw(27)  << left << "\t\t\t\t[6] Main Menu.\n";
    cout <<  setw(27)  << left << "\t\t=================================\n";
    _PerformTransactionsMenu((enTransactionsMenu)_ReadTransactionsOption());


}


};
