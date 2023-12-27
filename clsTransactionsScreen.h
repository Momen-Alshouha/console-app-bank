#pragma once
#include "clsScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsMainMenu.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"

class clsTransactionsScreen : public clsScreen
{
	enum enTransactionMenuOption
	{
		enDeposite = 1, enWithdraw, enTotalBalances, enMainMenu
	};

	static short _ReadTransactionMenuOption();

	static void _PerformTransactionMenuOption(enTransactionMenuOption Option);

	static void _GoBackToTransactionMenu();

	static void _ShowDepositeScreen();

	static void _ShowWithdrawScreen();

public:
	static void ShowTransactionScreen();


};

