#include "clsMainMenu.h"
#include <iostream>
#include <iomanip>
using namespace std;

void clsMainMenu::_ShowAllClientsScreen()
{
    clsClientListScreen::ShowClientsList();
}

void clsMainMenu::_ShowAddNewClientsScreen()
{
    cout << "\nAdd New Client Screen Will be here...\n";

}

void clsMainMenu::_ShowDeleteClientScreen()
{
    cout << "\nDelete Client Screen Will be here...\n";

}

void clsMainMenu::_ShowUpdateClientScreen()
{
    cout << "\nUpdate Client Screen Will be here...\n";

}

void clsMainMenu::_ShowFindClientScreen()
{
    cout << "\nFind Client Screen Will be here...\n";

}

 void clsMainMenu::_ShowTransactionsMenue()
{
    cout << "\nTransactions Menue Will be here...\n";

}

void clsMainMenu::_ShowManageUsersMenue()
{
    cout << "\nUsers Menue Will be here...\n";

}

void clsMainMenu::_ShowEndScreen()
{
    cout << "\nThank You\n";
}


void clsMainMenu::_PerfromMainMenuOption(enMainMenuOption Option)
{
    system("cls");
    switch (Option)
    {
    case clsMainMenu::eListClients:
        _ShowAllClientsScreen();
        _GoBackToMainMenu();
        break;
    case clsMainMenu::eAddNewClient:
        _ShowAddNewClientsScreen();
        _GoBackToMainMenu();
        break;
    case clsMainMenu::eDeleteClient:
        _ShowDeleteClientScreen();
        _GoBackToMainMenu();
        break;
    case clsMainMenu::eUpdateClient:
        _ShowUpdateClientScreen();
        _GoBackToMainMenu();
        break;
    case clsMainMenu::eFindClient:
        _ShowFindClientScreen();
        _GoBackToMainMenu();
        break;
    case clsMainMenu::eShowTransactionsMenue:
        _ShowTransactionsMenue();
        _GoBackToMainMenu();
        break;
    case clsMainMenu::eManageUsers:
        _ShowManageUsersMenue();
        _GoBackToMainMenu();
        break;
    case clsMainMenu::eExit:
        _ShowEndScreen();
        break;
    default:
        break;
    }
}

int clsMainMenu::_ReadMainMenueOption()
{
    cout << "Enter Option [1-8] : ";
    return clsInputValidate::ReadIntNumberBetween(1, 8);
}

void clsMainMenu::_GoBackToMainMenu()
{
    cout << "\npress any key to back to main menu\n";
    system("pause>0");
    ShowMainMenu();
}

void clsMainMenu::ShowMainMenu()
{
    system("cls");
    _DrawScreenHeader("Main Screen");
    cout  << "\t[1] Show Client List.\n";
    cout  << "\t[2] Add New Client.\n";
    cout  << "\t[3] Delete Client.\n";
    cout  << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout  << "\t[6] Transactions.\n";
    cout << "\t[7] Manage Users.\n";
    cout <<"\t[8] Logout.\n";
    cout << "====================================\n";

    _PerfromMainMenuOption((enMainMenuOption)_ReadMainMenueOption());
}

static  void _GoBackToMainMenue()
{
    cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

    system("pause>0");
    clsMainMenu::ShowMainMenu();
}