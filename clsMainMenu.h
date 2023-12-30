#pragma once
#include "clsInputValidation.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include "clsLoginScreen.h"
#include "clsLoginLogs.h"

class clsMainMenu : protected clsScreen
{
	enum enMainMenuOption
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,eDeleteAllClients=4,
		eUpdateClient = 5, eFindClient = 6, eShowTransactionsMenue = 7,
		eManageUsers = 8, eLoginLogs=9,eLogout = 10
	};

	static void _ShowAllClientsScreen();

	static void _ShowAddNewClientsScreen();

	static void _ShowDeleteClientScreen();

	static void _ShowDeleteAllClientsScreen();

	static void _ShowUpdateClientScreen();

	static void _ShowFindClientScreen();

	static void _ShowTransactionsMenu();

	static void _ShowManageUsersMenu();

	static void _ShowLoginLogs();

	static void _PerfromMainMenuOption(enMainMenuOption Option);

	static int _ReadMainMenueOption();

	static void _GoBackToMainMenu();

	static void _Logout();

	static bool CheckPermission(clsUser::enPermissions Permission);

public:
	
	static void ShowMainMenu();

};

