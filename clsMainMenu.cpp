#include "clsMainMenu.h"

void clsMainMenu::_ShowAllClientsScreen()
{
    clsClientListScreen::ShowClientsList();
}

void clsMainMenu::_ShowAddNewClientsScreen()
{
    clsAddClientScreen::AddClient();
}

void clsMainMenu::_ShowDeleteClientScreen()
{
    clsDeleteScreen::DeleteClient();
}

void clsMainMenu::_ShowDeleteAllClientsScreen()
{
    clsDeleteScreen::DeleteAllClients();
}

void clsMainMenu::_ShowUpdateClientScreen()
{
    clsUpdateClientScreen::UpdateClient();
}

void clsMainMenu::_ShowFindClientScreen()
{
    clsFindClientScreen::FindClientScreen();
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
    case clsMainMenu::eDeleteAllClients:
        _ShowDeleteAllClientsScreen();
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
    cout << "Enter Option [1-9] : ";
    return clsInputValidate::ReadIntNumberBetween(1, 9);
}

void clsMainMenu::_GoBackToMainMenu()
{
    cout << "\nPress any key to back to main menu...\n";
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
    cout << "\t[4] Delete All Clients.\n";
    cout  << "\t[5] Update Client Info.\n";
    cout << "\t[6] Find Client.\n";
    cout  << "\t[7] Transactions.\n";
    cout << "\t[8] Manage Users.\n";
    cout <<"\t[9] Logout.\n";
    cout << "====================================\n";

    _PerfromMainMenuOption((enMainMenuOption)_ReadMainMenueOption());
}

static  void _GoBackToMainMenue()
{
    cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

    system("pause>0");
    clsMainMenu::ShowMainMenu();
}