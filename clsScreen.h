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
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsScreen
{

	static void PrintSystemDate(clsDate Date);

protected:

	static void ReadClientInfo(clsClient& Client);

	static void ReadUserInfo(clsUser& User);

	static int _ReadPermissionsToSet();
	
public:

	static void _DrawScreenHeader(string Title, string SubTitle = "");	
	
	static void PrintClient(clsClient& client);

	static void PrintShortlistedClient(clsClient& client);

	static void PrintUserCard(clsUser& User);

	static void PrintUserRecord(clsUser& User);


};

