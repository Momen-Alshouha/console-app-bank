#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include <iomanip>

class clsClientListScreen : public clsScreen
{

public:
	static void PrintClientRecordLine(clsClient Client);
	static void ShowClientsList();


};

