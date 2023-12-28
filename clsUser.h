#pragma once
#include "clsPerson.h"
class clsUser : public clsPerson
{
	const static string UsersFileName;
	
	enum enMode
	{
		enEmptyMode, enUpdateMode, enAddMode
	};

	enum enPermissions
	{
		enpListClients = 1, enpAddClients = 2, enpDeleteClient = 4, enpDeleteAllClients = 4, enpUpdateClient = 8, enpFindClient = 16,
		enpTransactions = 32, enpManageUsers = 64
	};

	string _Username, _Password;
	
	enPermissions _Permissions;

public:

	string GetUserName();
	void SetUserName(string Username);

	string GetPassword();
	void SetPassword(string Password);

	enPermissions GetPermission();
	void SetPermission(int Permission);

	// proprities
	__declspec(property(get = GetPassword, put = SetPassword)) string password;
	__declspec(property(get = GetUserName, put = SetUserName)) string username;
	__declspec(property(get = GetPermission, put = SetPermission)) string permissions;

};

