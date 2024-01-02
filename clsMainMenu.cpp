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

 void clsMainMenu::_ShowTransactionsMenu()
{
     clsTransactionsScreen::ShowTransactionScreen();
}

void clsMainMenu::_ShowManageUsersMenu()
{
    //cout << "\nUsers Menue Will be here...\n";
    clsManageUsers::ShowManageUsersScreen();

}

void clsMainMenu::_ShowLoginLogs()
{
    clsLoginLogs::ShowLoginLogs();
}

void clsMainMenu::_ShowCurrencyExchangeMainMenuScreen()
{
    clsCurrencyMainScreen::ShowCurrencyMainMenu();
}


void clsMainMenu::_PerfromMainMenuOption(enMainMenuOption Option)
{
    system("cls");
    switch (Option)
    {
    case clsMainMenu::eListClients:    
        if (CheckPermission(clsUser::pListClients))
        {
           _ShowAllClientsScreen();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eAddNewClient:
        if (CheckPermission(clsUser::pAddNewClient))
        {
            _ShowAddNewClientsScreen();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eDeleteClient:
        if (CheckPermission(clsUser::pDeleteClient))
        {
            _ShowDeleteClientScreen();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eDeleteAllClients:
        
        if (CheckPermission(clsUser::pDeleteClient))
        {
            _ShowDeleteAllClientsScreen();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eUpdateClient:
        
        if (CheckPermission(clsUser::pUpdateClients))
        {
            _ShowUpdateClientScreen();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eFindClient:
        if (CheckPermission(clsUser::pFindClient))
        {
            _ShowFindClientScreen();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eShowTransactionsMenue:
        if (CheckPermission(clsUser::pTranactions))
        {
            _ShowTransactionsMenu();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eManageUsers:
        if (CheckPermission(clsUser::pManageUsers))
        {
           _ShowManageUsersMenu();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eLoginLogs:
        if (CheckPermission(clsUser::pLoginLogs))
        {
            _ShowLoginLogs();
        }
        _GoBackToMainMenu();
        break;

    case clsMainMenu::eCurrencyExchange:
        
        if (CheckPermission(clsUser::pCurrencyExchange))
        {
            clsCurrencyMainScreen::ShowCurrencyMainMenu();
        }

        _GoBackToMainMenu();
        break;


    case clsMainMenu::eLogout:
        _Logout();
        clsLoginScreen::ShowLoginScreen();
        break;
    default:
        break;
    }
}

int clsMainMenu::_ReadMainMenuOption()
{
    cout << "Enter Option [1-11] : ";
    return clsInputValidate::ReadIntNumberBetween(1, 11);
}

void clsMainMenu::_GoBackToMainMenu()
{
    cout << "\nPress any key to back to main menu...\n";
    system("pause>0");
    ShowMainMenu();
}

void clsMainMenu::_Logout()
{
    UserSession::getCurrentUser() = clsUser::Find("", "");
}

bool clsMainMenu::CheckPermission(clsUser::enPermissions Permission)
{
    if (Permission==clsUser::eAll)
    {
        return true;
    }
    else if ((Permission & UserSession::getCurrentUser().Permissions) == Permission)
    {
        return true;
    }
    _DrawScreenHeader("ACCESS DENIED!");
    cout << "\n - Please Contact Your Admin!\n";
    return false;
}

void clsMainMenu::ShowMainMenu()
{
    system("cls");
    _DrawScreenHeader("Main Screen");
    cout  << "\t[1]  Show Client List.\n";
    cout  << "\t[2]  Add New Client.\n";
    cout  << "\t[3]  Delete Client.\n";
    cout << "\t[4]  Delete All Clients.\n";
    cout  << "\t[5]  Update Client Info.\n";
    cout << "\t[6]  Find Client.\n";
    cout  << "\t[7]  Transactions.\n";
    cout << "\t[8]  Manage Users.\n";
    cout << "\t[9]  Login Logs.\n";
    cout <<"\t[10] Currency Exchange.\n";
    cout << "\t[11] Logout.\n";
    cout << "=================================================\n";

    _PerfromMainMenuOption((enMainMenuOption)_ReadMainMenuOption());
}

static  void _GoBackToMainMenue()
{
    cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

    system("pause>0");
    clsMainMenu::ShowMainMenu();
}