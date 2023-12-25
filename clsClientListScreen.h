#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include <iomanip>

class clsClientListScreen : public clsScreen
{
	static void _PrintClientRecordLine(clsClient Client);
public:
	
	static void ShowClientsList();


};

