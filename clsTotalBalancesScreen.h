#pragma once
#include "clsScreen.h"
#include "clsTransactionsScreen.h"

class clsTotalBalancesScreen : public clsScreen
{

	static void PrintClientRecordBalanceLine(clsClient Client);

public:

	static void ShowTotalBalances();

};

