#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainMenu.h"

class clsLoginScreen : public clsScreen
{
	static void _Login();

public:
	static void ShowLoginScreen();

};

