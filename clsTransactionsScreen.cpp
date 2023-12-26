#include "clsTransactionsScreen.h"

short clsTransactionsScreen::_ReadTransactionMenuOption()
{
   cout << "Enter Option (1-4) : ";
   return clsInputValidate::ReadIntNumberBetween(1, 4);
}

void clsTransactionsScreen::_PerformTransactionMenuOption(enTransactionMenuOption Option)
{
    system("cls");
    switch (Option)
    {
    case clsTransactionsScreen::enDeposite:
        cout << "Deposite\n";
        _GoBackToMainMenu();
        break;
    case clsTransactionsScreen::enWithdraw:
        cout << "Withdraw\n";
        _GoBackToMainMenu();
        break;
    case clsTransactionsScreen::enTotalBalances:
        cout << "Total Balances\n";
        _GoBackToMainMenu();
        break;
    case clsTransactionsScreen::enMainMenu:
        clsMainMenu::ShowMainMenu();
        break;
    default:
        break;
    }
}

void clsTransactionsScreen::_GoBackToMainMenu()
{
    cout << "\nPress any key to back to main menu...\n";
    system("pause>0");
    clsMainMenu::ShowMainMenu();
}

void clsTransactionsScreen::ShowTransactionScreen()
{
    system("cls");
   _DrawScreenHeader("Transactions Screen");
    cout << "\t[1] Deposite.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Show Total Balances.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "====================================\n";

    _PerformTransactionMenuOption((enTransactionMenuOption)_ReadTransactionMenuOption());
}
