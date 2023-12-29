#pragma once
#include "clsScreen.h"
#include "clsMainMenu.h"
#include "clsListUsersScreen.h"

class clsManageUsers : public clsScreen
{
	enum enManageUsersMenuOption
	{
		eListUsers = 1, eAddUser, eDeleteUser, eUpdateUser, eFindUser, eMainMenu
	};

	static void _PerformManageUsersMenuOption(enManageUsersMenuOption Option);

	static void _ListUsers();
	static void _AddUser();
	static void _UpdateUser();
	static void _DeleteUser();
	static void _FindUser();
	static void _GoBackToManageUsersMenu();
	static void _MainMenu();

public:
	static void ShowManageUsersScreen();

};

