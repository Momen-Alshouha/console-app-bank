#pragma once
#include "clsScreen.h"
#include "clsMainMenu.h"

class clsTransactionsScreen : public clsScreen
{
	enum enTransactionMenuOption
	{
		enDeposite = 1, enWithdraw, enTotalBalances, enMainMenu
	};

	static short _ReadTransactionMenuOption();

	static void _PerformTransactionMenuOption(enTransactionMenuOption Option);

	static void _GoBackToTransactionMenu();

public:
	static void ShowTransactionScreen();


};

