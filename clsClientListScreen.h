#pragma once
#include "clsScreen.h"


class clsClientListScreen : public clsScreen
{
	static void _PrintClientRecordLine(clsClient Client);
public:
	
	static void ShowClientsList();


};

