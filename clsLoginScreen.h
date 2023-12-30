#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainMenu.h"

class clsLoginScreen : public clsScreen
{
	static void _Login();

	static string _GenerateLoginLogLine(clsUser &User);

	static void _AddUserLoginToLogFile(clsUser &User);

public:
	static void ShowLoginScreen();

};

