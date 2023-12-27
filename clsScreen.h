#pragma once
#include <string>
#include <iostream>
#include "clsDate.h"
#include <vector>
#include  <iomanip>
#include "clsUtil.h"
#include "clsClient.h"
#include "clsInputValidation.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{

	static void PrintSystemDate(clsDate Date);

protected:

	static void ReadClientInfo(clsClient& Client);

public:

	static void _DrawScreenHeader(string Title, string SubTitle = "");	
	
	static void PrintClient(clsClient& client);

};

