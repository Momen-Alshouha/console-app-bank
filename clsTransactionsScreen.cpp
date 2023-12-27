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
        _ShowDepositeScreen();
        _GoBackToTransactionMenu();
        break;
    case clsTransactionsScreen::enWithdraw:
        _ShowWithdrawScreen();
        _GoBackToTransactionMenu();
        break;
    case clsTransactionsScreen::enTotalBalances:
        _ShowTotalBalancesScreen();
        _GoBackToTransactionMenu();
        break;
    case clsTransactionsScreen::enMainMenu:
        clsMainMenu::ShowMainMenu();
        break;
    default:
        break;
    }
}

void clsTransactionsScreen::_GoBackToTransactionMenu()
{
    cout << "\nPress any key to back to transactions menu ...\n";
    system("pause>0");
    ShowTransactionScreen();
}

void clsTransactionsScreen::_ShowDepositeScreen()
{
    clsDepositeScreen::ShowDepositeScreen();
}

void clsTransactionsScreen::_ShowWithdrawScreen()
{
    clsWithdrawScreen::ShowWithdrawScreen();
}

void clsTransactionsScreen::_ShowTotalBalancesScreen()
{
    clsTotalBalancesScreen::ShowTotalBalances();
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