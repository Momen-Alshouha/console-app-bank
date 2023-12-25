#pragma once
#include "clsInputValidation.h"
#include "clsScreen.h"

class clsMainMenu : protected clsScreen
{
	enum enMainMenuOption
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8
	};

	static void _ShowAllClientsScreen();

	static void _ShowAddNewClientsScreen();

	static void _ShowDeleteClientScreen();

	static void _ShowUpdateClientScreen();

	static void _ShowFindClientScreen();

	static void _ShowTransactionsMenue();

	static void _ShowManageUsersMenue();

	static void _ShowEndScreen();

	static void _PerfromMainMenuOption(enMainMenuOption Option);

	static int _ReadMainMenueOption();

	static void _GoBackToMainMenu();

public:
	
	static void ShowMainMenu();

};

